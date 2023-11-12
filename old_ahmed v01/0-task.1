#include "main.1.h"
/**
 * print_char - prints char
 * @args: list of arguments
 * Return: num of chars typed
 */
int print_char(va_list args)
{
	int len;
	char buffer[1];

	buffer[0] = va_arg(args, int);
	len = write(1, buffer, 1);
	return (len);
}
/**
 * print_string - prints string
 * @args: list of arguments
 * Return: num of chars typed
 */
int print_string(va_list args)
{
	int len;
	int b;
	char *s = va_arg(args, char *);

	for (b = 0; *s != '\0'; s++)
	{
		b++;
	}
	len = write(1, s, b);
	return (len);
}
/**
 * _printf - prints to std output
 * @format: specifiers for formatted output.
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int len, count1 = 0, count2 = 0;
	specs specifier[] = {
	{'c', print_char},
	{'s', print_string},
	{'\0', NULL},
	};
	va_list args;

	va_start(args, format);
here:
	while (format[count1] != '\0')
	{
		if (format[count1] == '%')
		{
			count2 = 0;
			while (specifier[count2].spec != '\0')
			{
				if (format[count1 + 1] == specifier[count2].spec)
				{
					len += specifier[count2].f(args);
					count1 += 2;
					goto here;
				}
				count2++;
			}
		}
		putchar(format[count1]);
		count1++;
	}
	return (len);
}
