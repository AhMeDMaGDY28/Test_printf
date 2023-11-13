#include "main.h"
/**
 * print_string - prints string
 * @args: list of arguments
 * Return: num of chars typed
 */
int print_string(va_list args)
{
	int b = 0;
	char *s = va_arg(args, char *);

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		b++;
	}
	return (b);
}
