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

//to high 102360389


void part1();
void part2();

long long all_multiply();
long long all_multiply2();

bool enabled = true;

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
	for(size_t i = 0; i < file.amountlines; i++)
	{
		answer += all_multiply(file.file[i]);
	}

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;
	for(size_t i = 0; i < file.amountlines; i++)
	{
		answer += all_multiply2(file.file[i]);
	}

	printf("Part 2: %lld", answer);
}

long long all_multiply(char *vstring)
{
	char *game;
	char *current;
	long long first, second, answer = 0;
	game = searchAndReplace(vstring, "*", "_");
	game = searchAndReplace(game, "mul", "*");
	current = game;
	while(current <= game + strlen(game))
	{
		if(*current == '*')
		{
			current++;
			if(*(current++) == '(')
			{
				first = str_ll(current);
				while(*(current) >= '0' && *(current) <= '9')
					current++;
				if(*(current++) == ',')
				{
					second = str_ll(current);
					while(*(current) >= '0' && *(current) <= '9')
					current++;
					if(*(current++) == ')')
					{
						answer += first * second;
					}
				}
				
			}
		}
		else
			current++;
	}
	return answer;
}

long long all_multiply2(char *vstring)
{
	
	char *game;
	char *current;
	long long first, second, answer = 0;
	game = searchAndReplace(vstring, "*", "_");
	game = searchAndReplace(game, "mul", "*");
	game = searchAndReplace(game, "X", "_");
	game = searchAndReplace(game, "Y", "_");
	game = searchAndReplace(game, "do()", "Y");
	game = searchAndReplace(game, "don't()", "X");
	current = game;
	while(current <= game + strlen(game))
	{
		if(enabled)
		{
			if(*current == 'X')
			{
				enabled = false;
				current++;
			}
			else if(*current == '*')
			{
				current++;
				if(*(current++) == '(')
				{
					first = str_ll(current);
					while(*(current) >= '0' && *(current) <= '9')
						current++;
					if(*(current++) == ',')
					{
						second = str_ll(current);
						while(*(current) >= '0' && *(current) <= '9')
						current++;
						if(*(current++) == ')')
						{
							answer += first * second;
						}
					}
					
				}
			}
			else
				current++;
		}
		else
		{
			if(*current == 'Y')
				enabled = true;
			current++;
		}
	}
	return answer;
}