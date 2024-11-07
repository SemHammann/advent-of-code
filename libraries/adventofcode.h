//V3.1

#ifndef ADVENTOFCODE_SEM_H
#define ADVENTOFCODE_SEM_H

struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};

struct filecontent file;

size_t strtoint();
char** str_split(char* a_str, const char a_delim, bool doublechar);
char *searchAndReplace(char *text, char *search, char *replace);
struct filecontent readfile(const char *filename);

#endif