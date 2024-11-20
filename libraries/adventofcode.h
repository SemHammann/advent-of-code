//V4.0

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


size_t strtoint();
char **str_split(char* a_str, const char a_delim, bool doublechar);
char *searchAndReplace(char *text, char *search, char *replace);
struct filecontent readfile(const char *filename);
void fix_file();
void make_files();

#endif //ADVENTOFCODE_SEM_H