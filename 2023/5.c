//I'm going to clean up this code before really starting with the 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "..\libraries\adventofcode.c"

#define arraysize 128

/*struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};*/
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

void part1();
void part2();

size_t strtoarray();
size_t strtoint();
struct number structstrtoint();


int main(void)
{
    clock_t begin = clock();
    const char *filename = "txt/5.test1.txt";
    struct filecontent main = readfile(filename);
    struct mapdata maindata;
    size_t amountnumbers = 1;
    size_t i = 0, j = 0;
    char game[4096] = "0";
    char tmp[4096] = "0";
    char **tokens;
    char **tokensg;
    strcpy(game, main.file[0]);
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
    part1(main);
    clock_t end1 = clock();
    printf("\n%lfms\n\n", (double)(end1 - begin1));
    part2(main);
    clock_t end2 = clock();
    printf("\n%lfms", (double)(end2 - end1));
    printf("%d", sizeof(main));
}

void part1(struct filecontent part1)
{

}

void part2(struct filecontent part2)
{
    
}

size_t strtoarray(char *vstring)
{ 
    size_t i = 0;
    struct number strtoarray;

    strcpy(strtoarray.str, vstring);
    strtoarray.place = 1;
    while(strtoarray.place < strlen(strtoarray.str))
    {
        strtoarray = structstrtoint(strtoarray);
        strtoarray.numberstring[i] = strtoarray.number;
        strtoarray.place = strtoarray.place + strtoarray.size + 1;
        i++;
    }
    while(i < arraysize)
    {
        strtoarray.numberstring[i] = 0;
        i++;
    }
    return *strtoarray.numberstring;
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

struct number structstrtoint(struct number strint)
{
    size_t number = 0;
    size_t i = strint.place;
    char numberstr[4096];
    strint.size = 0;
    strcpy(numberstr, strint.str);
    while(true)
    {
        if(numberstr[i] >= '0' && numberstr[i] <= '9')
            {
                number = 10 * number + (numberstr[i] - '0');
            }
            else
            {
                strint.number = number;
                return strint;
            }
        strint.size++;    
        i++;
    }
    return strint;
}
