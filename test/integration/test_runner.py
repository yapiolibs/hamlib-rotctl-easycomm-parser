import subprocess
import time
from tests import IntegrationTests


class Test:

    def __init__(self, project_dir):
        self.virtual_device_cmd = "{}/integration/activate-virtual-device.sh".format(project_dir)
        self.rotctl_cmd = "{}/integration/start-rotctl.sh".format(project_dir)
        self.test_program_cmd = "{}/integration/start-test-program.sh".format(project_dir)
        self.virtual_dev = None
        self.test_program = None
        self.rotctl = None
        self.timestamp_start = None
        self.timestamp_end = None

    def run(self, description, rotctl_command, expected_result):  # type: (str, List[str]) -> Bool
        self.timestamp_start = time.time()
        print("test: run test \"{}\" ({})".format(description, rotctl_command))
        self._set_up()
        self.rotctl = subprocess.Popen([self.rotctl_cmd, rotctl_command], stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE)
        result = self._verify(expected_result, *self._test_transaction())
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

    def _verify(selfd, expected_lines, std_out, std_err):  # type: (str, List[str], List[str], List[str]) -> Bool
        print("test: verify ...")
        has_passed = True

        if len(std_err) > 0:
            has_passed = False
            print("test: failed: found unexpeted stderr lines: {}".format(len(std_err)))
            for line in std_err:
                print("test: \"{}\"".format(line))

        len_expected, len_actual = len(std_out), len(expected_lines)
        if len_expected != len_actual:
            has_passed = False
            print("test: failed: expected number of stdout lines does not match: expected={} vs, actual={}"
                  .format(len_expected, len_actual))
        else:
            for expected_line, actual_line in zip(expected_lines, std_out):
                if expected_line != actual_line:
                    has_passed = False
                    print("test: failed: expected line does not match: expected=\"{}\" vs. actual=\"{}\""
                          .format(expected_line, actual_line))

        if not has_passed:
            print("test: expected stdout lines:")
            for line in expected_lines:
                print("test: \"{}\"".format(line))
            print("test: actual stdout lines:")
            for line in std_out:
                print("test: \"{}\"".format(line))

        return has_passed

    def _test_transaction(self):  # type: (None) -> Tuple[List[str],List[str]]
        print("test: transaction ...")
        std_out, std_err = None, None
        try:
            self.test_program.wait(timeout=1)
            std_out, std_err = self.test_program.communicate(timeout=1)
        except subprocess.TimeoutExpired:
            print("test: wait test program error")
            test_program.kill()

        def lines_from_bytes(bytes):
            return str(bytes.strip().decode("ascii")).split('\n') if len(bytes) > 0 else []

        return lines_from_bytes(std_out), lines_from_bytes(std_err)


class TestRunner:

    def __init__(self, project_dir):
        self.project_dir = project_dir
        self.tests = IntegrationTests().test_set

    def run(self):
        results = [(description, Test(self.project_dir).run(description, command, expected_result)) for
                   description, command, expected_result in self.tests]
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
