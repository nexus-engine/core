#include "logger.h"
// TODO: remove
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <platform/platform.h>

// Start loggging, returns true if succesful
b8 init_logging() {
    // TODO: create log file

    NINFO("Initialized logger");
    // platform_sleep(5000);
    return TRUE;
}

// Stops logging regardless of state
void stop_logging() {
    // TODO: cleanup logging/write queued entries
}

// funnels all of the internal logging output
void log_output(log_level level, const char* message_in, ...) {
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    b8 is_error = level < LOG_LEVEL_WARN;
    const i32 msg_length = 32000;
    char output[msg_length];
    memset(output, 0, sizeof(output));
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message_in);
    vsnprintf(output, msg_length, message_in, arg_ptr);
    va_end(arg_ptr);
    char message[msg_length];
    sprintf(message, "%s%s\n", level_strings[level], output);
    if (is_error) {
        platform_console_write_error(message, level);
    } else {
        platform_console_write(message, level);
    }
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}