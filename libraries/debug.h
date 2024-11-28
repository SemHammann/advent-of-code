//V0.1

#ifndef DEBUG_SEM_H
#define DEBUG_SEM_H

#if !defined(DEBUG) && !defined(_DEBUG)
	#warning "DEBUG or _DEBUG not defined"	
#endif

int debug_print(const char *str, ...);

#endif // DEBUG_SEM_H
