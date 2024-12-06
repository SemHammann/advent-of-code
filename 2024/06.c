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

struct Data
{
	size_t start_y, start_x, y, x, current_direction;
	size_t horizontal[4];
	size_t vertical[4];
	char direction;
};
struct Data data;

void part1();
void part2();

void search_start();
void walk();
long long check_amount_walked();

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	
	fix_file(argv, "M");


	search_start();
	data.horizontal[0] = 1;
	data.horizontal[1] = 0;
	data.horizontal[2] = -1;
	data.horizontal[3] = 0;

	data.vertical[0] = 0;
	data.vertical[1] = 1;
	data.vertical[2] = 0;
	data.vertical[3] = -1;
	


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

	walk();

	answer = check_amount_walked();

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	printf("Part 2: %lld", answer);
}

void search_start()
{
	for(size_t y = 0; y < file.amountlines; y++)
		for(size_t x = 0; x < file.lengthlines[y]; x++)
		{
			if(file.file[y][x] == 'v' || file.file[y][x] == '<' || file.file[y][x] == '^' || file.file[y][x] == '>')
			{
				data.start_y = y;
				data.start_x = x;
				data.y = y;
				data.x = x;
				data.direction = file.file[y][x];
				if(file.file[y][x] == '>')
					data.current_direction = 0;
				if(file.file[y][x] == 'v')
					data.current_direction = 1;
				if(file.file[y][x] == '<')
					data.current_direction = 2;
				if(file.file[y][x] == '^')
					data.current_direction = 3;
				return;
			}
		}
}

void walk()
{
	while(true)
	{
		while(file.file[data.y + data.vertical[data.current_direction]][data.x + data.horizontal[data.current_direction]] != '#')
		{
			file.file[data.y][data.x] = 'X';
			data.y += data.vertical[data.current_direction];
			data.x += data.horizontal[data.current_direction];
			if(data.y + data.vertical[data.current_direction] < 0 || data.y + data.vertical[data.current_direction] >= file.amountlines)
			{
				file.file[data.y][data.x] = 'X';
				return;
			}
			if(data.x + data.horizontal[data.current_direction] < 0 || data.x + data.horizontal[data.current_direction] >= file.lengthlines[data.y])
			{
				file.file[data.y][data.x] = 'X';
				return;
			}
		}
		data.current_direction++;
		data.current_direction = data.current_direction % 4;
	}
}

long long check_amount_walked()
{
	long long answer = 0;
	for(size_t y = 0; y < file.amountlines; y++)	
		for(size_t x = 0; x < file.lengthlines[y]; x++)
			if(file.file[y][x] == 'X')
				answer++;

	return answer;
}