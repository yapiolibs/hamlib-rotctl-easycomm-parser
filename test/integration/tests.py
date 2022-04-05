from test_base import TestSet, TestData

ROTCTL_VERSION_3 = "rotctl(d), Hamlib 3.0"
ROTCTL_VERSION_4 = "rotctl(d), Hamlib 4.0"

ROTCTL_VERSION_3OR4 = r"({})|({})".format(ROTCTL_VERSION_3, ROTCTL_VERSION_4)
PAUSE_COMMAND = "pause 0.2"  # rotctl need a short break in between commands
EXIT_COMMAND = "reset 0"  # abuse "reset" to exit the test program
EXIT_SEQUENCE = "{} {}".format(PAUSE_COMMAND, EXIT_COMMAND)

EASYCOMM_1_CLI_ARG = "--model=201"
EASYCOMM_2_CLI_ARG = "--model=202"
EASYCOMM_3_CLI_ARG = "--model=204"


class Easycomm1IntegrationTests(TestSet):
    easycomm1 = "--model=201"

    @staticmethod
    def _test_easycomm_1():
        return None  # TODO
        # description = "Easycomm 1 command: AZ123.4 EL-12.3 UP1234 upm DN1235 dnm"
        # rotctl_program_cli_args = [IntegrationTests.easycomm1]


Easycomm1IntegrationTests()


class IntegrationTests(TestSet):

    @staticmethod
    def _test_park():
        return None  # TODO
        # rotor park
        # PARK

    @staticmethod
    def _test_reset():
        return None  # TODO
        # RESET


IntegrationTests()


class Easycomm2sIntegrationTests(TestSet):
    easycomm2 = "--model=202"

    @staticmethod
    def _test_easycomm2_get_pos() -> TestData:
        return TestData(
            description="get_pos: AZ EL",
            rotctl_commands="get_pos {}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >AZ<",
                r"received: >EL<",
                r"response: >AZ11.0\d* EL12.0\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"get_pos 11.0\d*",
                r"12.0\d*",
                r"",
                r"{} ".format(PAUSE_COMMAND),
                r"{}.*".format(
                    EXIT_COMMAND)],  # less restrictive; see issue #1
            allowed_rotctl_return_codes=[0, 2],  # less restrictive; see issue #1
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG]
        )

    @staticmethod
    def _test_easycomm2_set_pos() -> TestData:
        return TestData(
            description="set_pos: AZ11.1 EL12.2",
            rotctl_commands="set_pos 11.1 12.2 {}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >AZ11.1\d*<",
                r"received: >EL12.2\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"set_pos 11.1\d* 12.2\d* ",
                r"{} ".format(PAUSE_COMMAND),
                r"{}.*".format(EXIT_COMMAND)],  # less restrictive; see issue #1
            allowed_rotctl_return_codes=[0, 2],  # less restrictive; see issue #1
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG]
        )

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


Easycomm2sIntegrationTests()


class Easycomm3IntegrationTests(TestSet):

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


Easycomm3IntegrationTests()
