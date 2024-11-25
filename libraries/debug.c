//V0.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>

#include "../libraries/debug.h"

int debug_print(const char *str, ...)
{
	#if defined(DEBUG) || defined(_DEBUG)
	va_list ptr;
	va_start(ptr, str);

	char token[1000];
	int k = 0;
	//token = calloc(1000, sizeof(char));

	for(int i = 0; str[i] != '\0'; i++)
	{
		token[k++] = str[i];
		if(str[i + 1] == '%' || str[i + 1] == '\0')
		{
			token[k] = '\0';
			k = 0;
			if(token[0] != '%')
			{
				fprintf(stdout, "%s", token);
			}
			else
			{
				int j = 1;
				char ch1 = 0;
				while((ch1 = token[j++]) > 58)
				{
					if(ch1 == 'i' || ch1 == 'd' || ch1 == 'u' || ch1 == 'h')
					{
						fprintf(stdout, token, va_arg(ptr, int));
					}
					else if(ch1 == 'c')
					{
						fprintf(stdout, token, va_arg(ptr, int));
					}
					else if(ch1 == 'f')
					{
						fprintf(stdout, token, va_arg(ptr, double));
					}
					else if(ch1 == 'l')
					{
						char ch2 = token[2];
						if(ch2 == 'u' || ch2 == 'd' || ch2 == 'i')
						{
							fprintf(stdout, token, va_arg(ptr, long));
						}
						else if(ch2 == 'f')
						{
							fprintf(stdout, token, va_arg(ptr, double));
						}
						else if(ch2 == 'l')
						{
							char ch3 = token[3];
							if(ch3 == 'u' || ch2 == 'd' || ch2 == 'i')
							{
								fprintf(stdout, token, va_arg(ptr, long long));
							}
							if(ch3 == 'f')
							{
								fprintf(stdout, token, va_arg(ptr, long double));
							}
						}
					}
					else if(ch1 == 's')
					{
						fprintf(stdout, token, va_arg(ptr, char*));
					}
					else
					{
						fprintf(stdout, "%s", token);
					}
				}
			}
		}
	}
	#endif
	return 0;
}