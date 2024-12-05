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


struct Data
{
	long long **page_order;
	long long **pages;
	size_t start_pages;
	size_t amount_pages;
	size_t *amount_pages_line;
};

struct Data data;
struct Data data2;

void part1();
void part2();

void fill_data();
long long check_possible();
long long correct_order();
void swap();

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	
	fix_file(argv, "M");

	fill_data();
	data2 = data;


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

	for(size_t i = 0; i < data.amount_pages; i++)
	{
		answer += check_possible(i);
	}

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	for(size_t i = 0; i < data.amount_pages; i++)
	{
		if(check_possible(i) == 0)
		{
			answer += correct_order(i);
		}
	}

	printf("Part 2: %lld", answer);
}

void fill_data()
{
	size_t i = 0, k;
	char **tokens;
	char **tokens2;
	char game[10];
	while(file.lengthlines[i] != 0)
		i++;
	
	data.page_order = calloc(i, sizeof(long long*));
	for(size_t j = 0; j < i; j++)
	{
		strcpy(game, file.file[j]);
		tokens = str_split(game, '|', false);
		*(data.page_order + j) = calloc(2, sizeof(long long));
		*(*(data.page_order + j)) = str_ll(*tokens);
		*(*(data.page_order + j) + 1) = str_ll(*(tokens + 1));
	}
	
	data.start_pages = i + 1;
	data.amount_pages = file.amountlines - data.start_pages;
	data.pages = calloc(data.amount_pages, sizeof(long long*));
	data.amount_pages_line = calloc(data.amount_pages, sizeof(size_t));

	for(size_t j = 0; j < data.amount_pages; j++)
	{
		k = 0;
		tokens = str_split(file.file[j + i + 1], ',', false);
		while(*(tokens + k) != NULL)
			k++;
		*(data.pages + j) = calloc(k, sizeof(long long));
		*(data.amount_pages_line + j) = k;
		for(size_t l = 0; l < k; l++)
		{
			*(*(data.pages + j) + l) = str_ll(*(tokens + l));
		}
	}
}

long long check_possible(size_t which_page)
{
	for(size_t i = 0; i < data.amount_pages_line[which_page]; i++)
	{
		for(size_t j = 0; j < data.start_pages - 1; j++)
		{
			if(data.pages[which_page][i] == data.page_order[j][1])
			{
				for(size_t k = i; k < data.amount_pages_line[which_page]; k++)
				{
					if(data.pages[which_page][k] == data.page_order[j][0])
					{
						return 0;
					}
				}
			}
		}
	}

	return data.pages[which_page][*(data.amount_pages_line + which_page)/2];
}

long long correct_order(size_t which_page)
{
	for(size_t i = 0; i < data2.amount_pages_line[which_page]; i++)
	{
		for(size_t j = 0; j < data2.start_pages - 1; j++)
		{
			if(data2.pages[which_page][i] == data2.page_order[j][1])
			{
				for(size_t k = i; k < data2.amount_pages_line[which_page]; k++)
				{
					if(data2.pages[which_page][k] == data2.page_order[j][0])
					{
						swap(&(data2.pages[which_page][k]), &(data2.pages[which_page][i]));
						i = -1;
						j = 999;
						k = 999;
					}
				}
			}
		}
	}


	return data2.pages[which_page][*(data2.amount_pages_line + which_page)/2];
}

void swap(long long* xp, long long* yp)
{
    long long temp = *xp;
    *xp = *yp;
    *yp = temp;
}