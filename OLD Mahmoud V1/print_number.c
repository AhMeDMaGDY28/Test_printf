#include "main.h"
/**
 * print_number - prints number
 * @args: args
 * Return: num of chars typed
 */
int print_number(va_list args)
{
	unsigned int k, m;
	int h = va_arg(args, int), b = 0;

	if (h == 0)
	{
		_putchar('0');
	}
	else
	{
		if (h < 0)
		{
			k = -h;
			_putchar('-');
		}
		else
		{
			k = h;
		}
		m = 1000000000;
		do {
			if (k >= m)
			{
				_putchar((k / m % 10) + '0');
			}
			m /= 10;
			b++;
		} while (m != 0);
	}
	return (b);
}
