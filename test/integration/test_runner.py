from typing import List, Tuple

import subprocess
import time
from tests import IntegrationTests


class Test:
    """
                        command(s)
        ┌─────────────┐-----------→┌─────────────┐-----------→┌──────────────┐
      ┌─│rotctl/hamlib│            │    pipe     │            │ test program │─┐
      │ └─────────────┘←-----------└─────────────┘←-----------└──────────────┘ │
      │      │    │ rotctl output                    response      │    │      │
      │      ↓    ↓                                                ↓    ↓      │
      │ ┌──────┐┌──────┐                                      ┌──────┐┌──────┐ │
      │ │stderr││stdout│──────┐                        ┌──────│stderr││stdout│ │
      │ └──────┘└──────┘      │                        │      └──────┘└──────┘ │
      │     ↓                 ↓                        ↓                 ↓     │
      │ must be empty      expected lines   expected lines:      must be empty │
      │                                     string repr.                       │
      ↓                                     of parsed commands                 ↓
      return code                                                    return code

      A test program receives data from rotctl and feeds the parser library under test.
      The library parses the payload to a struct.
      The interpreted struct string-representation is echoed to stdout.
      A dummy response is generated sent back and printed to stdout if a response is expected.
    """

    def __init__(self, project_dir):
        self.virtual_device_cmd = "{}/integration/activate-virtual-device.sh".format(project_dir)
        self.rotctl_cmd = "{}/integration/start-rotctl.sh".format(project_dir)
        self.test_program_cmd = "{}/integration/start-test-program.sh".format(project_dir)
        self.virtual_dev = None
        self.test_program = None
        self.rotctl = None
        self.timestamp_start = None
        self.timestamp_end = None

    def run(self, description, rotctl_command, expected_test_program_lines, expected_test_program_ret_code,
            expected_rotctl_lines,
            expected_rotctl_ret_code):  # type: (str, str, List[str], int, List[str], int) -> Tuple[bool, float]
        self.timestamp_start = time.time()
        print("test: run test \"{}\" ({})".format(description, rotctl_command))
        self._set_up()
        self.rotctl = subprocess.Popen([self.rotctl_cmd, rotctl_command], stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE)

        test_program_transaction, rotctl_transaction = self._test_transaction()
        result = Test.verify_process_output("test program", expected_test_program_lines,
                                            expected_test_program_ret_code,
                                            *test_program_transaction) and \
                 Test.verify_process_output("rotctl", expected_rotctl_lines,
                                            expected_rotctl_ret_code,
                                            *rotctl_transaction)

        self._tear_down()
        timespan = time.time() - self.timestamp_start
        return result, timespan

    def _set_up(self):
        print("test: setup ...")
        self.virtual_dev = subprocess.Popen(self.virtual_device_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        self.test_program = subprocess.Popen(self.test_program_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    def _tear_down(self):
        print("test: tear down")
        for p in [self.rotctl, self.test_program, self.virtual_dev]:
            p.terminate()

    @staticmethod
    def verify_process_output(process_name, expected_lines, expected_ret_code, stdout_lines, stderr_lines,
                              ret_code):  # type: (str, List[str], int, List[str], List[str], int) -> bool
        print("test: verify {} output ...".format(process_name))
        has_passed = True

        if expected_ret_code != ret_code:
            has_passed = False
            print("test: failed: expected return code {} but found {}".format(expected_ret_code, ret_code))

        if len(stderr_lines) > 0:
            has_passed = False
            print("test: failed: found {} stderr lines but 0 expected".format(len(stderr_lines)))
            for line in stderr_lines:
                print("test: \"{}\"".format(line))

        len_expected, len_actual = len(expected_lines), len(stdout_lines)
        if len_expected != len_actual:
            has_passed = False
            print("test: failed: expected {} of stdout lines but found {}".format(len_expected, len_actual))
        else:
            for expected_line, actual_line in zip(expected_lines, stdout_lines):
                if expected_line != actual_line:
                    has_passed = False
                    print("test: failed: expected line does not match: expected=\"{}\" vs. actual=\"{}\""
                          .format(expected_line, actual_line))

        if not has_passed:
            print("test: expected stdout lines:")
            for line in expected_lines:
                print("test: \"{}\"".format(line))
            print("test: actual stdout lines:")
            for line in stdout_lines:
                print("test: \"{}\"".format(line))

        return has_passed

    def _test_transaction(
            self):  # type: () -> Tuple[Tuple[List[str], List[str], int], Tuple[List[str], List[str], int]]
        print("test: transaction ...")
        test_program_stdout, test_program_stderr, test_program_ret_code = None, None, None
        rotctl_stdout, rotctl_stderr, rotctl_ret_code = None, None, None

        try:
            self.test_program.wait(timeout=1)
            test_program_stdout, test_program_stderr = self.test_program.communicate(timeout=1)
            test_program_ret_code = self.test_program.returncode
        except subprocess.TimeoutExpired:
            print("test: failed to wait for test program")
            self.test_program.kill()

        try:
            self.rotctl.wait(timeout=1)
            rotctl_stdout, rotctl_stderr = self.rotctl.communicate(timeout=1)
            rotctl_ret_code = self.rotctl.returncode
        except subprocess.TimeoutExpired:
            print("test: failed to wait for rotctl")
            self.rotctl.kill()

        def lines_from_bytes(lines_as_byte_array):
            return str(lines_as_byte_array.strip().decode("ascii")).split('\n') if len(lines_as_byte_array) > 0 else []

        return (lines_from_bytes(test_program_stdout), lines_from_bytes(test_program_stderr), test_program_ret_code), \
               (lines_from_bytes(rotctl_stdout), lines_from_bytes(rotctl_stderr), rotctl_ret_code)


class TestRunner:

    def __init__(self, project_dir):
        self.project_dir = project_dir
        self.tests = IntegrationTests().test_set

    def run(self):
        results = [
            (description, Test(self.project_dir)
             .run(description, command, expected_test_program_lines, expected_test_program_ret_code,
                  expected_rotctl_lines, expected_rotctl_ret_code))
            for
            description, command, expected_test_program_lines, expected_test_program_ret_code, expected_rotctl_lines,
            expected_rotctl_ret_code
            in self.tests]

        print("test: test summary:")
        all_passed = True
        total_duration = 0
        for description, (has_passed, timespan) in results:
            total_duration += timespan
            if has_passed:
                print("test: OK ....... \"{}\" {:.2f}s".format(description, timespan))
            else:
                print("test: FAILED ... \"{}\" {:.2f}s".format(description, timespan))
                all_passed = False

        if all_passed:
            print("test: all tests passed in {:.2f}s".format(total_duration))
            return 0
        else:
            print("test: some tests failed {:.2f}s".format(total_duration))
            return 1
