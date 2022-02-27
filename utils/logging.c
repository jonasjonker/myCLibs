#include <errno.h>
#include <stdarg.h>

#include "logging.h"

/**
 * @brief variadic function that prints a message before exiting.
 * 
 * @param format as recognixed by printf
 * @param ... as recognized by printf
 */
void exitWithMsg(const char *format, ...) {
    va_list argList;
    va_start(argList, format);
    vprintf(format, argList);
    va_end(argList);
    // capture last error code
    exit(errno);
}
