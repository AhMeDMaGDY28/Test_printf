#include "main.h"
/**
 * print_char - prints char
 * @args: list of arguments
 * Return: num of chars typed
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
