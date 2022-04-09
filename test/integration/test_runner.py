from typing import List, Tuple, Optional

from enum import Enum
import subprocess
import re
import time
from colorama import Fore
from test_base import TestData
from tests import TestSet
import os.path


class TestResult(Enum):
    PASSED = 1
    FAILED = 2
    IGNORED = 3


TestColors = {
    TestResult.PASSED: Fore.GREEN,
    TestResult.FAILED: Fore.RED,
    TestResult.IGNORED: Fore.BLUE,
}


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
        self.rotctl2_cmd = [self.rotctl_file_path,
                            "--rot-file={}".format(self.pipe_endpoint_a),
                            "--set-conf=timeout=900,post_write_delay=100,write_delay=0"]
        self.test_program_cmd = ["{}/.pio/build/native/program".format(project_dir), self.pipe_endpoint_b]
        self.virtual_dev = None
        self.test_program = None
        self.rotctl = None
        self.timestamp_start = None
        self.timestamp_end = None
        self.runs_on_github_ci = runs_on_github_ci
        self.rotctl_version = self._get_rotctl_version()

    @property
    def rotctl_file_path(self) -> Optional[str]:
        candidates = ["/usr/local/bin/rotctl", "/usr/bin/rotctl"]
        for f in candidates:
            if os.path.exists(f):
                return f
        return None

    def run(self, test_data: TestData) -> Tuple[TestResult, float]:
        self.timestamp_start = time.time()
        print("test: -------------------- [test {}start{} - \"{}\"] --------------------"
              .format(Fore.GREEN, Fore.RESET, test_data.description))
        if re.fullmatch(test_data.allowed_rotctl_versions, self.rotctl_version) is None:
            print("test: found rotctl version \"{}\" version but applicable is \"{}\""
                  .format(self.rotctl_version, test_data.allowed_rotctl_versions))
            print("test: ignore test: rotctl version not accepted")
            test_result = TestResult.IGNORED
        else:
            print("test: found applicable rotctl version \"{}\" version, applicable is \"{}\""
                  .format(self.rotctl_version, test_data.allowed_rotctl_versions))
            self._set_up()

            self.rotctl2_cmd.extend(test_data.rotctl_extra_program_cli_args)
            # self.rotctl2_cmd.append("-")
            print("test: send \"{}\" to \"{}\"".format(test_data.rotctl_commands, " ".join(self.rotctl2_cmd)))
            self.rotctl = subprocess.Popen(self.rotctl2_cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                           stderr=subprocess.PIPE, text=True)

            test_program_transaction, rotctl_transaction = self._test_transaction(
                "{}".format(test_data.rotctl_commands))
            test_result = TestResult.PASSED if Test.verify_process_output(
                "test program",
                test_data.expected_test_program_stdout_lines,
                test_data.allowed_test_program_return_codes,
                *test_program_transaction) and Test.verify_process_output(
                "rotctl",
                test_data.expected_rotctl_stdout_lines,
                test_data.allowed_rotctl_return_codes,
                *rotctl_transaction) else TestResult.FAILED

            self._tear_down()

        duration = time.time() - self.timestamp_start
        print("test: -------------------- [test {}{}{} - \"{}\"] ---------------------"
              .format(TestColors[test_result], test_result.name, Fore.RESET, test_data.description))
        return test_result, duration

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
            rotctl_stdout, rotctl_stderr = self.rotctl.communicate(rotctl_commands, timeout=3)
            rotctl_ret_code = self.rotctl.returncode
        except subprocess.TimeoutExpired:  # OK if process already finished
            self.rotctl.kill()
            rotctl_stdout, rotctl_stderr = self.rotctl.communicate()
            rotctl_ret_code = self.rotctl.returncode

        try:
            test_program_stdout, test_program_stderr = self.test_program.communicate(timeout=3)
            test_program_ret_code = self.test_program.returncode
        except subprocess.TimeoutExpired:  # OK if process already finished
            self.test_program.kill()
            test_program_stdout, test_program_stderr = self.test_program.communicate()
            test_program_ret_code = self.test_program.returncode

        return (self._lines_from_stream(test_program_stdout),
                self._lines_from_stream(test_program_stderr),
                test_program_ret_code), \
               (self._lines_from_stream(rotctl_stdout),
                self._lines_from_stream(rotctl_stderr),
                rotctl_ret_code)

    @staticmethod
    def _lines_from_stream(lines_as_byte_array):
        if lines_as_byte_array is None:
            return []
        else:
            return str(lines_as_byte_array.strip()).split('\n') if len(lines_as_byte_array) > 0 else []

    def _get_rotctl_version(self) -> str:
        rotctl = subprocess.Popen([self.rotctl_file_path, "--version"],
                                  stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        try:
            stdout, stderr = rotctl.communicate(timeout=3)
        except subprocess.TimeoutExpired:
            rotctl.kill()
            stdout, stderr = rotctl.communicate()

        stderr_lines = self._lines_from_stream(stderr)
        if len(stderr_lines) > 0:
            print("test: failed to get rotctl version")
            for line in stderr_lines:
                print("test:   \"{}\"".format(line))

        stdout_lines = self._lines_from_stream(stdout)
        if len(stdout_lines) > 0:
            for line in stdout_lines:
                print("test:   \"{}\"".format(line))
            return stdout_lines[0]
        return ""


class TestRunner:

    def __init__(self, project_dir, runs_on_github_ci: bool = False):
        self.project_dir = project_dir
        self.tests = TestSet.test_set()
        self.runs_on_github_ci = runs_on_github_ci

    def run(self):
        results = [(test_data.description, Test(self.project_dir, self.runs_on_github_ci).run(test_data))
                   for test_data in self.tests]

        print("test: test summary:")
        passed, failed, ignored = 0, 0, 0
        total_duration = 0
        for description, (test_result, duration) in results:
            total_duration += duration
            if test_result is TestResult.PASSED:
                print("test: {}PASSED{}  in {:.2f}s ... \"{}\" "
                      .format(TestColors[TestResult.PASSED], Fore.RESET, duration, description))
                passed += 1
            elif test_result is TestResult.FAILED:
                print("test: {}FAILED{}  in {:.2f}s ... \"{}\""
                      .format(TestColors[TestResult.FAILED], Fore.RESET, duration, description))
                failed += 1
            else:
                print("test: {}IGNORED{} in {:.2f}s ... \"{}\""
                      .format(TestColors[TestResult.IGNORED], Fore.RESET, duration, description))
                ignored += 1

        color = TestColors[TestResult.FAILED]
        if failed <= 0:
            color = TestColors[TestResult.IGNORED]
        if ignored <= 0:
            color = TestColors[TestResult.PASSED]
        print("{}test: {} failed, {} passed, {} ignored in {:.2f}s (total {} tests){}"
              .format(color, failed, passed, ignored, total_duration, passed + failed + ignored, Fore.RESET))

        if failed > 0 or passed <= 0:
            return 1
        else:
            return 0
