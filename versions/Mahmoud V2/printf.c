#include "main.h"
/**
 * _printf - prints to std output
 * @format: specifiers for formatted output.
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int len = 0, ct1 = 0, ct2 = 0, flag;
	specs sp[] = {
	{"%c", print_char}, {"%s", print_string}, {"%%", print_percent},
	{"%d", print_number}, {"%i", print_number}, {NULL, NULL},
	};
	va_list args;

	va_start(args, format);
	while (format[ct1] && format)
	{
		flag = 1;
		ct2 = 0;
		while (sp[ct2].spec != NULL)
		{
			if (format[ct1] == sp[ct2].spec[0] && format[ct1 + 1] == sp[ct2].spec[1])
			{
				len += sp[ct2].f(args);
				ct1 += 2;
				flag *= -1;
			}
			if (flag > 0)
			{
				ct2++;
			}
			else
			{
				break;
			}
		}
		if (flag > 0)
		{
			_putchar(format[ct1]);
			ct1++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
