//V5.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#if defined(WIN32) || defined(_WIN32) 
	#include <direct.h>
#else
	#include <sys/stat.h>
#endif

#include "adventofcode.h"


struct filecontent readfile(const char *files)
{
	FILE *file_ptr;
	struct filecontent readfile;
	file_ptr = fopen(files, "r");
	assert(!(file_ptr == NULL));
	char str[4096];
	char buffer[4096];
	char *tmp;
	readfile.amountlines = 1;
	size_t current_buffer_count = 0, max_buffer_count = 0;
	size_t current_line = 0;

	while(true)
	{
		size_t res = fread(buffer, 1, 4096, file_ptr);
		assert(!(ferror(file_ptr)));
		for(size_t i = 0; i < res; i++)
			if(buffer[i] == '\n')
				readfile.amountlines++;
		
		if(feof(file_ptr))
			break;
	}

	rewind(file_ptr);
	readfile.file = (char**)calloc(readfile.amountlines + 1, sizeof(char*));
	readfile.lengthlines = (size_t*)calloc(readfile.amountlines, sizeof(size_t));
	tmp = (char*)calloc(4096, sizeof(char));

	assert(!(readfile.file == NULL));
	assert(!(readfile.lengthlines == NULL));
	assert(!(tmp == NULL));

	while(fgets(str, 4096, file_ptr) != NULL)
	{
		if((str[strlen(str) - 1]) != '\n')
		{
			if(current_buffer_count > max_buffer_count)
			{
				tmp = (char*)realloc(tmp, 4096 * (current_buffer_count + 1) * sizeof(char));
				assert(!(tmp == NULL));
			}
			current_buffer_count++;
			strcat(tmp, str);
		}
		else
		{
			str[strlen(str) - 1] = 0;
			max_buffer_count = __max(max_buffer_count, current_buffer_count);
			strcat(tmp, str);
			*(readfile.file + current_line) = (char*)malloc(strlen(tmp) * sizeof(char));
			assert(!(*(readfile.file + current_line) == NULL));
			readfile.lengthlines[current_line] = strlen(tmp);
			strcpy(*(readfile.file + current_line), tmp);
			memset(tmp, 0, 4096 * (max_buffer_count + 1) * sizeof(char));
			current_buffer_count = 0;
			current_line++;
		}	
	}
	*(readfile.file + current_line) = (char*)malloc(strlen(tmp) * sizeof(char));
	readfile.lengthlines[current_line] = strlen(tmp);
	assert(!(*(readfile.file + current_line) == NULL));
	strcpy(*(readfile.file + current_line), tmp);

	return readfile;
}

void fix_file(char *argv[], const char *whichfile)
{	
	char filenametest1[256];
	char filenametest2[256];
	char filenamemain[256];
	char path_until_now[256];

	strcpy(path_until_now, fix_path_until_now(argv));

	char *filename = make_file_name(argv);
	char directory[256];
	sprintf(directory, "%stxt", path_until_now);
	make_directory(directory);

	sprintf(filenametest1, "%stxt%c%s.test1.txt", path_until_now, PATH_SEPARATOR, filename);
	sprintf(filenametest2, "%stxt%c%s.test2.txt", path_until_now, PATH_SEPARATOR, filename);
	sprintf(filenamemain, "%stxt%c%s.txt", path_until_now, PATH_SEPARATOR, filename);
	
	make_file(argv, filenametest1);
	make_file(argv, filenametest2);
	make_file(argv, filenamemain);

	if(whichfile == "T1")
	{
		printf("\nReading form \"%s\"\n", filenametest1);
		file = readfile(filenametest1);
	}
	else if(whichfile == "T2")
	{
		printf("\nReading form \"%s\"\n", filenametest2);
		file = readfile(filenametest2);
	}
	else if(whichfile == "M")
	{
		printf("\nReading form \"%s\"\n", filenamemain);
		file = readfile(filenamemain);
	}
	else
	{
		assert(false && "Not a valid input");
	}
}


char *make_file_name(char *argv[])
{
	char argvfile[FIX_FILE_STR_LENGTH];
	char **tokens;
	long long unsigned j = 0;
	strcpy(argvfile, argv[0]);
	tokens = str_split(argvfile, PATH_SEPARATOR, false);

	assert(!(strlen(argv[0]) > FIX_FILE_STR_LENGTH));
	
	while(*(tokens + j) != NULL)
	{
		j++;
	}
	j--;
	tokens = str_split(*(tokens + j), '.', true);

	return *tokens;
}



