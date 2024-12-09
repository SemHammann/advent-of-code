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
	int *data;
	size_t length;
	int last;
};
struct Data data;

void part1();
void part2();

void setup();
void compress();
void compress2();
long long count();

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
	long long answer = 0;
	setup();

	compress();
	answer = count();

	free(data.data);
	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;
	setup();

	compress2();
	answer = count();

	printf("Part 2: %lld", answer);
	free(data.data);
}

void setup()
{
	size_t j = 0, k = 0;
	int tmp;
	data.length = 0;
	for(size_t i = 0; i < file.lengthlines[0]; i++)
		data.length += file.file[0][i] - '0';

	data.data = calloc(data.length + 1, sizeof(int));
	for(size_t i = 0; i < data.length + 1; i++)
		data.data[i] = -1;

	for(size_t i = 0; i < file.lengthlines[0]; i++)
	{
		for(long long l = 0; l < file.file[0][i] - '0'; l++)
		{
			data.data[j] = k;
			j++;
		}
		i++;
		k++;
		for(long long l = 0; l < (tmp = file.file[0][i] - '0'); l++)
		{
			data.data[j] = -1;
			j++;
		}
	}
	data.last = k - 1;
	return;
}

void compress()
{
	int first_free= 0, end = data.length;
	while(end > first_free)
	{
		while(data.data[first_free] != -1)
			first_free++;
		while(data.data[end] == -1)
			end--;
		if(first_free < end)
		{
			data.data[first_free] = data.data[end];
			data.data[end] = -1;
		}
		else
			return;
	}
}

void compress2()
{
	int first_free= 0, end = data.length;
	int free_count, end_count;
	bool free_already;
	while(data.last >= 0)
	{
		end_count = 0;
		free_count = 0;
		first_free = 0;
		while(data.data[end] != data.last)
			end--;
		while(data.data[end - end_count] == data.last)
			end_count++;

		data.last--;

		while(free_count < end_count)
		{
			free_count = 0;
			if(!free_already)
				first_free++;
			free_already = false;
			
			while(data.data[first_free] != -1)
			{
				first_free++;
				free_already = true;
				if(first_free >= data.length)
					break;
			}
			if(first_free >= data.length)
					break;
			while(data.data[first_free + free_count] == -1)
				free_count++;
		}

		
		if(free_count >= end_count && end > first_free)
		{
			for(size_t i = 0; i < end_count; i++)
			{
				data.data[first_free + i] = data.data[end - i];
				data.data[end - i] = -1;
			}
		}
	}
}

long long count()
{
	long long answer = 0;
	size_t i = 0;
	for(i = 0; i < data.length; i++)
	{
		if(data.data[i] != -1)
			answer += i * data.data[i];

		// printf("%d, ", data.data[i]);
	}
	return answer;
}