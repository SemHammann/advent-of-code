#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

struct filecontent read(const char *files)
{
    FILE *file_ptr;
    char str[4096] = "0";
    size_t i = 0;
    char ch;
    struct filecontent read;
    read.lengthfile = 0; //doe hier nog iets mee
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