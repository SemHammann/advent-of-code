#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct filecontent
{
    char **file;
    size_t lengthfile;
};

void deel1();
void deel2();
int leesgetal();
int strtoint();

struct filecontent read(const char *files);

int main(void)
{
    const char *filename = "txt/3.test1.txt";
    struct filecontent main = read(filename);
    deel1(main);
    //deel2((struct filecontent deel2);
}

void deel1(struct filecontent deel1)
{
    int resultaat = 0;
    char game[4095];
    
    for(int i = 0; i < deel1.lengthfile; i++)
    {
        if(deel1.file[i] != 0)
        {
            strcpy(game, deel1.file[i]);
            printf("%s", game);
        }
    }
    printf("Deel 1: %d", resultaat);
}

void deel2(struct filecontent deel2)
{
    int resultaat = 0;
    char game[4095];
    
    for(int i = 0; i < deel2.lengthfile; i++)
    {
        if(deel2.file[i] != 0)
        {
            strcpy(game, deel2.file[i]);
            printf("%s", game);
        }
    }
    printf("Deel 2: %d", resultaat);
}

int leesgetal()
{

}

int strtoint(char getal[], size_t i)
{
    int check = 0;
    size_t len = strlen(getal);

    while(i < len)
    {
        if(getal[i] >= '0' && getal[i] <= '9')
        {
            check = 10 * check + (getal[i] - '0');
        }
        else
        {
            return check;
        }
        i++;
    }
    return check;
}






struct filecontent read(const char *files)
{
    FILE *file_ptr;
    char str[4096];
    size_t numlines = 0;
    int maxstrlength = 1;
    size_t i = 0;
    char ch;
    struct filecontent read;

    file_ptr = fopen(files, "r");

    while((ch = fgets(str, 4095, file_ptr) != NULL))
    {
        read.lengthfile++;
    }
    rewind(file_ptr);
    const size_t size = read.lengthfile*sizeof(char*);
    //printf("Size of the array is %llu x %d\n", numlines, maxstrlength);
    char **output = malloc(size);
    for (i = 0; i < read.lengthfile; i++)
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
    read.file = output;
    return read;
}

