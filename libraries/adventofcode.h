//5.1

#ifndef ADVENTOFCODE_BLOEM_H
#define ADVENTOFCODE_BLOEM_H

#ifndef __GNUC__
	#warning "I haven't tested for this compiler"
#endif /* __GNUC__ */

#include <stdbool.h>

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
    size_t amountlines;
	size_t *lengthlines;
};

struct filecontent file;

//char path_until_now[256];


extern struct filecontent readfile(const char *filename);
extern void fix_file(char *argv[], const char *whichfile);
extern char *make_file_name(char *argv[]);
extern void make_file(char *argv[], char filen[]);
extern void make_debug_file(char *argv[], char **string, char *filename);
extern void make_directory(const char *name);
extern char *fix_path_until_now(char *argv[]);

extern long long unsigned str_to_llu(char *vstring);
extern long long str_ll(char *vstring);
extern char **str_split(char* a_str, const char a_delim, bool doublechar);
extern char *searchAndReplace(char *text, char *search, char *replace);


#endif //ADVENTOFCODE_SEM_H