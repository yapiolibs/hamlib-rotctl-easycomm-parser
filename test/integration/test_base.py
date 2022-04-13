from typing import List


class TestData(object):
    def __init__(self,
                 description: str = "",
                 rotctl_commands: str = "",
                 rotctl_extra_program_cli_args: List[str] = [0],
                 allowed_rotctl_versions: str = "",
                 expected_test_program_stdout_lines: List[str] = [],
                 expected_rotctl_stdout_lines: List[str] = [],
                 allowed_test_program_return_codes: List[int] = [0],
                 allowed_rotctl_return_codes: List[int] = [0]):
        """
        :param description: A human readable test name.

        :param rotctl_commands: The string sent to rotctl at start-time via stdin; same syntax as in interactive mode.
        :param rotctl_extra_program_cli_args: Useful if a specific Easycomm version shall be enforced.


        :param allowed_rotctl_versions:
               A regex to match against 1st line of `rotctl --version`.
               If no match the test data will be ignored.
               Useful when specific hamlib versions must be treated specifically.

        :param expected_test_program_stdout_lines:
               The expected output of the parser test-program.
               Every command's string-representation is enclosed in > and < to make leading/trailing whitespaces
               and line endings visible.
        :param expected_rotctl_stdout_lines: The expected output of the rotctl program.

        :param allowed_test_program_return_codes: A list of accepted return codes.
        :param allowed_rotctl_return_codes: A list of accepted return codes.
        """
        self.description: str = description
        self.rotctl_commands: str = rotctl_commands
        self.rotctl_extra_program_cli_args: List[str] = rotctl_extra_program_cli_args
        self.allowed_rotctl_versions = allowed_rotctl_versions
        self.expected_test_program_stdout_lines: List[str] = expected_test_program_stdout_lines
        self.expected_rotctl_stdout_lines: List[str] = expected_rotctl_stdout_lines
        self.allowed_test_program_return_codes: List[int] = allowed_test_program_return_codes
        self.allowed_rotctl_return_codes: List[int] = allowed_rotctl_return_codes


class TestSet(object):
    """
    Methods of derived classes starting with "_test_" are considered as test methods.
    Test methods returning None are ignored.
    In order to register the tests of a derived class it must instantiate exactly once.
    """

    _tests: List[TestData] = []

    def __init__(self):
        for method_name in dir(self):
            if method_name.startswith('_test_'):
                test_method = getattr(self, method_name)
                test_data = test_method()
                if test_data is not None:
                    TestSet._tests.append(test_data)

    @staticmethod
    def test_set():
        return TestSet._tests
