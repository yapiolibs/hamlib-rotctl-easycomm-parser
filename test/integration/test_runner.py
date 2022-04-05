from typing import List, Tuple

import subprocess
import time
import re
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

    def __init__(self, project_dir: str):
        self.pipe_endpoint_a = "{}/easycomm-endpoint-rotctl".format(project_dir)
        self.pipe_endpoint_b = "{}/easycomm-endpoint-test-program".format(project_dir)
        self.virtual_device_cmd = ["/usr/bin/socat", "-d", "-d",
                                   "pty,raw,echo=0,link={}".format(self.pipe_endpoint_a),
                                   "pty,raw,echo=0,link={}".format(self.pipe_endpoint_b)]
        self.rotctl_cmd = "{}/integration/start-rotctl.sh".format(project_dir)
        self.test_program_cmd = ["{}/.pio/build/native/program".format(project_dir), self.pipe_endpoint_b]
        self.virtual_dev = None
        self.test_program = None
        self.rotctl = None
        self.timestamp_start = None
        self.timestamp_end = None

    def run(self, description: str, rotctl_commands: str,
            expected_test_program_lines: List[str], allowed_test_program_ret_codes: List[int],
            expected_rotctl_lines: List[str], allowed_rotctl_ret_codes: List[int]) -> Tuple[bool, float]:
        self.timestamp_start = time.time()
        print("test: run test \"{}\" ({})".format(description, rotctl_commands.join(" ")))
        self._set_up()
        print("test: send command(s) \"{}\" ({})".format(rotctl_commands, self.rotctl_cmd))
        self.rotctl = subprocess.Popen([self.rotctl_cmd, rotctl_commands], stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE)

        test_program_transaction, rotctl_transaction = self._test_transaction()
        result = Test.verify_process_output("test program", expected_test_program_lines,
                                            allowed_test_program_ret_codes,
                                            *test_program_transaction) and \
                 Test.verify_process_output("rotctl", expected_rotctl_lines,
                                            allowed_rotctl_ret_codes,
                                            *rotctl_transaction)

        self._tear_down()
        timespan = time.time() - self.timestamp_start
        return result, timespan

    def _set_up(self) -> None:
        print("test: setup ...")
        print("test: prepare virtual device: \"{}\"".format(" ".join(self.virtual_device_cmd)))
        self.virtual_dev = subprocess.Popen(self.virtual_device_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        time.sleep(2)  # time to breathe required for GitHub CI
        print("test: start test program: \"{}\"".format(" ".join(self.test_program_cmd)))
        self.test_program = subprocess.Popen(self.test_program_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    def _tear_down(self) -> None:
        print("test: tear down")
        for p in [self.rotctl, self.test_program, self.virtual_dev]:
            p.terminate()

    @staticmethod
    def verify_process_output(process_name: str, expected_lines: List[str], allowed_ret_codes: List[int],
                              stdout_lines: List[str], stderr_lines: List[str], actual_ret_code) -> bool:
        print("test: verify {} output ...".format(process_name))
        has_passed = True

        if actual_ret_code not in allowed_ret_codes:
            has_passed = False
            print("test: failed: allowed return codes {} but found {}".format(allowed_ret_codes, actual_ret_code))

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
                if re.fullmatch(expected_line, actual_line) is None:
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

    def _test_transaction(self) -> Tuple[Tuple[List[str], List[str], int], Tuple[List[str], List[str], int]]:
        print("test: transaction ...")
        test_program_stdout, test_program_stderr, test_program_ret_code = None, None, None
        rotctl_stdout, rotctl_stderr, rotctl_ret_code = None, None, None

        try:
            self.test_program.wait(timeout=1)
            test_program_stdout, test_program_stderr = self.test_program.communicate(timeout=1)
            test_program_ret_code = self.test_program.returncode
        except subprocess.TimeoutExpired:
            print("test: failed to wait for {}".format(self.test_program_cmd))
            self.test_program.kill()

        try:
            self.rotctl.wait(timeout=1)
            rotctl_stdout, rotctl_stderr = self.rotctl.communicate(timeout=1)
            rotctl_ret_code = self.rotctl.returncode
        except subprocess.TimeoutExpired:
            print("test: failed to wait for {}".format(self.test_program_cmd))
            self.rotctl.kill()

        def lines_from_bytes(lines_as_byte_array):
            if lines_as_byte_array is None:
                return []
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
             .run(description, command, expected_test_program_lines, allowed_test_program_ret_codes,
                  expected_rotctl_lines, allowed_rotctl_ret_codes))
            for
            description, command, expected_test_program_lines, allowed_test_program_ret_codes, expected_rotctl_lines,
            allowed_rotctl_ret_codes
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
