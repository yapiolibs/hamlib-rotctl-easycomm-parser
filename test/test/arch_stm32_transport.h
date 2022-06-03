#pragma once
#if defined(ARDUINO_ARCH_STM32)
#ifdef __cplusplus
extern "C"
{
#endif
    void unittest_uart_putchar(char c);
    void unittest_uart_flush();
    void unittest_uart_begin();
    void unittest_uart_end();

#define UNITY_OUTPUT_CHAR(a) void unittest_uart_putchar(char c)
//#define UNITY_OUTPUT_CHAR_HEADER_DECLARATION unittest_uart_putchar(int c)
#define UNITY_OUTPUT_FLUSH() void unittest_uart_flush();
//#define UNITY_OUTPUT_FLUSH_HEADER_DECLARATION unittest_uart_flush(void)
#define UNITY_OUTPUT_START() unittest_uart_begin();
#define UNITY_OUTPUT_COMPLETE() unittest_uart_end();

#ifdef __cplusplus
}
#endif
#endif
