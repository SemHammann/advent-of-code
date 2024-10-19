#ifndef __MYCODE_H__
#define __MYCODE_H__

struct filecontent
{
    char **file;
    size_t lengthfile;
};

extern char **read(const char *filename);
extern int lenfile(const char *filename);

#endif