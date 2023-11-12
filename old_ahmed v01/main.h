#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * struct specs - to select type of printing
 * @spec: specifier
 * @f: function to print
 */
typedef struct specs
{
	char spec;
	int (*f)(va_list);
} specs;

int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
int print_string(va_list args);
int print_number(va_list args);


#endif
