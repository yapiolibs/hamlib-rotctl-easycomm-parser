class TestSet(object):

    def __init__(self):
        self._tests = []  # type: List[Tuple[str, str, List[str]]]

        for method_name in dir(self):
            if method_name.startswith('_test_'):
                test_method = getattr(self, method_name)
                self._add_test(*test_method())

    @property
    def test_set(self):
        return self._tests

    def _add_test(self, description, commands, expected_lines):  # type: (str, str, List[str]) -> None
        self._tests.append((description, commands, expected_lines))


class IntegrationTests(TestSet):
    """
    Procedure:
      The test program receives data from rotctl. The data is parsed and its representation echoed to stdout.
      If the command expects a response a dummy response is generated to satisfy rotctl.

    Test data:
      description: a human readable test name
      commands: commands that are sent to rotctl, same as in interactive mode but space separated and
        without leading '\'
        example: "p pause 0.2 get_pos pause 0.2 reset 0"
      expected test-program lines: the expected output of the test program (Easycomm parser library)
      expected rotctl lines: the expected output of rotctl

     Test program:
       The program reads data and feeds the parser to test its output. It reads dara from a pipe, parses the
       commands (Easycomm III) and echoes the command inclusive its response (if any) to stdout.
       The response is also written to the pipe back to rotctl.


    """

    @staticmethod
    def _test_get_pos():  # type: () -> str, str, List[str]
        description = "get_pos: AZ EL"
        commands = "get_pos pause 0.3 reset 0"
        expected_lines = ["received: >AZ EL<",
                          "response: >AZ2.0 EL1.0<",
                          "received: >RESET<"]
        # expected_rotctl_lines = [] TODO: implement also the validation of rotctl output
        return description, commands, expected_lines


# TODO

# set position
# "AZ%.1f EL%.1f UP000 XXX DN000 XXX\n
# "AZ%.1f EL%.1f

# get position
# AZ EL -> AZf ELf

# movement stop
# "SA SE

# rotor park
# PARK

# rotor move
# MU MD ML MR

# move velocity 0 - 100 vs 0 - 9999
# "VU%04d\ vd vr fl

#get registers
# GS GE IP AM VE CR
