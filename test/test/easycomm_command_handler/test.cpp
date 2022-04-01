#ifndef ENV_NATIVE
#include <Arduino.h>
#endif

#include <easycomm-command-callback-handler.h>
#include <unity.h>


void testCallback(const EasycommData *command, void *custom_data) { *((bool *)custom_data) = true; }


void test_command_handler_invoke_registered_callback_01()
{
    bool is_callback_invoked = false;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
    cb_handler.registry[EasycommIdSingleLine] = testCallback;
    const char *command = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";
    TEST_ASSERT_TRUE(easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, &is_callback_invoked));
    TEST_ASSERT_TRUE(is_callback_invoked);
}

void test_command_handler_invoke_unregistered_callback_01()
{
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
    cb_handler.registry[EasycommIdSingleLine] = nullptr;
    const char *command = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";
    TEST_ASSERT_FALSE(easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, nullptr));
}

void test_command_handler_invoke_unregistered_callback_02()
{
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
    const char *command = "AZ0.0"; // not an Easycomm standard 1 command
    TEST_ASSERT_FALSE(easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, nullptr));
}

#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
    UNITY_BEGIN();
    RUN_TEST(test_command_handler_invoke_registered_callback_01);
    RUN_TEST(test_command_handler_invoke_unregistered_callback_01);
    RUN_TEST(test_command_handler_invoke_unregistered_callback_02);
    UNITY_END();

#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
