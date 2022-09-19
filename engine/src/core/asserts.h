#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line.
#define NASSERTIONS_ENABLED

#ifdef NASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

NEX void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define NASSERT(expr)                                                \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define NASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define NASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define NASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define NASSERT(expr)               // Does nothing at all
#define NASSERT_MSG(expr, message)  // Does nothing at all
#define NASSERT_DEBUG(expr)         // Does nothing at all
#endif