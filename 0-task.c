#include "main.h"

int _printf(const char *format, ...)
{
	int x = 0, i = 0;
	char *a;
	va_list args;
	va_start(args, format);
here:
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				_putchar(va_arg(args, int));
				x++;
				i += 2;
				goto here;
				break;
			case 's':

				x += strlen(va_arg(args, char *));
				break;
			case 'd':

				x++;
				break;
			case '%':
				putchar('%');
				x++;
				break;
			default:
				break;
			}
		}
		else
		{
			putchar(format[i]);
			x++;
		}
		i++;
	}
	va_end(args);
	return (x);
}
