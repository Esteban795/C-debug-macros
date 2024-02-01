// Following macros work on terminals that support ANSI escape codes
#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

# define BOLD				"\033[1m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define YELLOW				"\033[33m"
# define BLUE				"\033[34m"
# define MAGENTA			"\033[35m"
# define CYAN				"\033[36m"
# define WHITE				"\033[37m"
# define ORANGE				"\033[38;5;202m"

#define DEBUG(err,...) fprintf(stderr, BOLD RED "DEBUG: (%s:%d)" RED err"\n",__FILE__,__LINE__ ##__VA_ARGS__)

void intp(int *ptr,size_t len)	{
    size_t i = 0;
    while (i < len) {
        printf("%d\n", ptr[i]); 
        i++;
    }
}

void boolp(bool *ptr, size_t len)	{
    size_t i; i = 0;
    while (i < len) {
        ptr[i] == true ? printf("True\n") : printf("False\n"); 
        i++;
    }
}

void defp(void* ptr,size_t len){
    DEBUG("Defaulting to char as pointer type.");
    size_t i = 0;
    while (i < len) {
        printf("%p\n", ptr + i); 
        i++;
    }
}

#define PRINT_1D(array, size) _Generic((array),int* : intp  ((int  *) array, size),bool	*: boolp ((bool *) array, size),default	 : defp(array, size))
#endif