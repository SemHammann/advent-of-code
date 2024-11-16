#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "..\libraries\adventofcode.c"

//#define TEST1

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
	char next[3];
}Position_t;

Position_t start;
Position_t current;

void part1();
void part2();

void search_start();
size_t follow_loop();
void get_new_current();



int main(void)
{
	clock_t begin = clock();
	file = readfile(filename);

	search_start();

	clock_t begin1 = clock();
	printf("\nThings for 1 and 2: %.0lfms\n\n", (double)(begin1 - begin));
	part1();
	clock_t end1 = clock();
	printf("\n%.0lfms\n\n", (double)(end1 - begin1));
	part2();
	clock_t end2 = clock();
	printf("\n%.0lfms", (double)(end2 - end1));
}

void part1()
{
	size_t answer;

	answer = follow_loop() / 2;


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
				get_new_current(start);
				return;
			}
		}
	}
}

size_t follow_loop()
{
	size_t amount_steps = 1;

	while(file.file[current.y][current.x] != 'S' || amount_steps == 1 || (current.x != start.x && current.y != start.y))
	{
		switch(current.next[1])
		{
		case 'U':
			current.y--;
			switch(file.file[current.y][current.x])
			{
				case '|':
					strcpy(current.next, "|U");
					break;
				case '7':
					strcpy(current.next, "7L");
					break;
				case 'F':
					strcpy(current.next, "FR");
					break;
				default:
					break;
				}
			break;
		case 'R':
			current.x++;
			switch(file.file[current.y][current.x])
				{
					case '-':
						strcpy(current.next, "-R");
						break;
					case 'J':
						strcpy(current.next, "JU");
						break;
					case '7':;
						strcpy(current.next, "7D");
						break;
					default:
						break;
				}
			break;
		case 'D':
			current.y++;
			switch(file.file[current.y][current.x])
				{
					case '|':
						strcpy(current.next, "|D");
						break;
					case 'L':
						strcpy(current.next, "LR");
						break;
					case 'J':;
						strcpy(current.next, "JL");
						break;
					default:
						break;
				}

			break;
		case 'L':
			current.x--;
			switch(file.file[current.y][current.x])
				{
					case '-':
						strcpy(current.next, "-L");
						break;
					case 'L':
						strcpy(current.next, "LU");
						break;
					case 'F':
						strcpy(current.next, "FD");
						break;
					default:
						break;
				}
			break;
		default:
			break;
		}
		amount_steps++;
	}

	return amount_steps;
}

void get_new_current(Position_t old)
{
	current = old;
	switch(file.file[old.y - 1][old.x])
	{
		case '|':
			current.y--;
			strcpy(current.next, "|U");
			return;
		case '7':
			current.y--;
			strcpy(current.next, "7L");
			return;
		case 'F':
			current.y--;
			strcpy(current.next, "FR");
			return;
		default:
			break;
	}
	switch(file.file[old.y][old.x + 1])
	{
		case '-':
			current.x++;
			strcpy(current.next, "-R");
			return;
		case 'J':
			current.x++;
			strcpy(current.next, "JU");
			return;
		case '7':
			current.x++;
			strcpy(current.next, "7D");
			return;
		default:
			break;
	}
	switch(file.file[old.y + 1][old.x])
	{
		case '|':
			current.y++;
			strcpy(current.next, "|U");
			return;
		case 'L':
			current.y++;
			strcpy(current.next, "LR");
			return;
		case 'J':
			current.y++;
			strcpy(current.next, "JL");
			return;
		default:
			break;
	}
	switch(file.file[old.y][old.x - 1])
	{
		case '-':
			current.x--;
			strcpy(current.next, "-L");
			return;
		case 'L':
			current.x--;
			strcpy(current.next, "LU");
			return;
		case 'F':
			current.x--;
			strcpy(current.next, "FD");
			return;
		default:
			break;
	}
}