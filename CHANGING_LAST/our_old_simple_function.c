#include "printf_header.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/*most of the names of old functions changed for kimba*/
/*this file will have our old c files and some simple changes*/
/**
 * _putchar - writes to std output
 * @i: character to be printed
 * Return: 1 if passed -1 if failed
 */
int _putchar(int i)
{
	static int j;
	static char buffer[BUFF_LIMIT];

	if (i == BUFF_FLUSHING || j >= BUFF_LIMIT)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (i != BUFF_FLUSHING)
		buffer[j++] = i;
	return (1);
}
/**
 * _puts - prints a string
 * @s: string to be printed
 * Return: len printed
 */
int _puts(char *s)
{
	char *f = s;

	while (*s)
	{
		_putchar(*s++);
	}
	return (s - f);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be determined
 * Return: length of string
 */
int _strlen(char *s)
{
	int b;

	for (b = 0; *s != '\0'; s++)
	++b;
	return (b);
}
/**
 * _isdigit - function that checks for a digit
 * @c: char to check
 * Return: 1 if c is a digit otherwise 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
