#pragma once
#include "defines.h"
#include"asserts.h"

// log everything by default (debug mode)
#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// when in release mode, don't log debug or trace
#if NRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

// define our level of logging
typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,

} log_level;

// Start loggging, returns true if succesful
b8 init_logging();

// Stops logging regardless of state
void stop_logging();

// funnels all of the internal logging output
NEX void log_output(log_level level, const char* message, ...);

#ifndef NFATAL
// does variadic arguments with preprocesser for fatal message log
#define NFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#endif

#ifndef NERROR
// does variadic arguments with preprocesser for error message log
#define NERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// does variadic arguments with preprocesser for warn message log
#define NWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define NWARN(message, ...)  // do nothing
#endif

#if LOG_INFO_ENABLED == 1
// does variadic arguments with preprocesser for info message log
#define NINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define NINFO(message, ...)  // do nothing
#endif

#if LOG_DEBUG_ENABLED == 1
// does variadic arguments with preprocesser for debug message log
#define NDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define NDEBUG(message, ...)  // do nothing
#endif

#if LOG_TRACE_ENABLED == 1
// does variadic arguments with preprocesser for trace message log
#define NTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define NTRACE(message, ...)  // do nothing
#endif
