#include "main.h"
/**
 * _printf - prints to std output
 * @format: specifiers for formatted output.
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	char *o, *front;
	facts factor = FACTORS_N;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	for (o = (char *)format; *o; o++)
	{
		fact(&factor, args);
		if (*o != '%')
		{
			len += _putchar(*o);
			continue;
		}
		front = o;
		o++;
		while (flags(o, &factor))
		{
			o++;
		}
		o = width(o, &factor, args);
		o = perc(o, &factor, args);
		if (mods(o, &factor))
			o++;
		if (!spec(o))
			len += print_segment(front, o, factor.mod_l || factor.mod_h ? o - 1 : 0);
		else
			len += chose_print_fun(o, args, &factor);
	}
	_putchar(BUFF_FLUSHING);
	va_end(args);
	return (len);
}
