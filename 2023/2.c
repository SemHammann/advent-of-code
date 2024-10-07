#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int deel1();
int deel2();
int possible();
char** str_split(char* a_str, const char a_delim);

int main(void)
{
    deel1();
    //deel2();
}

int deel1(void)
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
        //printf("%d\n", sum);
        //printf("%d", atoi(*(tokensg + 1)));
    }
    fclose(file_ptr);
    printf("%d\n", sum);
}

int deel2(void)
{

}

int possible(const char *vstring)
{
    int t = 0, s;
    for(int i = 0; i < strlen(vstring); i++)
    {
        switch(vstring[i])
        {
            case '1':
                switch(vstring[i+3])
                {
                    case 'r':
                        if(vstring[i+1] >= '3')
                        t++; break;
                    case 'g':
                        if(vstring[i+1] >= '4')
                        t++; break;
                    case 'b':
                        if(vstring[i+1] >= '5')
                        t++; break;
                    default:
                        break;
                }
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
    //printf("%d\n", t);
    if(t==0)
        return 1;
    else
        return 0;
}

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