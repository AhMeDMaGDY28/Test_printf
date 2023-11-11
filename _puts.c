#include "main.h"
char *_puts(char *string)
{
    int i, b;
    b = strlen(string);
    for (i = 0; i < b; i++)
    {
        putchar(string[i]);
    }
    return (string);
}