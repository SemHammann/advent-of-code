#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "..\libraries\adventofcode.c"

#define arraysize 128

struct mapdata
{
	size_t seeds[arraysize];
	size_t seed_soil[arraysize];
	size_t soil_fertilizer[arraysize];
	size_t fertilizer_water[arraysize];
	size_t water_light[arraysize];
	size_t light_temperature[arraysize];
	size_t temperature_humidity[arraysize];
	size_t humidity_location[arraysize];
};
struct number
{
	size_t number, size, place;
	char *str;
	size_t *numberstring;
};

struct filecontent file;

void part1();
void part2();

size_t strtoint();



int main(void)
{
	clock_t begin = clock();
	const char *filename = "txt/5.test1.txt";
	struct filecontent file = readfile(filename);
	struct mapdata maindata;
	size_t amountnumbers = 1;
	size_t i = 0, j = 0;
	char game[4096];
	char tmp[4096];
	char **tokens;
	char **tokensg;
	memset(maindata.seeds, 0, sizeof(maindata.seeds));

	strcpy(game, file.file[0]);
	tokens = str_split(game, ':', false);
	strcpy(tmp, *(tokens + 1));
	tmp[0] = '0';
	tokensg = str_split(tmp, ' ', false);
	while(NULL != *(tokensg + j))
	{
		strcpy(tmp, *(tokensg + j));
		maindata.seeds[j] = strtoint(tmp);
		j++;
	}
	clock_t begin1 = clock();
	printf("\nThings for 1 and 2: %lfms\n\n", (double)(begin1 - begin));
	part1();
	clock_t end1 = clock();
	printf("\n%lfms\n\n", (double)(end1 - begin1));
	part2();
	clock_t end2 = clock();
	printf("\n%lfms", (double)(end2 - end1));
	printf("%d", sizeof(main));
}

void part1()
{

}

void part2()
{

}


size_t strtoint(char *vstring)
{
	size_t i = 0, number  = 0;
	char game[4096];
	strcpy(game, vstring);
	while(true)
	{
		if(game[i] >= '0' && game[i] <= '9')
			{
				number = 10 * number + (game[i] - '0');
			}
			else
			{
				return number;
			}   
		i++;
	}
}

