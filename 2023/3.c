#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct filecontent
{
    char **file;
    size_t lengthfile;
};
struct getalinfo
{
    size_t plek, grote, getal;
};

void deel1();
void deel2();
int leesgetal();
struct getalinfo strtoint();
struct getalinfo check();

struct filecontent read(const char *files);

int main(void)
{
    const char *filename = "txt/3.test1.txt";
    struct filecontent main = read(filename); //deze vindt die niet leuk, KIJK HIERNA ALS JE NIET EEN JAAR WILT WACHTEN
    deel1(main);
    //deel2((struct filecontent deel2);
}

void deel1(struct filecontent deel1)
{
    int resultaat = 0;
    int plekgetal;
    char game[4095];
    struct getalinfo getalinfo1;
    
    for(int i = 0; i < deel1.lengthfile; i++)
    {
        strcpy(game, deel1.file[i]);
        printf("%s", game);
        plekgetal = leesgetal(game);
        if(plekgetal <= 0)
        {
            getalinfo1 = strtoint(game, plekgetal);
            getalinfo1 = check(getalinfo1, deel1);
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

int leesgetal(char game[])
{
    for(size_t i = 0; i > strlen(game); i++)
    {
        if(game[i] >= '0' && game[i] <= '9')
        {
            return i;
        }
    }
    return -1;
}

struct getalinfo strtoint(char getal[], size_t i)
{
    size_t len = strlen(getal);
    struct getalinfo strint;
    strint.grote = 0;
    strint.getal = 0;

    while((strint.grote + i) < len)
    {
        if(getal[i] >= '0' && getal[i] <= '9')
        {
            strint.getal = 10 * strint.getal + (getal[i] - '0');
        }
        else
        {
            return strint;
        }
        strint.grote++;
    }
    strint.plek = strint.grote + i;
    return strint;
}

struct getalinfo check(struct getalinfo checkgetal, struct filecontent checkfile)
{
    int possible;
    size_t i=0, j;
    char game[4095];
    strcpy(game, checkfile.file[i]);
    if(game[i] >= '!' && game[i] <= '/' && game[i] != '.')
    {
        possible++;
    }

    if(possible == 0)
    {
        checkgetal.getal = 0;
    }
    return checkgetal;
}



struct filecontent read(const char *files)
{
    FILE *file_ptr;
    char str[4096];
    int maxstrlength = 1;
    size_t i = 0;
    char ch;
    struct filecontent read;
    read.lengthfile = 0;

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

