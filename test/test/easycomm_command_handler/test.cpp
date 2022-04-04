#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include <easycomm-command-callback-handler.h>
#include <unity.h>


void testCallback(const EasycommData *command, void *custom_data) { (*(uint16_t *)custom_data)++; }


void test_command_handler_invoke_registered_callback_01()
{
    uint16_t num_callback_invocations = 0;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
    cb_handler.registry[EasycommIdSingleLine] = testCallback;
    const char *command = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";
    TEST_ASSERT_TRUE(easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, &num_callback_invocations));
    TEST_ASSERT_EQUAL(1, num_callback_invocations);
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


void test_command_handler_invoke_default_callbacks_version_1()
{
    uint16_t num_callback_invocations = 0;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, EasycommParserStandard1, testCallback);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ0.0 EL0.0 UP0 UUU DN0 DDD", &cb_handler,
                                           EasycommParserStandard1, &num_callback_invocations));
    TEST_ASSERT_EQUAL(1, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("PARK", &cb_handler, EasycommParserStandard1, &num_callback_invocations));
    TEST_ASSERT_EQUAL(2, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("RESET", &cb_handler, EasycommParserStandard1, &num_callback_invocations));
    TEST_ASSERT_EQUAL(3, num_callback_invocations);
}


void test_command_handler_invoke_default_callbacks_version_12()
{
    uint16_t num_callback_invocations = 0;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, EasycommParserStandard12, testCallback);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ0.0 EL0.0 UP0 UUU DN0 DDD", &cb_handler,
                                           EasycommParserStandard12, &num_callback_invocations));
    TEST_ASSERT_EQUAL(1, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("PARK", &cb_handler, EasycommParserStandard12, &num_callback_invocations));
    TEST_ASSERT_EQUAL(2, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("RESET", &cb_handler, EasycommParserStandard12, &num_callback_invocations));
    TEST_ASSERT_EQUAL(3, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ123.1", &cb_handler, EasycommParserStandard12,
                                           &num_callback_invocations));
    TEST_ASSERT_EQUAL(4, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ", &cb_handler, EasycommParserStandard12, &num_callback_invocations));
    TEST_ASSERT_EQUAL(5, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("EL123.1", &cb_handler, EasycommParserStandard12,
                                           &num_callback_invocations));
    TEST_ASSERT_EQUAL(6, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("EL", &cb_handler, EasycommParserStandard12, &num_callback_invocations));
    TEST_ASSERT_EQUAL(7, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ EL", &cb_handler, EasycommParserStandard12, &num_callback_invocations));
    TEST_ASSERT_EQUAL(8, num_callback_invocations);
}


void test_command_handler_invoke_default_callbacks_version_123()
{
    uint16_t num_callback_invocations = 0;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, EasycommParserStandard123, testCallback);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ0.0 EL0.0 UP0 UUU DN0 DDD", &cb_handler,
                                           EasycommParserStandard123, &num_callback_invocations));
    TEST_ASSERT_EQUAL(1, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("PARK", &cb_handler, EasycommParserStandard123, &num_callback_invocations));
    TEST_ASSERT_EQUAL(2, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("RESET", &cb_handler, EasycommParserStandard123, &num_callback_invocations));
    TEST_ASSERT_EQUAL(3, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ123.1", &cb_handler, EasycommParserStandard123,
                                           &num_callback_invocations));
    TEST_ASSERT_EQUAL(4, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ", &cb_handler, EasycommParserStandard123, &num_callback_invocations));
    TEST_ASSERT_EQUAL(5, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("EL123.1", &cb_handler, EasycommParserStandard123,
                                           &num_callback_invocations));
    TEST_ASSERT_EQUAL(6, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("EL", &cb_handler, EasycommParserStandard123, &num_callback_invocations));
    TEST_ASSERT_EQUAL(7, num_callback_invocations);

    TEST_ASSERT_TRUE(easycommHandleCommand("AZ EL", &cb_handler, EasycommParserStandard123, &num_callback_invocations));
    TEST_ASSERT_EQUAL(8, num_callback_invocations);
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
    RUN_TEST(test_command_handler_invoke_default_callbacks_version_1);
    RUN_TEST(test_command_handler_invoke_default_callbacks_version_12);
    RUN_TEST(test_command_handler_invoke_default_callbacks_version_123);

    UNITY_END();

#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
