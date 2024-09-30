
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readt();
int deel1();
int deel2();

int main (void)
{
    deel1(); //put deel1 or deel2 here
}

int deel1(void)
{
    int r = 0;
    r = r + readt("treb7uchet");
    printf ("\n%d", r);
}

int readt(const char *vstring)
{
    int a = -1, b, i, t;
    char *end;
    for(i = 0; i < strlen(vstring); i++)
    { 
        t = strtol(&vstring[i], &end, 10);
        if(t + '0' == vstring[i])
        {
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
    return (10*a + b); //return a als the first number and b as the second
}