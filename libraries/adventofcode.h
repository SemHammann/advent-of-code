//V1.0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <inttypes.h>

#include "bloem.h"
#include "queue.h"
#include "debug.h"

extern long long unsigned str_to_llu(char *vstring);
extern long long str_ll(char *vstring);
extern char **str_split(char* a_str, const char a_delim, bool doublechar);
extern char *searchAndReplace(char *text, char *search, char *replace);

void part1();
void part2();