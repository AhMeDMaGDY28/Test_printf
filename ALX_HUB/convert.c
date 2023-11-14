#include "main.h"
/**
 * conv - translates int to chars
 * @i: int to be converted
 * @b: base of int
 * @flag: arguments flags
 * @factor: struct factor
 * Return: translated string
 */
char *conv(long int i, int b, int flag, facts *factor)
{
	static char *a;
	static char box[50];
	char neg = 0;
	char *p;
	unsigned long j = i;
	(void)factor;

	if (!(flag & CONV_USIGN) && i < 0)
	{
		j = -i;
		neg = '-';
	}
	a = flag & CONV_LOW_C ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &box[49];
	*p = '\0';
	do {
		*--p = a[j % b];
		j /= b;
	} while (j != 0);
	if (neg)
	{
		*--p = neg;
	}
	return (p);
}
/**
 * print_unsign - prints unsigned ints
 * @args: arguments
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_unsign(va_list args, facts *factor)
{
	unsigned long z;

	if (factor->mod_l)
	{
		z = (unsigned long)va_arg(args, unsigned long);
	}
	else if (factor->mod_h)
	{
		z = (unsigned short int)va_arg(args, unsigned int);
	}
	else
	{
		z = (unsigned int)va_arg(args, unsigned int);
	}
	factor->un_sign = 1;
	return (print_no(conv(z, 10, CONV_USIGN, factor), factor));
}
/**
 * print_adrs - prints address
 * @args: arguments
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_adrs(va_list args, facts *factor)
{
	unsigned long int m = va_arg(args, unsigned long int);
	char *s;

	if (!m)
		return (_puts("(nil)"));
	s = conv(m, 16, CONV_USIGN | CONV_LOW_C, factor);
	*--s = 'x';
	*--s = '0';
	return (print_no(s, factor));
}
