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

    def __init__(self, project_dir: str, runs_on_github_ci: bool = False):
        self.pipe_endpoint_a = "{}/easycomm-endpoint-rotctl".format(project_dir)
        self.pipe_endpoint_b = "{}/easycomm-endpoint-test-program".format(project_dir)
        self.virtual_device_cmd = ["/usr/bin/socat", "-d", "-d",
                                   "pty,raw,echo=0,link={}".format(self.pipe_endpoint_a),
                                   "pty,raw,echo=0,link={}".format(self.pipe_endpoint_b)]
        self.rotctl2_cmd = ["/usr/bin/rotctl",
                            "--rot-file={}".format(self.pipe_endpoint_a),
                            "--set-conf=timeout=900,post_write_delay=100,write_delay=0"]
        self.test_program_cmd = ["{}/.pio/build/native/program".format(project_dir), self.pipe_endpoint_b]
        self.virtual_dev = None
        self.test_program = None
        self.rotctl = None
        self.timestamp_start = None
        self.timestamp_end = None
        self.runs_on_github_ci = runs_on_github_ci

    def run(self, description: str, rotctl_commands: str, rotctl_extra_program_cli_args: List[str],
            expected_test_program_lines: List[str], allowed_test_program_ret_codes: List[int],
            expected_rotctl_lines: List[str], allowed_rotctl_ret_codes: List[int]) -> Tuple[bool, float]:
        self.timestamp_start = time.time()
        print("test: -------------------- test start --------------------")
        print("test: run test \"{}\" ({})".format(description, rotctl_commands.join(" ")))
        self._set_up()

        self.rotctl2_cmd.extend(rotctl_extra_program_cli_args)
        self.rotctl2_cmd.append("-")
        print("test: send command(s) \"{}\" to \"{}\"".format(rotctl_commands, " ".join(self.rotctl2_cmd)))
        print("test: rotctl : \"{}\"".format(" ".join(self.rotctl2_cmd)))
        self.rotctl = subprocess.Popen(self.rotctl2_cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE, text=True)

        test_program_transaction, rotctl_transaction = self._test_transaction("{}\n".format(rotctl_commands))
        result = Test.verify_process_output(
            "test program", expected_test_program_lines, allowed_test_program_ret_codes, *test_program_transaction) \
                 and Test.verify_process_output(
            "rotctl", expected_rotctl_lines, allowed_rotctl_ret_codes, *rotctl_transaction)

        self._tear_down()
        timespan = time.time() - self.timestamp_start
        print("test: ---------------------- test {} ---------------------".format("SUCCEEDED" if result else "FAILED"))
        return result, timespan

    def _set_up(self) -> None:
        print("test: setup ...")
        print("test: prepare virtual device: \"{}\"".format(" ".join(self.virtual_device_cmd)))
        self.virtual_dev = subprocess.Popen(self.virtual_device_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                            text=True)
        if self.runs_on_github_ci:
            time.sleep(2)  # time to breathe required for GitHub CI
        print("test: start test program: \"{}\"".format(" ".join(self.test_program_cmd)))
        self.test_program = subprocess.Popen(self.test_program_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                             text=True)

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
            print("test: verify {} failed: allowed return codes {} but found {}"
                  .format(process_name, allowed_ret_codes, actual_ret_code))

        if len(stderr_lines) > 0:
            has_passed = False
            print("test: verify {} failed: found {} stderr lines but 0 expected"
                  .format(process_name, len(stderr_lines)))
            for line in stderr_lines:
                print("test:   \"{}\"".format(line))

        len_expected, len_actual = len(expected_lines), len(stdout_lines)
        if len_expected != len_actual:
            has_passed = False
            print("test: verify {} failed: expected {} stdout lines but found {}"
                  .format(process_name, len_expected, len_actual))
        else:
            for expected_line, actual_line in zip(expected_lines, stdout_lines):
                if re.fullmatch(expected_line, actual_line) is None:
                    has_passed = False
                    print("test: verify {} failed: expected line does not match: expected=\"{}\" vs. actual=\"{}\""
                          .format(process_name, expected_line, actual_line))

        if not has_passed:
            print("test: expected {} stdout lines:".format(process_name))
            for line in expected_lines:
                print("test:   \"{}\"".format(line))
            print("test: actual {} stdout lines:".format(process_name))
            for line in stdout_lines:
                print("test:   \"{}\"".format(line))

        if has_passed:
            print("test: verify {} output: OK".format(process_name))

        return has_passed

    def _test_transaction(self, rotctl_commands: str) \
            -> Tuple[Tuple[List[str], List[str], int], Tuple[List[str], List[str], int]]:
        print("test: transaction ...")
        test_program_stdout, test_program_stderr, test_program_ret_code = None, None, None
        rotctl_stdout, rotctl_stderr, rotctl_ret_code = None, None, None

        try:
            rotctl_stdout, rotctl_stderr = self.rotctl.communicate(rotctl_commands, timeout=1)
            rotctl_ret_code = self.rotctl.returncode
        except subprocess.TimeoutExpired:
            print("test: failed to wait for {}".format(self.rotctl2_cmd))
            self.rotctl.kill()
            rotctl_stdout, rotctl_stderr = self.rotctl.communicate()
            rotctl_ret_code = self.rotctl.returncode

        try:
            test_program_stdout, test_program_stderr = self.test_program.communicate(timeout=1)
            test_program_ret_code = self.test_program.returncode
        except subprocess.TimeoutExpired:
            print("test: failed to wait for {}".format(self.test_program_cmd))
            self.test_program.kill()
            test_program_stdout, test_program_stderr = self.test_program.communicate()
            test_program_ret_code = self.test_program.returncode

        def lines_from_stream(lines_as_byte_array):
            if lines_as_byte_array is None:
                return []
            return str(lines_as_byte_array.strip()).split('\n') if len(lines_as_byte_array) > 0 else []

        return (lines_from_stream(test_program_stdout),
                lines_from_stream(test_program_stderr),
                test_program_ret_code), \
               (lines_from_stream(rotctl_stdout),
                lines_from_stream(rotctl_stderr),
                rotctl_ret_code)


class TestRunner:

    def __init__(self, project_dir, runs_on_github_ci: bool = False):
        self.project_dir = project_dir
        self.tests = IntegrationTests().test_set
        self.runs_on_github_ci = runs_on_github_ci

    def run(self):
        results = [
            (description, Test(self.project_dir, self.runs_on_github_ci)
             .run(description, command, rotctl_extra_args, expected_test_program_lines,
                  allowed_test_program_ret_codes, expected_rotctl_lines, allowed_rotctl_ret_codes))
            for
            description, command, rotctl_extra_args, expected_test_program_lines, allowed_test_program_ret_codes,
            expected_rotctl_lines, allowed_rotctl_ret_codes
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
