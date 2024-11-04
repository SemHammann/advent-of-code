#ifndef __MYCODE_H__
#define __MYCODE_H__

struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};

char** str_split(char* a_str, const char a_delim, bool doublechar);
char *searchAndReplace(char *text, char *search, char *replace);
struct filecontent readfile(const char *filename);
size_t max(size_t a, size_t b);
size_t min(size_t a, size_t b);


#endif