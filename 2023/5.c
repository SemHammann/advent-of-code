//I'm going to clean up this code before really starting with the 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

#define arraysize 128

struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};
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

char** str_split(char* a_str, const char a_delim);
char *searchAndReplace(char *text, char *search, char *replace);
struct filecontent read(const char *files);
size_t max();

int main(void)
{
    clock_t begin = clock();
    const char *filename = "txt/5.test1.txt";
    struct filecontent main = read(filename);
    struct mapdata maindata;
    size_t amountnumbers = 1;
    size_t i = 0;
    char game[4096] = "0";
    char tmp[4096] = "0";
    char **tokens;
    char **tokensg;
    strcpy(game, main.file[0]);
    tokens = str_split(game, ':');
    strcpy(tmp, *(tokens + 1));
    tmp[0] = '0';
    while(tmp[i] != '\0')
    {
        if(tmp[i] == ' ')
            amountnumbers++;
        i++;
    }
    tokensg = str_split(tmp, ' ');
    for(size_t j = 0; j < amountnumbers; j++)
    {
        strcpy(tmp, *(tokensg + j));
        maindata.seeds[j] = strtoint(tmp);
    }
    clock_t begin1 = clock();
    printf("\nThings for 1 and 2: %lfms\n\n", (double)(begin1 - begin));
    part1(main);
    clock_t end1 = clock();
    printf("\n%lfms\n\n", (double)(end1 - begin1));
    part2(main);
    clock_t end2 = clock();
    printf("\n%lfms", (double)(end2 - end1));
    printf("E");
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









char** str_split(char* a_str, const char a_delim) 
{
    //zorg ervoor dat als de 1e in de string is waarop je splitst, die niet breekt, en dubbele enzo

    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    /*char a_delim2[2] = "0";

    for(size_t i = 0; i < strlen(a_str); i++)
    {
        if(a_str[i] == a_delim)
        {
            if(a_str[i] == a_delim)
            {
                a_delim2[0] = *a_str;
                a_delim2[1] = *a_str;
                searchAndReplace(a_str[i], str(*a_str, *a_str), a_str[i]);
                i = 0;
            }
        }
    }*/

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if(result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

char *searchAndReplace(char *text, char *search, char *replace)
{
   char buffer[1000];
   char *ptr;
   char *modText = NULL;

   buffer[0] ='\0';
   while ( ptr = strstr(text, search) )
   {
      strncat(buffer, text, ptr - text);
      strcat(buffer, replace);

      text = ptr + strlen(search);
   }
   strcat(buffer, text);

   modText = malloc(strlen(buffer) + 1);
   strcpy(modText, buffer);
   return modText;
}

struct filecontent read(const char *files)
{
    FILE *file_ptr;
    char str[4096] = "0";
    size_t i = 0;
    char ch;
    struct filecontent read;
    read.lengthfile = 0;
    read.maxlengthfile = 1;

    file_ptr = fopen(files, "r");
    assert(!(NULL == file_ptr) && "File can't be opened");

    while((ch = fgets(str, 4095, file_ptr) != NULL))
    {
        read.lengthfile++;
        read.maxlengthfile = max(read.maxlengthfile, strlen(str));
    }
    rewind(file_ptr);
    const size_t size = read.lengthfile*sizeof(char*);
    char **output = malloc(size);
    for(i = 0; i < read.lengthfile; i++)
    {
        output[i] = (char*)malloc(4096 * sizeof(char));
        *output[i] = 0;
    }

    i = 0;
    while(fgets(str, 4095, file_ptr) != NULL)
    {
        strcpy(output[i], str);
        i++;
    }
    fclose(file_ptr);
    read.file = output;
    return read;
}

size_t max(size_t a, size_t b)
{
    if(a > b)
        return a;
    else
        return b;
}