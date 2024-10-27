#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};
struct numberinfo
{
    size_t winningnumbersarr[128];
    size_t mynumbersarr[128];
    char **card;
    char winningnumbers[4096];
    char mynumbers[4096];
};
struct number
{
    size_t number, size, place;
    char str[4096];
    size_t numberstring[128];
};

void part1();
void part2();

size_t strtoarray();
struct number strtoint();

char *replace(const char *vstring);
char** str_split(char* a_str, const char a_delim);
char *searchAndReplace(char *text, char *search, char *replace);
struct filecontent read(const char *files);
size_t max();

int main(void)
{
    const char *filename = "txt/4.test1.txt";
    struct filecontent main = read(filename);
    //char game[4095] = "0";
    //strcpy(game, main.file[0]);
    //strcpy(game, replace(game));
    part1(main);
    part2(main);
}

void part1(struct filecontent part1)
{
    char game[4095] = "0";
    size_t result = 0;
    struct numberinfo number1;
    char **tokens;
    char **tokensg;
    for(size_t i = 0; i < part1.lengthfile; i++)
    {
        strcpy(game, part1.file[i]);
        strcpy(game, replace(game));
        tokens = str_split(game, ':');
        tokensg = str_split(*(tokens + 1), '|');
        *number1.winningnumbers = *tokensg;
        /*number1.mynumbers = *(tokensg + 1);
        //printf("%s\n%s", number1.winningnumbers, number1.mynumbers);
        *number1.winningnumbersarr = strtoarray(number1.winningnumbers);
        *number1.mynumbersarr = strtoarray(number1.mynumbers);*/
        printf("\n");
    }
}

void part2(struct filecontent part2)
{

}

size_t strtoarray(char *vstring)
{
    size_t str[128] = { 0 };
    size_t *str_p;
    

    struct number strtoarray;
    strcpy(strtoarray.str, vstring);
    strtoarray.place = 1;
    strtoarray = strtoint(strtoarray);
    for(size_t j = 0; j < 128; j++)
    {
        str[j] = strtoarray.numberstring[j];
    }
    printf("%llu\n", str[1]);
    return str;
}

struct number strtoint(struct number strint)
{
    size_t number = 0;
    size_t i = strint.place;
    char numberstr[4096];
    strcpy(numberstr, strint.str);
    while(true)
    {
        if(numberstr[i] >= '0' && numberstr[i] <= '9')
            {
                number = 10 * number + (numberstr[i] - '0');
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




char *replace(const char *vstring)
{
    char output[4095];
    char *output_p = output;

    strcpy(output, vstring);

    output_p = searchAndReplace(output_p, "  ", " ");

    return output_p;
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


char *searchAndReplace(char *text, char *search, char *replace)
{
   char buffer[1000];
   char *ptr;
   char *modText = NULL;

   buffer[0] ='\0';
   while ( ptr = strstr(text, search) )
   {
      strncat(buffer, text, ptr-text);
      strcat(buffer, replace);

      text = ptr + strlen(search);
   }
   strcat(buffer, text);

   modText = malloc(strlen(buffer) + 1);
   strcpy(modText, buffer);
   return modText;
}

struct filecontent read(const char *files)
{
    FILE *file_ptr;
    char str[4096] = "0";
    size_t i = 0;
    char ch;
    struct filecontent read;
    read.lengthfile = 0;
    read.maxlengthfile = 1;

    file_ptr = fopen(files, "r");

    while((ch = fgets(str, 4095, file_ptr) != NULL))
    {
        read.lengthfile++;
        read.maxlengthfile = max(read.maxlengthfile, strlen(str));
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
        //check op "/n" als einde, haal de /n weg
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