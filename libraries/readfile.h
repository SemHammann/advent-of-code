#ifndef __MYCODE_H__
#define __MYCODE_H__

struct filecontent
{
    char **file;
    size_t lengthfile, maxlengthfile;
};

struct filecontent read(const char *filename);

#endif