//V5.0

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
	char str[4096+2] = "0";
	long long unsigned i = 0;
	char ch;
	struct filecontent read;
	read.lengthfile = 0;
	read.maxlengthfile = 1;

	file_ptr = fopen(files, "r");
	assert(!(file_ptr == NULL));

	while((ch = fgets(str, (4095+2), file_ptr) != NULL))
	{
		read.lengthfile++;
		read.maxlengthfile = __max(read.maxlengthfile, strlen(str));
		assert(read.maxlengthfile + 1 <= 4096);
	}
	rewind(file_ptr);
	const long long unsigned size = read.lengthfile*sizeof(char*);
	char **output = calloc(read.lengthfile + 1, sizeof(char*));
	assert(output != NULL);
	for(i = 0; i < read.lengthfile; i++)
	{
		output[i] = (char*)calloc((read.maxlengthfile + 1), sizeof(char));
		assert(output[i] != NULL);
		*output[i];
	}

	i = 0;
	while(fgets(str, 4095, file_ptr) != NULL)
	{
		strcpy(str, searchAndReplace(str, "\n", ""));
		strcpy(output[i], str);
		i++;
	}
	fclose(file_ptr);
	read.file = output;
	return read;
}

void fix_file(char *argv[], const char *whichfile)
{	
	char filenametest1[256];
	char filenametest2[256];
	char filenamemain[256];

	fix_path_until_now(argv);

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
	fix_path_until_now(argv);
	char debug_dir[256];
	sprintf(debug_dir, "%s%c%s", path_until_now, PATH_SEPARATOR, filename);
	make_directory(debug_dir);
	sprintf(filename_debug, "debug%c%s.txt", PATH_SEPARATOR, filename);
	file_ptr = fopen(filename_debug, "w");
	if(file_ptr != NULL)
	{
		while(*(string + i) != NULL)
		{
			fprintf(file_ptr, "%s\n", *(string + i));
			i++;
		}
		printf("Made debug file \"%s\"\n", filename_debug);
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

void fix_path_until_now(char *argv[])
{
	char filename_with_executable[256];
	char *filename = make_file_name(argv);

	#if defined(WIN32) || defined(_WIN32)
		sprintf(filename_with_executable, "%s%s", filename, ".exe");
	#else
		sprintf(filename_with_executable, "%s", filename);
	#endif


	path_until_now = searchAndReplace(*argv, filename_with_executable, "");
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

	result = malloc(sizeof(char*) * count);

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
	char buffer[1000];
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

	modText = malloc(strlen(buffer) + 1);
	strcpy(modText, buffer);
	return modText;
}

