#include "readfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **read(const char *files)
{
    // Defining file pointer and opening the file.
    FILE *file_ptr;
    char str[4096]; // '\0''
    int numlines = 0;
    int maxstrlength = 1;
    int i = 0;
    char ch;
    
    file_ptr = fopen(files, "r");

    while((ch = fgets(str, 4095, file_ptr) != NULL))
    {
        numlines++;
    }
    rewind(file_ptr);
    const int size = numlines*sizeof(char*);
    printf("Size of the array is %d x %d\n", numlines, maxstrlength);
    char **output = malloc(size);
    for (i = 0; i < numlines; i++)
    {
        output[i] = (char*)malloc(4096 * sizeof(char));
        *output[i] = 0;
    }
    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }
    else
    {
        printf("File open worked\n");
        i = 0;
    }
    while (fgets(str, 4095, file_ptr) != NULL) {
        strcpy(output[i], str);
        i++;
    }
    fclose(file_ptr);
    return output;
}

/*int main(void)
{
    int j;
    const char *filename = "1.txt";
    char **lines = read(filename);
    for(j = 0; j < 100; j++)
    {
        printf("%s", lines[j]);
    }
}*/