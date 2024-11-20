//V4.1

#ifndef ADVENTOFCODE_SEM_H
#define ADVENTOFCODE_SEM_H

#if defined(WIN32) || defined(_WIN32) 
    #define PATH_SEPARATOR '\\' 
#else 
    #define PATH_SEPARATOR '/' 
#endif 


struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};

struct filecontent file;

char filename[99];
char filenametest1[99];
char filenametest2[99];
char filenamemain[99];

struct filecontent readfile(const char *filename);
void fix_file(char *argv[]);
void make_file(char file[]);
size_t strtoint(char *vstring);
char **str_split(char* a_str, const char a_delim, bool doublechar);
char *searchAndReplace(char *text, char *search, char *replace);


#endif //ADVENTOFCODE_SEM_H