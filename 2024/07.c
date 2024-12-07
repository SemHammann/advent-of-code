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
	long long *answers;
	long long **input;
	size_t *amount_input;
};
struct Data data;


void part1();
void part2();

void fill_data();
long long possible();
long long possible2();

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	
	fix_file(argv, "M");
	fill_data();


	clock_t begin1 = clock();
	printf("\nThings for 1 and 2: %.0lf ms\n\n", (double)(begin1 - begin)/CLOCKS_PER_SEC*1000);
	part1();
	clock_t end1 = clock();
	printf("\n%.0lf ms\n\n", (double)(end1 - begin1)/CLOCKS_PER_SEC*1000);
	part2();
	clock_t end2 = clock();
	printf("\n%.0lf ms", (double)(end2 - end1)/CLOCKS_PER_SEC*1000);
}

void part1() 
{
	long long answer = 0;

	for(size_t i = 0; i < file.amountlines; i++)
		answer += possible(i, 0, 0);

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	for(size_t i = 0; i < file.amountlines; i++)
		answer += possible2(i, 0, 0);

	printf("Part 2: %lld", answer);
}

void fill_data()
{
	char **tokens;
	char game[4096];
	size_t j, k;
	
	data.answers = calloc(file.amountlines, sizeof(long long));
	data.input = calloc(file.amountlines, sizeof(long long*));
	data.amount_input = calloc(file.amountlines, sizeof(size_t));

	for(size_t i = 0; i < file.amountlines; i++)
	{
		strcpy(game, file.file[i]);
		tokens = str_split(game, ':', false);
		*(data.answers + i) = str_ll(*tokens);

		tokens = str_split(*(tokens + 1), ' ', false);
		j = 0;
		k = 0;
		while(*(tokens + j) != NULL)
			j++;
		*(data.amount_input + i) = j;
		*(data.input + i) = calloc(j, sizeof(long long));
		while(*(tokens + k) != NULL)
		{
			*(*(data.input + i) + k) = str_ll(*(tokens + k));
			k++;
		}
	}
}

long long possible(size_t place, size_t where, size_t current)
{
	long long mul, add;
	if(where >= *(data.amount_input + place))
	{
		if(current == *(data.answers + place))
			return *(data.answers + place);
		else
			return 0;
	}
	add = current + *(*(data.input + place) + where);
	if(current == 0 && where == 0)
		current = 1;
	mul = current * *(*(data.input + place) + where);
	
	if(possible(place, where + 1, mul) == *(data.answers + place) || possible(place, where + 1, add) == *(data.answers + place))
		return *(data.answers + place);
	else
		return 0;
}

long long possible2(size_t place, size_t where, size_t current)
{
	long long mul, add, cons, fact;
	if(where >= *(data.amount_input + place))
	{
		if(current == *(data.answers + place))
			return *(data.answers + place);
		else
			return 0;
	}
	fact = (long long)pow(10, (long long)(log10(*(*(data.input + place) + where)) + 1));
	add = current + *(*(data.input + place) + where);
	cons = current * fact + *(*(data.input + place) + where);
	if(current == 0 && where == 0)
		current = 1;
	mul = current * *(*(data.input + place) + where);
	
		
	if(possible2(place, where + 1, mul) == *(data.answers + place) || possible2(place, where + 1, add) == *(data.answers + place) || possible2(place, where + 1, cons) == *(data.answers + place))
		return *(data.answers + place);
	else
		return 0;
}