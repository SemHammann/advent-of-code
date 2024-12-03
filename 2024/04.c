#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "../libraries/adventofcode.c" //V5.1
#include "../libraries/queue.h" //V4.2
#define _DEBUG
#include "../libraries/debug.h" //V0.1



void part1();
void part2();

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	
	fix_file(argv, "M");


	clock_t begin1 = clock();
	printf("\nThings for 1 and 2: %.0lfms\n\n", (double)(begin1 - begin)/CLOCKS_PER_SEC*1000);
	part1();
	clock_t end1 = clock();
	printf("\n%.0lfms\n\n", (double)(end1 - begin1)/CLOCKS_PER_SEC*1000);
	part2();
	clock_t end2 = clock();
	printf("\n%.0lfms", (double)(end2 - end1)/CLOCKS_PER_SEC*1000);
}

void part1() 
{
	long long answer;

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer;

	printf("Part 2: %lld", answer);
}