//5.0

#ifndef ADVENTOFCODE_BLOEM_H
#define ADVENTOFCODE_BLOEM_H

#ifndef __GNUC__
	#warning "I haven't tested for this compiler"
#endif /* __GNUC__ */

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

char *path_until_now;


struct filecontent readfile(const char *filename);
void fix_file(char *argv[], const char *whichfile);
char *make_file_name(char *argv[]);
void make_file(char *argv[], char filen[]);
void make_debug_file(char *argv[], char **string, char *filename);
void make_directory(const char *name);
void fix_path_until_now(char *argv[]);

long long unsigned str_to_llu(char *vstring);
long long str_ll(char *vstring);
char **str_split(char* a_str, const char a_delim, bool doublechar);
char *searchAndReplace(char *text, char *search, char *replace);


#endif //ADVENTOFCODE_SEM_H