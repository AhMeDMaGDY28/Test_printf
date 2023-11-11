#include "main.h"
char *_puts(char *string)
{
    int i, b;
    b = _strlen(string);
    for (i = 0; i < b; i++)
    {
        putchar(string[i]);
    }
    return (string);
}

/**
 * _strlen - Computes the length of a string.
 *
 * @s: A pointer to a string.
 *
 * Description: This function calculates the length
 * of the string pointed to by @s.
 *
 * Return: The length of the string (number of characters).
 *
 * Author: Ahmed Magdy
 * School: ALX CO 1 BLENDED
 */
int _strlen(char *s)
{
    int length = 0;

    while (s[length] != '\0')
    {
        length++;
    }

    return (length);
}
