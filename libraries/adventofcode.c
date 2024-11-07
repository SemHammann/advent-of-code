//V3.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "adventofcode.h"



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

char** str_split(char* a_str, const char a_delim, bool doublechar) 
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

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
        char *token = strtok(a_str, delim);

        while(token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        if(doublechar == true)
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

struct filecontent readfile(const char *files)
{
    FILE *file_ptr;
    char str[4096+2] = "0";
    size_t i = 0;
    char ch;
    struct filecontent read;
    read.lengthfile = 0; //doe hier nog iets mee
    read.maxlengthfile = 1;

    file_ptr = fopen(files, "r");
    assert(!(NULL == file_ptr) && "File can't be opened");

    while((ch = fgets(str, (4095+2), file_ptr) != NULL))
    {
        read.lengthfile++;
        read.maxlengthfile = __max(read.maxlengthfile, strlen(str));
        assert(read.maxlengthfile + 1 <= 4096);
    }
    rewind(file_ptr);
    const size_t size = read.lengthfile*sizeof(char*);
    char **output = malloc(size);
    for(i = 0; i < read.lengthfile; i++)
    {
        output[i] = (char*)malloc((read.maxlengthfile + 1) * sizeof(char));
        *output[i] = 0;
    }

    i = 0;
    while(fgets(str, 4095, file_ptr) != NULL)
    {
        //strcpy(output[i], str);
        output[i] = searchAndReplace(str, "\n", "");
        i++;
    }
    fclose(file_ptr);
    read.file = output;
    return read;
}

