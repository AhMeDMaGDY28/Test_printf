#include "main.h"

int _printf(const char *format, ...)
{
	int x = 0, i = 0;
	va_list args;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				x += _putchar(va_arg(args, int));
				i++;
				break;
			case 's':
				x += print_string(args);
				i++;
				break;
			case 'd':
			case 'i':
				x += print_number(args);
				i++;
				break;
			case '%':
				_putchar('%');
				x++;
				break;
			default:
				break;
			}
		}
		else
		{
			_putchar(format[i]);
			x++;
		}
		i++;
	}

	va_end(args);
	return (x);
}
