#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <inttypes.h>

#include "../libraries/adventofcode.c" //V5.1
#include "../libraries/queue.c" //V4.2
#define _DEBUG
#include "../libraries/debug.c" //V0.1


char **antinodes;

void part1();
void part2();

void fill_antinodes(char frequency);
void fill_antinodes2(char frequency);
long long count_antinodes();

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	
	fix_file(argv, "M");
	antinodes = calloc(file.amountlines + 1, sizeof(char*));
	for(size_t i = 0; i < file.amountlines; i++)
	{
		*(antinodes + i) = calloc(file.lengthlines[i] + 1, sizeof(char));
	}


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
	long long answer = 0;

	for(char i = 0; i < 127; i++)
	{
		if(i != '.')
			fill_antinodes(i);
	}

	answer = count_antinodes();
	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	for(char i = 0; i < 127; i++)
	{
		if(i != '.')
			fill_antinodes(i);
	}

	answer = count_antinodes();

	printf("Part 2: %lld", answer);
}

void fill_antinodes(char frequency)
{
	long long yt, xt;
	for(long long y1 = 0; y1 < file.amountlines; y1++)
	{
		for(long long x1 = 0; x1 < file.lengthlines[y1]; x1++)
		{
			if(file.file[y1][x1] == frequency)
			{
			for(size_t y2 = 0; y2 < file.amountlines; y2++)
			{
				for(size_t x2 = 0; x2 < file.lengthlines[y2]; x2++)
				{
					if(!(x1 == x2 && y1 == y2) && file.file[y2][x2] == frequency)
					{
						yt = y1 - y2;
						xt = x1 - x2;
						if(x1 + xt >= 0 && x1 + xt < file.lengthlines[0] && y1 + yt >= 0 && y1 + yt < file.amountlines)
							antinodes[y1 + yt][x1 + xt] = '#';
						if(x2 - xt >= 0 && x2 - xt < file.lengthlines[0] && y2 - yt >= 0 && y2 - yt < file.amountlines)
							antinodes[y2 - yt][x2 - xt] = '#';
					}
				}
			}
			}
		}
	}
}

void fill_antinodes2(char frequency)
{
	long long yt, xt;
	for(long long y1 = 0; y1 < file.amountlines; y1++)
	{
		for(long long x1 = 0; x1 < file.lengthlines[y1]; x1++)
		{
			if(file.file[y1][x1] == frequency)
			{
			for(size_t y2 = 0; y2 < file.amountlines; y2++)
			{
				for(size_t x2 = 0; x2 < file.lengthlines[y2]; x2++)
				{
					if(!(x1 == x2 && y1 == y2) && file.file[y2][x2] == frequency)
					{
						yt = y1 - y2;
						xt = x1 - x2;
						if(x1 + xt >= 0 && x1 + xt < file.lengthlines[0] && y1 + yt >= 0 && y1 + yt < file.amountlines)
							antinodes[y1 + yt][x1 + xt] = '#';
						if(x2 - xt >= 0 && x2 - xt < file.lengthlines[0] && y2 - yt >= 0 && y2 - yt < file.amountlines)
							antinodes[y2 - yt][x2 - xt] = '#';
					}
				}
			}
			}
		}
	}
}

long long count_antinodes()
{
	long long answer = 0;
	for(size_t y = 0; y < file.amountlines; y++)
		for(size_t x = 0; x < file.lengthlines[y]; x++)
			if(antinodes[y][x] == '#')
				answer++;

	return answer;
}