void make_file(char *argv[], char filen[])
{
	FILE *file_ptr;
	
	file_ptr = fopen(filen, "r");
	if(file_ptr == NULL)
	{
		file_ptr = fopen(filen, "w");
		if(file_ptr != NULL)
		{
			printf("Made file \"%s\"\n", filen);
		}
		else
		{
			printf("Can not make file \"%s\"\n", filen);
		}
	}
	fclose(file_ptr);
}

void make_debug_file(char *argv[], char **string, char *filename)
{
	FILE *file_ptr;
	unsigned long long i = 0;
	char filename_debug[256];
	char path_until_now[256];
	strcpy(path_until_now, fix_path_until_now(argv));
	char debug_dir[256];
	sprintf(debug_dir, "%sdebug", path_until_now);
	make_directory(debug_dir);
	sprintf(filename_debug, "%s%c%s.txt", debug_dir, PATH_SEPARATOR, filename);
	file_ptr = fopen(filename_debug, "w");
	if(file_ptr != NULL)
	{
		while(*(string + i) != NULL)
		{
			fprintf(file_ptr, "%s\n", *(string + i));
			i++;
		}
		printf("\nMade debug file \"%s\"\n", filename_debug);
	}
	else
	{
		printf("failed to make a debugfile\n");
	}
}

void make_directory(const char *name)
{
	int number;
	#if defined(WIN32) || defined(_WIN32) 
    number = _mkdir(name);
	#else
    number = mkdir(name, 0777);
	#endif
	if(number == 0)
	{
		printf("\nMade directory \"%s\"\n", name);
	}
}

char *fix_path_until_now(char *argv[])
{
	char filename_with_executable[256];
	char *filename = make_file_name(argv);
	char *path_until_now;
	path_until_now = (char*)calloc(256, sizeof(char));

	#if defined(WIN32) || defined(_WIN32)
		sprintf(filename_with_executable, "%s%s", filename, ".exe");
	#else
		sprintf(filename_with_executable, "%s", filename);
	#endif

	size_t last_separator;
	for(size_t i = 0; i < strlen(*argv); i++)
	{
		if(argv[0][i] == PATH_SEPARATOR)
			last_separator = i;
	}
	strncpy(path_until_now, *argv, last_separator + 1);
	return path_until_now;
}


long long unsigned str_to_llu(char *vstring)
{
	long long unsigned i = 0, number  = 0;
	char game[4096];
	strcpy(game, vstring);
	while(true)
	{
		if(game[i] >= '0' && game[i] <= '9')
			{
				number = 10 * number + (game[i] - '0');
			}
			else
			{
				return number;
			}   
		i++;
	}
}

long long str_ll(char *vstring)
{
	int i = 0;
	long long number = 0;
	char game[4096];
	bool negative = false;
	strcpy(game, vstring);
	while(true)
	{
		if(game[i] == '-')
		{
			negative = true;
			i++;
		}
		if(game[i] >= '0' && game[i] <= '9')
			{
				number = 10 * number + (game[i] - '0');
			}
			else if(negative == true)
			{
				return (number * -1);
			}  
			else
			{
				return number;
			} 
		i++;
	}
}

char** str_split(char* a_str, const char a_delim, bool doublechar) 
{
	char** result    = 0;
	long long unsigned count     = 0;
	char* tmp        = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	while (*tmp)
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	count += last_comma < (a_str + strlen(a_str) - 1);

	count++;

	result = (char**)malloc(sizeof(char*) * count);

	if(result)
	{
		long long unsigned idx  = 0;
		char *token = strtok(a_str, delim);

		while(token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		if(doublechar == true)
			assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

char *searchAndReplace(char *text, char *search, char *replace)
{
	char buffer[4095];
	char *ptr;
	char *modText = NULL;

	buffer[0] ='\0';
	while ( ptr = strstr(text, search) )
	{
		strncat(buffer, text, ptr - text);
		strcat(buffer, replace);

		text = ptr + strlen(search);
	}
	strcat(buffer, text);

	modText = (char*)malloc(strlen(buffer) + 1);
	strcpy(modText, buffer);
	return modText;
}

