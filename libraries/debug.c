//V0.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>

#include "../libraries/debug.h"

int debug_print(const char *str, ...)
{
	#if defined(DEBUG) || defined(_DEBUG)
    va_list args;
    va_start(args, str);

    // Use vfprintf to handle formatting directly
    int result = vfprintf(stdout, str, args);

    va_end(args);
    return result;
	#else
	return 0;
	#endif
}