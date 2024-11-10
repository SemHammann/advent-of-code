#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "..\libraries\adventofcode.c"

#define arraylength 1024
#define stringlength 4096

struct Data
{
	char steps[stringlength];
	size_t start[arraylength];
	size_t left[arraylength];
	size_t right[arraylength];
	size_t value[arraylength];
	size_t new_start[arraylength];
};

struct Data data;
struct Data data2;

void part1();
void part2();

void fill_data();
size_t string_size_t();
size_t check_steps();
void fill_data2();
size_t string_size_t2();
size_t check_steps2();


int main(void)
{
	clock_t begin = clock();
	const char *filename = "txt/8.txt";
	file = readfile(filename);

	fill_data();
	fill_data2();

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

	answer = check_steps();

	printf("Part 1: %llu", answer);
}

void part2()
{
	size_t answer;

	
	answer = check_steps2();

	printf("Part 2: %llu", answer);
}

void fill_data()
{
	size_t i;
	char game[stringlength];
	char tmp[stringlength];
	char **tokens;
	char **tokensg;

	strcpy(data.steps, file.file[0]);

	for(i = 2; i < file.lengthfile; i++)
	{
		strcpy(game, file.file[i]);
		strcpy(game, searchAndReplace(game, " ", ""));
		strcpy(game, searchAndReplace(game, "(", ""));
		strcpy(game, searchAndReplace(game, ")", ""));
		tokens = str_split(game, '=', false);
		//strcpy(tmp, *(tokens + 1));
		data.start[i - 2] = string_size_t(*(tokens));
		tokensg = str_split(*(tokens + 1), ',', false);
		data.left[i - 2] = string_size_t(*(tokensg));
		data.right[i - 2] = string_size_t(*(tokensg + 1));
	}
}

size_t string_size_t(char *vstring)
{
	size_t i = 0, number  = 0;
	char game[4096];
	strcpy(game, vstring);
	while(true)
	{
		if(game[i] >= 'A' && game[i] <= 'Z')
			{
				number = 100 * number + (game[i] - 'A' + 1);
			}
			else
			{
				return number;
			}   
		i++;
	}
}

size_t check_steps()
{
	size_t amount = 0, i = 0, j = 0, new_start;
	size_t value_start = string_size_t("AAA");
	size_t value_end = string_size_t("ZZZ");
	while(value_start != data.start[i])
	{
		i++;
	}
	while(true)
	{
		amount++;
		switch(data.steps[j])
		{
			case 'R':
				new_start = data.right[i]; break;
			case 'L':
				new_start = data.left[i]; break;
			default:
				break;
		}
		i = 0;
		while(new_start != data.start[i])
		{
			i++;
		}
		if(data.start[i] == value_end)
		{
			return amount;
		}
		j++;
		if(j == strlen(data.steps))
		{
			j = 0;
		}
	}
}

void fill_data2()
{
	size_t i;
	char game[stringlength];
	char tmp[stringlength];
	char **tokens;
	char **tokensg;

	strcpy(data.steps, file.file[0]);

	for(i = 2; i < file.lengthfile; i++)
	{
		strcpy(game, file.file[i]);
		strcpy(game, searchAndReplace(game, " ", ""));
		strcpy(game, searchAndReplace(game, "(", ""));
		strcpy(game, searchAndReplace(game, ")", ""));
		tokens = str_split(game, '=', false);
		//strcpy(tmp, *(tokens + 1));
		data2.start[i - 2] = string_size_t2(*(tokens));
		tokensg = str_split(*(tokens + 1), ',', false);
		data2.left[i - 2] = string_size_t(*(tokensg));
		data2.right[i - 2] = string_size_t(*(tokensg + 1));
	}
}

size_t string_size_t2(char *vstring)
{
	size_t i = 0, number  = 0;
	char game[4096];
	strcpy(game, vstring);
	number = game[2] - 'A' + 1;
	return number;  
}

size_t check_steps2()
{
	size_t amount = 0, i = 0, j = 0, k = 0, amount_start = 0, new_start;
	size_t value_start = string_size_t2("XXA");
	size_t value_end = string_size_t2("XXZ");
	bool all_on_end;
	while(i < file.lengthfile - 2)
	{
		if(value_start == data2.start[i])
		{
			data2.value[amount_start] = i;
			amount_start++;
		}
		i++;
	}
	while(true)
	{
		amount++;
		all_on_end = true;
		for(k = 0; k < amount_start; k++)
		{
			switch(data.steps[j])
			{
				case 'R':
					data2.new_start[k] = data.right[data2.value[k]]; break;
				case 'L':
					data2.new_start[k] = data.left[data2.value[k]]; break;
				default:
					break;
			}
			data2.value[k] = 0;
			while(data2.new_start[k] != data.start[data2.value[k]])
			{
				data2.value[k]++;
			}
			if(data2.start[data2.value[k]] != value_end)
			{
				all_on_end = false;
			}
		}

		if(all_on_end == true)
		{
			return amount;
		}
		j++;
		if(j >= strlen(data.steps))
		{
			j = 0;
		}
	}
}
