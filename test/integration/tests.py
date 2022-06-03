from test_base import TestSet, TestData

"""
examples:
- "rotctl(d), Hamlib 3.0"
- "rotctl(d), Hamlib 4.0"
- "rotctl(d), Hamlib 4.4 Thu Dec 02 23:46:51 2021 +0000 SHA=5f8c4c"

"""
ROTCTL_VERSION_3 = r"rotctl\(d\), Hamlib 3.\d"
ROTCTL_VERSION_4 = r"rotctl\(d\), Hamlib 4.\d.*"
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
            description="rotctl=v4.x easycomm=1 command: AZ123.4 EL-12.3 UP1234 upm DN1235 dnm",
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
            description="rotctl=v3.x easycomm=1 command: AZ123.4 EL-12.3 UP1234 upm DN1235 dnm",
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
            description="rotctl=v3.x easycomm=? park (command not in Easycomm)",
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
            description="rotctl=v4.x easycomm=? park (command not in Easycomm)",
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
            description="rotctl=v3.x easycomm=? reset (command not in Easycomm)",
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
            description="rotctl=v4.x easycomm=? reset (command not in Easycomm)",
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
            description="rotctl=v3.x easycomm=2 get_pos: AZ EL",
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
            description="rotctl=v4.x easycomm=2 get_pos: AZ EL",
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
            description="rotctl=v3.x easycomm=2 set_pos: AZ11.1 EL12.2",
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
            description="rotctl=v4.x easycomm=2 set_pos: AZ11.1 EL12.2",
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
            description="rotctl=v3.x easycomm=2 stop",
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
                "Rotator command: q"],  # see issue #1
            allowed_rotctl_return_codes=[2],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3
        )

    @staticmethod
    def _test_easycomm2_rotctl_v4_stop() -> TestData:
        return TestData(
            description="rotctl=v4.x easycomm=2 stop",
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
    def _test_easycomm2_rotctl_v34_get_uplink_frequency() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get uplink frequency: UP",
            rotctl_commands="w UP\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >UP<",
                r"response: >UP30000000<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w UP",
                "Reply: UP30000000",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v34_get_downlink_frequency() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get downlink frequency: DN",
            rotctl_commands="w DN\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >DN<",
                r"response: >DN29000000<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w DN",
                "Reply: DN29000000",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v34_get_uplink_mode() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get uplink mode: UM",
            rotctl_commands="w UM\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >UM<",
                r"response: >UMCW<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w UM",
                "Reply: UMCW",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v34_get_downlink_mode() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get downlink mode: DM",
            rotctl_commands="w DM\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >DM<",
                r"response: >DMUSB<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w DM",
                "Reply: DMUSB",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v34_get_uplink_radio() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get uplink radio: UR",
            rotctl_commands="w UR\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >UR<",
                r"response: >UR1<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w UR",
                "Reply: UR1",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v34_get_downlink_radio() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get downlink radio: DR",
            rotctl_commands="w DR\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >DR<",
                r"response: >DR2<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w DR",
                "Reply: DR2",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_rotctl_v34_get_time() -> TestData:
        return TestData(
            description="rotctl=v3|4 easycomm=2 get time: ST",
            rotctl_commands="w ST\n\\pause 0.2\nw RESET\nq\n",
            expected_test_program_stdout_lines=[
                r"received: >ST<",
                r"response: >ST70:01:01:23:59:59<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                "Rotator command: w ST",
                "Reply: ST70:01:01:23:59:59",
                "",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: w RESET",
                "Reply: ",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_2_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_3OR4
        )

    @staticmethod
    def _test_easycomm2_get_info():
        return None  # TODO

    @staticmethod
    def _test_easycomm2_rotctl_v4_move_up():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=2 move: UP SPEED",
            rotctl_commands="\\move 2 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >MU<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 2 100",
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
    def _test_easycomm2_rotctl_v4_move_down():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=2 move: DOWN SPEED",
            rotctl_commands="\\move 4 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >MD<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 4 100",
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
    def _test_easycomm2_rotctl_v4_move_left():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=2 move: LEFT SPEED",
            rotctl_commands="\\move 8 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >ML<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 8 100",
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
    def _test_easycomm2_rotctl_v4_move_right():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=2 move: RIGHT SPEED",
            rotctl_commands="\\move 16 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >MR<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 16 100",
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


Easycomm2IntegrationTests()


class Easycomm3IntegrationTests(TestSet):

    @staticmethod
    def _test_easycomm3_rotctl_v4_move_up():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=3 move: UP SPEED",
            rotctl_commands="\\move 2 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >VU9900<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 2 100",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_3_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_easycomm3_rotctl_v4_move_down():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=3 move: DOWN SPEED",
            rotctl_commands="\\move 4 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >VD9900<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 4 100",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_3_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_easycomm3_rotctl_v4_move_left():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=3 move: LEFT SPEED",
            rotctl_commands="\\move 8 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >VL9900<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 8 100",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_3_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

    @staticmethod
    def _test_easycomm3_rotctl_v4_move_right():
        # defect behaviour is reported in https://github.com/Hamlib/Hamlib/issues/1006
        return TestData(
            description="rotctl=v4.x easycomm=3 move: RIGHT SPEED",
            rotctl_commands="\\move 16 100\n{}".format(EXIT_SEQUENCE),
            expected_test_program_stdout_lines=[
                r"received: >VR9900<",
                r"received: >RESET<"],
            allowed_test_program_return_codes=[0],
            expected_rotctl_stdout_lines=[
                r"Rotator command: \\move 16 100",
                "",
                r"Rotator command: \\pause 0.2\d*",
                "",
                r"Rotator command: \\reset 0",
                "",
                "Rotator command: q"],
            allowed_rotctl_return_codes=[0],
            rotctl_extra_program_cli_args=[EASYCOMM_3_CLI_ARG],
            allowed_rotctl_versions=ROTCTL_VERSION_4
        )

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
