#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "..\libraries\adventofcode.c"

#define TEST1

#if defined TEST1
    #define filename "txt/10.test1.txt"
#elif defined TEST2
	#define filename "txt/10.test2.txt"
#else
    #define filename "txt/10.txt"
#endif

typedef struct Position
{
	size_t x, y;
}Position_t;

Position_t start;
Position_t current;

void part1();
void part2();

void search_start();



int main(void)
{
	clock_t begin = clock();
	file = readfile(filename);

	search_start();

	clock_t begin1 = clock();
	printf("\nThings for 1 and 2: %lfms\n\n", (double)(begin1 - begin));
	part1();
	clock_t end1 = clock();
	printf("\n%lfms\n\n", (double)(end1 - begin1));
	part2();
	clock_t end2 = clock();
	printf("\n%lfms", (double)(end2 - end1));
}

void part1()
{
	size_t answer;

	printf("Part 1: %llu", answer);
}

void part2()
{
	size_t answer;

	printf("Part 2: %llu", answer);
}

void search_start()
{
	for(size_t i = 0; i < file.lengthfile; i++)
	{
		for(size_t j = 0; j < file.maxlengthfile; j++)
		{
			if(file.file[i][j] == 'S')
			{
				start.x = j;
				start.y = i;
				return;
			}
		}
	}
}