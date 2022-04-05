from typing import List, Tuple


class TestSet(object):

    def __init__(self):
        self._tests: List[Tuple[str, str, List[str], List[str], List[int], List[str], List[int]]] = []

        for method_name in dir(self):
            if method_name.startswith('_test_'):
                test_method = getattr(self, method_name)
                test_data = test_method()
                if test_data is not None:
                    self._tests.append(test_data)

    @property
    def test_set(self):
        return self._tests


class IntegrationTests(TestSet):
    """
    Test data:
      - description: a human readable test name
      - commands:
         string sent to rotctl at start-time
         same as in interactive mode but space separated and without leading '\'
         see rotctl --help
      - test-program:
        - expected lines (stdout): the expected output of the parser library
          every command string-representation is enclosed in > and < to make leading/trailing whitespaces visible
        - expected return code
      - rotctl:
        - expected lines (stdout): the expected output of rotctl
        - expected return code
    """

    pause_command = "pause 0.2"  # rotctl need a short break in between commands
    exit_command = "reset 0"  # abuse "reset" to exit the test program
    postfix = "{} {}".format(pause_command, exit_command)
    easycomm1 = "--model=201"
    easycomm2 = "--model=202"
    easycomm3 = "--model=204"

    @staticmethod
    def _test_easycomm_1():
        return None  # TODO
        # description = "Easycomm 1 command: AZ123.4 EL-12.3 UP1234 upm DN1235 dnm"
        # rotctl_program_cli_args = [IntegrationTests.easycomm1]

    @staticmethod
    def _test_easycomm2_get_pos() -> (str, str, List[str], List[str], List[int], List[str], List[int]):
        description = "get_pos: AZ EL"
        rotctl_commands = "get_pos {}".format(IntegrationTests.postfix)

        expected_test_program_lines = [
            r"received: >AZ<",
            r"received: >EL<",
            r"response: >AZ11.0\d* EL12.0\d*<",
            r"received: >RESET<"]
        allowed_test_program_return_codes = [0]

        expected_rotctl_lines = [
            r"get_pos 11.0\d*",
            r"12.0\d*",
            r"",
            r"{} ".format(IntegrationTests.pause_command),
            r"{}.*".format(IntegrationTests.exit_command)]  # less restrictive; see issue #1
        allowed_rotctl_return_codes = [0, 2]  # less restrictive; see issue #1

        rotctl_program_cli_args = [IntegrationTests.easycomm2]

        return description, rotctl_commands, rotctl_program_cli_args, expected_test_program_lines, \
               allowed_test_program_return_codes, expected_rotctl_lines, allowed_rotctl_return_codes

    @staticmethod
    def _test_easycomm2_set_pos() -> (str, str, List[str], List[str], List[int], List[str], List[int]):
        description = "set_pos: AZ EL"
        rotctl_commands = "set_pos 11.1 12.2 {}".format(IntegrationTests.postfix)

        expected_test_program_lines = [
            r"received: >AZ11.1\d*<",
            r"received: >EL12.2\d*<",
            r"received: >RESET<"]
        allowed_test_program_return_codes = [0]

        expected_rotctl_lines = [
            r"set_pos 11.1\d* 12.2\d* ",
            r"{} ".format(IntegrationTests.pause_command),
            r"{}.*".format(IntegrationTests.exit_command)]  # less restrictive; see issue #1
        allowed_rotctl_return_codes = [0, 2]  # less restrictive; see issue #1

        rotctl_program_cli_args = [IntegrationTests.easycomm2]
        return description, rotctl_commands, rotctl_program_cli_args, expected_test_program_lines, \
               allowed_test_program_return_codes, expected_rotctl_lines, allowed_rotctl_return_codes

    @staticmethod
    def _test_easycomm2_set_pos2():
        return None  # TODO
        # get position
        # AZ EL -> AZf ELf

    @staticmethod
    def _test_easycomm2_stop():
        return None  # TODO
        # movement stop
        # "SA SE

    @staticmethod
    def _test_not_easycomm_park():
        return None  # TODO
        # rotor park
        # PARK

    @staticmethod
    def _test_easycomm2_set_moveu():
        return None  # TODO
        # rotor move
        # MU MD ML MR

    @staticmethod
    def _test_easycomm2_set_moved():
        return None  # TODO

    @staticmethod
    def _test_easycomm2_set_movel():
        return None  # TODO

    @staticmethod
    def _test_easycomm2_set_mover():
        return None  # TODO

    @staticmethod
    def _test_set_easycomm3_velocityu():
        return None  # TODO
        # move velocity 0 - 100 vs 0 - 9999
        # "VU%04d\ vd vr fl

    @staticmethod
    def _test_easycomm3_set_velocityd():
        return None  # TODO

    @staticmethod
    def _test_easycomm3_set_velocityl():
        return None  # TODO

    @staticmethod
    def _test_easycomm3_set_velocityr():
        return None  # TODO

    @staticmethod
    def _test_easycomm3_set_get_register_xyz():
        return None  # TODO
        # get registers
        # GS GE IP AM VE CR
