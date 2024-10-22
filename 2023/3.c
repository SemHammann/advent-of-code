#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


struct filecontent
{
    char **file;
    size_t lengthfile;
};
struct numberinfo
{
    size_t placex, placey, size, number;
    bool possible;
};

void part1();
void part2();
struct numberinfo readnumber();
struct numberinfo strtoint();
struct numberinfo check();
int min();

struct filecontent read(const char *files);

int main(void)
{
    const char *filename = "txt/3.test1.txt";
    struct filecontent main = read(filename);
    part1(main);
    //part2((main);
}

void part1(struct filecontent part1)
{
    int result = 0;
    char game[4095];
    struct numberinfo numberinfo1;
    numberinfo1.possible = true;
    
    for(int i = 0; i < part1.lengthfile; i++)
    {
        numberinfo1.placey = i;
        numberinfo1.placex = 0;
        strcpy(game, part1.file[i]);
        //printf("%s", game);
        do{
            numberinfo1 = readnumber(numberinfo1, part1);
            if(numberinfo1.possible == true)
            {
                numberinfo1 = strtoint(numberinfo1, part1);
                numberinfo1 = check(numberinfo1, part1);
                numberinfo1.placex = numberinfo1.placex + numberinfo1.size;
                printf("E");
                //hier moet nog komen dat die zorgt dat er ook meer dan 1 getal per string kan zijn
            }
            result = result + numberinfo1.number;
        }while(numberinfo1.possible == true);
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
            //printf("%s", game);
        }
    }
    printf("part 2: %d", result);
}

struct numberinfo readnumber(struct numberinfo readnumnum, struct filecontent readnumfile)
{
    size_t j = readnumnum.placey;
    size_t i = readnumnum.placex;
    char game[4095];
    readnumnum.possible = false;
    strcpy(game, readnumfile.file[j]);
    while(i < readnumfile.lengthfile)
    {
        if(game[i] >= '0' && game[i] <= '9')
        {
            readnumnum.possible = true;
            readnumnum.placex = i;
            return readnumnum;
        }
        i++;
    }
    return readnumnum;
}

struct numberinfo strtoint(struct numberinfo strint, struct filecontent strintfile)
{
    strint.size = 0;
    strint.number = 0;
    size_t j = strint.placey;
    size_t i = strint.placex;
    char number[4095];
    strcpy(number, strintfile.file[j]);
    while((strint.size) < 4095)
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
        i++;
    }
    return strint;
}

struct numberinfo check(struct numberinfo checknumber, struct filecontent checkfile)
{
    int possible = 0;
    size_t i, j, k;
    if(checknumber.placex >= 1)
        i = checknumber.placex - 1;
    else 
        i = checknumber.placex;
    if(checknumber.placey >= 1)
        j = checknumber.placey - 1;
    else 
        j = checknumber.placey;
    char game[4095];
    strcpy(game, checkfile.file[j]);    
    while(j <= checknumber.placey + 1)
    {
        k = min(j, checkfile.lengthfile - 1);
        strcpy(game, checkfile.file[k]);
        while(i <= (checknumber.placex + checknumber.size))
        {
            if(game[i] >= '!' && game[i] <= '/' && game[i] != '.')
            {
                possible++;
            }
            i++;
        }
        if(checknumber.placex >= 1)
            i = checknumber.placex - 1;
        else 
            i = checknumber.placex;
        j++;
    }

    if(possible == 0)
    {
        checknumber.number = 0;
    }
    return checknumber;
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
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
        //printf("File open worked\n");
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

