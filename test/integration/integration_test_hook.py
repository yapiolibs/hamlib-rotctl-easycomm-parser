Import("env", "projenv")
from SCons.Script import COMMAND_LINE_TARGETS
import sys
from test_runner import TestRunner

if "idedata" in COMMAND_LINE_TARGETS:
    env.Exit(0)

print("test: build targets:")
for bt in BUILD_TARGETS:
    print("test: * {}".format(bt))


def run_integration_tests(source, target, env):
    project_dir = env["PROJECT_DIR"]
    return TestRunner(project_dir).run()


env.AddCustomTarget("integration", "$BUILD_DIR/${PROGNAME}", run_integration_tests)
