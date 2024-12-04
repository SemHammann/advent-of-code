#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "../libraries/adventofcode.c" //V5.1
#include "../libraries/queue.c" //V4.2
#define _DEBUG
#include "../libraries/debug.c" //V0.1



void part1();
void part2();

long long check();
long long check_xmas();
long long check2();
long long check_mas();

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

	answer = check();

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer;

	answer = check2();

	printf("Part 2: %lld", answer);
}

long long check()
{
	long long answer = 0; 
	for(size_t y = 0; y < file.amountlines; y++)
	{
		for(size_t x = 0; x < file.lengthlines[0]; x++)
		{
			if(file.file[y][x] == 'X')
			{
				answer += check_xmas(y, x, 1, 0);
				answer += check_xmas(y, x, -1, 0);
				answer += check_xmas(y, x, 0, 1);
				answer += check_xmas(y, x, 0, -1);
				answer += check_xmas(y, x, 1, 1);
				answer += check_xmas(y, x, -1, -1);
				answer += check_xmas(y, x, -1, 1);
				answer += check_xmas(y, x, 1, -1);
			}
		}
	}
	return answer;
}

long long check_xmas(size_t y, size_t x, int dif_y, int dif_x)
{
	if((x + dif_x < file.lengthlines[0]) && (y + dif_y < file.amountlines) && (file.file[y + dif_y][x + dif_x] == 'M'))
		if((x + 2 * dif_x < file.lengthlines[0]) && (y + 2 *dif_y < file.amountlines) &&  (file.file[y + 2 * dif_y][x + 2 * dif_x] == 'A'))
			if((x + 3 * dif_x < file.lengthlines[0]) && (y + 3 * dif_y < file.amountlines) && (file.file[y + 3 * dif_y][x + 3 * dif_x] == 'S'))
			{
				//printf("%lld, %lld\n", x, y);
				return 1;
			}
	return 0;
}

long long check2()
{
	long long answer = 0;
	long long possible;
	for(size_t y = 0; y < file.amountlines; y++)
	{
		for(size_t x = 0; x < file.lengthlines[0]; x++)
		{
			possible = 0;
			if(file.file[y][x] == 'A')
			{
				possible += check_mas(y, x, 1, 1);
				possible += check_mas(y, x, 1, -1);
				possible += check_mas(y, x, -1, 1);
				possible += check_mas(y, x, -1, -1);
				
				if(possible == 2)
					answer++;
			}
		}
	}
	return answer;
}

long long check_mas(size_t y, size_t x, int dif_y, int dif_x)
{
	if((x + -dif_x < file.lengthlines[0]) && (y + -dif_y < file.amountlines) && (file.file[y - dif_y][x - dif_x] == 'M'))
		if((x + dif_x < file.lengthlines[0]) && (y + dif_y < file.amountlines) &&  (file.file[y + dif_y][x + dif_x] == 'S'))
			return 1;
	return 0;
}