#if defined(ENV_NATIVE)
#include "native-integration-test-program.h"

#elif defined(PIO_EXAMPLE_PARSE_COMMAND)
#include "example-parse-command.h"

#elif defined(PIO_EXAMPLE_PARSE_WITH_CALLBACK)
#include "example-parse-with-callback.h"

#elif defined(PIO_EXAMPLE_PARSE_STREAM)
#include "example-parse-stream.h"

#else

#include <Arduino.h>

void setup() {}

void loop() {}

#endif
