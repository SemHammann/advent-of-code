#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct filecontent
{
    char **file;
    size_t lengthfile;
};
struct numberinfo
{
    size_t place, size, number;
};

void part1();
void part2();
int readnumber();
struct numberinfo strtoint();
struct numberinfo check();

struct filecontent read(const char *files);

int main(void)
{
    const char *filename = "txt/3.test1.txt";
    struct filecontent main = read(filename); //deze vindt die niet leuk, KIJK HIERNA ALS JE NIET EEN JAAR WILT WACHTEN
    part1(main);
    //part2((struct filecontent part2);
}

void part1(struct filecontent part1)
{
    int result = 0;
    int placenumber;
    char game[4095];
    struct numberinfo numberinfo1;
    
    for(int i = 0; i < part1.lengthfile; i++)
    {
        strcpy(game, part1.file[i]);
        printf("%s", game);
        placenumber = readnumber(game);
        if(placenumber <= 0)
        {
            numberinfo1 = strtoint(game, placenumber);
            numberinfo1 = check(numberinfo1, part1);
        }
    }
    printf("part 1: %d", result);
}

void part2(struct filecontent part2)
{
    int result = 0;
    char game[4095];
    
    for(int i = 0; i < part2.lengthfile; i++)
    {
        if(part2.file[i] != 0)
        {
            strcpy(game, part2.file[i]);
            printf("%s", game);
        }
    }
    printf("part 2: %d", result);
}

int readnumber(char game[])
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

struct numberinfo strtoint(char number[], size_t i)
{
    size_t len = strlen(number);
    struct numberinfo strint;
    strint.size = 0;
    strint.number = 0;

    while((strint.size + i) < len)
    {
        if(number[i] >= '0' && number[i] <= '9')
        {
            strint.number = 10 * strint.number + (number[i] - '0');
        }
        else
        {
            return strint;
        }
        strint.size++;
    }
    strint.place = strint.size + i;
    return strint;
}

struct numberinfo check(struct numberinfo checknumber, struct filecontent checkfile)
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
        checknumber.number = 0;
    }
    return checknumber;
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

