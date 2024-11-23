//V4.3

#ifndef ADVENTOFCODE_SEM_H
#define ADVENTOFCODE_SEM_H

#if defined(WIN32) || defined(_WIN32) 
    #define PATH_SEPARATOR '\\' 
#else 
    #define PATH_SEPARATOR '/'
    #define __max(a,b) (((a) > (b)) ? (a) : (b))
    #define __min(a,b) (((a) < (b)) ? (a) : (b))
#endif 

#ifndef FIX_FILE_STR_LENGTH
    #define FIX_FILE_STR_LENGTH 256
#endif

struct filecontent
{
    char **file;
    long long unsigned lengthfile, maxlengthfile;
};

struct filecontent file;

char filename[99];
char filename_debug[99];
char filenametest1[99];
char filenametest2[99];
char filenamemain[99];

struct filecontent readfile(const char *filename);
void fix_file(char *argv[]);
void make_file_names(char *argv[]);
void make_file(char file[]);
void make_debug_file();
long long unsigned strtoint(char *vstring);
char **str_split(char* a_str, const char a_delim, bool doublechar);
char *searchAndReplace(char *text, char *search, char *replace);


#endif //ADVENTOFCODE_SEM_H