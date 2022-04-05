from typing import List


class TestData(object):
    def __init__(self,
                 description: str = "",
                 rotctl_commands: str = "",
                 rotctl_extra_program_cli_args: List[str] = [0],
                 expected_test_program_stdout_lines: List[str] = [],
                 expected_rotctl_stdout_lines: List[str] = [],
                 allowed_test_program_return_codes: List[int] = [0],
                 allowed_rotctl_return_codes: List[int] = [0]):
        """
        :param description: a human readable test name
        :param rotctl_commands: string sent to rotctl at start-time
               same as in interactive mode but space separated and without leading '\'
               see rotctl --help
        :param rotctl_extra_program_cli_args: the expected output of the parser library test-program
               every command string-representation is enclosed in > and < to make leading/trailing whitespaces visible
        :param expected_test_program_stdout_lines:
        :param expected_rotctl_stdout_lines: the expected output of the rotctl program
        :param allowed_test_program_return_codes: list of accepted return codes
        :param allowed_rotctl_return_codes: list of accepted return codes
        """
        self.description: str = description
        self.rotctl_commands: str = rotctl_commands
        self.rotctl_extra_program_cli_args: List[str] = rotctl_extra_program_cli_args
        self.expected_test_program_stdout_lines: List[str] = expected_test_program_stdout_lines
        self.expected_rotctl_stdout_lines: List[str] = expected_rotctl_stdout_lines
        self.allowed_test_program_return_codes: List[int] = allowed_test_program_return_codes
        self.allowed_rotctl_return_codes: List[int] = allowed_rotctl_return_codes


class TestSet(object):

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
