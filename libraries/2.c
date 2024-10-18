#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include "..\libraries\readfile.h"

void deel1();
//void deel2();
int possible();
int possible2();
char** str_split(char* a_str, const char a_delim);
int strtoint();
size_t custom_strlen(const char* str);

int main(void)
{
    deel1();
    //deel2();
    return 0;
}

void deel1(void)
{
    char game[500];
    char game2[500];
    char** tokens;
    char** tokensg;
    int sum = 0;

    FILE *file_ptr;
    file_ptr = fopen("2.txt", "r"); //put here the file name you need to open
    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }
    else
    {
        printf("File open worked\n");
        while (fgets(game, 500, file_ptr) != NULL)
        {
            //printf("%s\n", game);
            strcpy(game2, game);
        
            tokens = str_split(game2, ':');
            //printf("%s\n", *(tokens));
            //printf("%s\n", *(tokens + 1));

            tokensg = str_split(*tokens, ' ');
            //printf("%s\n", *(tokensg + 1));
            if(possible(*(tokens + 1)) == 1)
            {
                sum = sum + atoi(*(tokensg + 1));
            }

        }
    }
    fclose(file_ptr);
    printf("%d\n", sum);
}

/*void deel2(void)
{
    int sum = 0;
    int j;
    char game[4095];
    char game2[4095];
    const char *filename = "1.txt";
    char **tokens;
    char **tokensg;
    char **lines = read(filename);
    for(j = 0; j < 100; j++)
    {
        printf("%s", lines[j]);
    }
    for(int i = 0; i < lenfile(filename); i++)
    {
        strcpy(game, file[i]);
        strcpy(game2, game);
        tokens = str_split(game2, ':');
        sum = sum + possible2(*(tokens + 1));
    }
}*/

int possible(const char *vstring)
{
    int t = 0;
    for(size_t i = 0; i < strlen(vstring); i++)
    {
        switch(vstring[i])
        {
            case '1':
                switch(vstring[i+3])
                {
                    case 'r':
                        if(vstring[i+1] >= '3')
                            t++;
                        break;
                    case 'g':
                        if(vstring[i+1] >= '4')
                            t++;
                        break;
                    case 'b':
                        if(vstring[i+1] >= '5')
                            t++; 
                        break;
                    default:
                        break;     
                }
                break;
            default:
            {
                if(vstring[i] <= '2' && vstring[i] >= '9')
                {
                    switch(vstring[i+2])
                    {
                        case 'r':
                        case 'g':
                        case 'b':
                            break;
                        default:
                            t++; break;
                    }
                }
            }
        }
    }
    //printf("%d\n", t);
    if(t==0)
        return 1;
    else
        return 0;
}

/*int possible2(const char *vstring)
{
    int prod = 0;
}*/

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
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

int strtoint(char getal[])
{
    size_t i;
    int check = 0;
    size_t len = strlen(getal);

    for (i = 0; i < len; i++)
    {
        if(getal[i] >= '0' && getal[i] <= '9')
        {
            check = 10 * check + (getal[i] - '0');
        }
    }
    return check;
}

/*size_t custom_strlen(const char* str)
{
    size_t len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}*/