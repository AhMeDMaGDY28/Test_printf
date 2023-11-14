#include "main.h"
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
