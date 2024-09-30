
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read();
int deel1();
int deel2();

int main (void)
{
    deel1();
}

int deel1(void)
{
    int r;

    // Defining file pointer and opening the file.
    FILE *file_ptr;
    char str[50];

    // a+ Mode Means that the file is opened in the
    // append + reading mode
    file_ptr = fopen("1.txt", "r"); //put here the file name you need to open

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

      // Reading stinrg using fgets
    printf("Deel1\n");
    while (fgets(str, 50, file_ptr) != NULL) {
        r = r + read(str);
        //printf("%d ", read(str));
        //printf("%d\n", r);
    }

    fclose(file_ptr);
    printf ("%d", r);
    return 0;
}

int read(const char *vstring)
{
    int a = -1, b, i, t;
    char *end;
    for(i = 0; i < strlen(vstring); i++)
    { 
        t = (int)vstring[i] - '0';       
        if(t >= 0 && t <= 9)
        {
            //printf("%d %c ", t, vstring[i]);
            if(a == -1) //if a is already read, just override b, else override both
            {
                a = t;
                b = t;
            }
            else
            {
                b = t;
            }
        }
    }
    if(a == -1)
    {
        return 0;
    }
    else
    {
        return (10*a + b); //return a als the first number and b as the second
    }
}