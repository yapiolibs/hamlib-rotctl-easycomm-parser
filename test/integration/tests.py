from test_base import TestSet, TestData

ROTCTL_VERSION_3 = r"rotctl\(d\), Hamlib 3.\d"
ROTCTL_VERSION_4 = r"rotctl\(d\), Hamlib 4.\d"
ROTCTL_VERSION_3OR4 = r"({})|({})".format(ROTCTL_VERSION_3, ROTCTL_VERSION_4)

PAUSE_COMMAND = "pause 0.2"  # rotctl need a short break in between commands
EXIT_TEST_PROGRAM_COMMAND = "reset 0"  # abuse "reset" to terminate the test program
EXIT_SEQUENCE = "\\{}\n\\{}\nq\n".format(PAUSE_COMMAND, EXIT_TEST_PROGRAM_COMMAND)

EASYCOMM_1_CLI_ARG = "--model=201"
EASYCOMM_2_CLI_ARG = "--model=202"
EASYCOMM_3_CLI_ARG = "--model=204"


class Easycomm1IntegrationTests(TestSet):
    easycomm1 = "--model=201"

    @staticmethod
    def _test_easycomm_1_rotctl_v4():
        return TestData(
            description="v4   Easycomm 1 command: AZ123.4 EL-12.3 UP1234 upm DN1235 dnm",
            rotctl_commands="w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >AZ123.4\d*<",
                r"received: >EL-12.3\d*<",
                r"received: >UP1234<",
                r"received: >DN1235<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm",
                "Reply: ",
                r"Rotator command: \\pause 0.2",
                "",
                "Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],  # see issue #1
            allowed_rotctl_return_codes=[0],  # see issue #1
            rotctl_extra_program_cli_args=[EASYCOMM_1_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_easycomm_1_rotctl_v3():
        return TestData(
            description="v3   Easycomm 1 command: AZ123.4 EL-12.3 UP1234 upm DN1235 dnm",
            rotctl_commands="w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >AZ123.4\d*<",
                r"received: >EL-12.3\d*<",
                r"received: >UP1234<",
                r"received: >DN1235<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm",
                "Reply: ",
                r"Rotator command: \\pause 0.2",
                "",
                "Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_1_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )


Easycomm1IntegrationTests()


class NoEasycommCommandsIntegrationTests(TestSet):

    @staticmethod
    def _test_park_v3():
        return TestData(
            description="v3   park (command not in Easycomm)",
            rotctl_commands="\\park\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >PARK\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\park",
                "park: error = Communication timed out",  # see issue #1
                "",
                r"Rotator command: \\pause 0.2",
                "",
                r"Rotator command: \\reset 0",
                "reset: error = Communication timed out",  # see issue #1
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[2],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )

    @staticmethod
    def _test_park_v4():
        return TestData(
            description="v4   park (command not in Easycomm)",
            rotctl_commands="\\park\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >PARK\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\park",
                "",
                r"Rotator command: \\pause 0.2",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_reset_v3():
        return TestData(
            description="v3   reset (command not in Easycomm)",
            rotctl_commands="\\reset 0\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\reset 0",
                "reset: error = Communication timed out",  # see issue #1
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[2],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )

    @staticmethod
    def _test_reset_v4():
        return TestData(
            description="v4   reset (command not in Easycomm)",
            rotctl_commands="\\reset 0\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )


NoEasycommCommandsIntegrationTests()


class Easycomm2IntegrationTests(TestSet):
    easycomm2 = "--model=202"

    @staticmethod
    def _test_easycomm2_rotctl_v3_get_pos() -> TestData:
        return TestData(
            description="v3   get_pos: AZ EL",
            rotctl_commands="\\get_pos\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >AZ<",
                r"received: >EL<",
                r"response: >AZ11.0\d* EL12.0\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\get_pos",
                r"Azimuth: 11.0\d*",
                r"Elevation: 12.0\d*",
                "",
                r"Rotator command: \\pause 0.2",
                "",
                r"Rotator command: \\reset 0",
                "reset: error = Communication timed out",  # see issue #1
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[2],  # see issue #1
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )

    @staticmethod
    def _test_easycomm2_rotctl_v4_get_pos() -> TestData:
        return TestData(
            description="v4   get_pos: AZ EL",
            rotctl_commands="\\get_pos\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >AZ<",
                r"received: >EL<",
                r"response: >AZ11.0\d* EL12.0\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\get_pos",
                r"Azimuth: 11.0\d*",
                r"Elevation: 12.0\d*",
                "",
                r"Rotator command: \\pause 0.2",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v3_set_pos() -> TestData:
        return TestData(
            description="v3   set_pos: AZ11.1 EL12.2",
            rotctl_commands="\\set_pos 11.1 12.2\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >AZ11.1\d*<",
                r"received: >EL12.2\d*<",
                r"received: >UP0<",
                r"received: >DN0<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\set_pos 11.1\d* 12.2\d*",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "reset: error = Communication timed out",  # see issue #1
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[2],  # see issue #1
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )

    @staticmethod
    def _test_easycomm2_rotctl_v4_set_pos() -> TestData:
        return TestData(
            description="v4   set_pos: AZ11.1 EL12.2",
            rotctl_commands="\\set_pos 11.1 12.2\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >AZ11.1\d*<",
                r"received: >EL12.2\d*<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\set_pos 11.1\d* 12.2\d*",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v3_stop() -> TestData:
        return TestData(
            description="v3   stop",
            rotctl_commands="\\stop\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >SA<",
                r"received: >SE<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\stop",
                "stop: error = Communication timed out",  # see issue #1
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "reset: error = Communication timed out",  # see issue #1
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )

    @staticmethod
    def _test_easycomm2_rotctl_v4_stop() -> TestData:
        return TestData(
            description="v4   stop",
            rotctl_commands="\\stop\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >SA<",
                r"received: >SE<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\stop",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

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


Easycomm2IntegrationTests()


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
