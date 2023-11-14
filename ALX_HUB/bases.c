#include "main.h"
/**
 * print_low_hexes - prints hexes in low
 * @args: arguments
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_low_hexes(va_list args, facts *factor)
{
	unsigned long h;
	int len = 0;
	char *s;

	if (factor->mod_l)
		h = (unsigned long)va_arg(args, unsigned long);
	else if (factor->mod_h)
		h = (unsigned short int)va_arg(args, unsigned int);
	else
		h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 16, CONV_USIGN | CONV_LOW_C, factor);
	if (factor->hash_f && h)
	{
		*--s = 'x';
		*--s = '0';
	}
	factor->un_sign = 1;
	return (len += print_no(s, factor));
}
/**
 * print_up_hexes - prints hexes in up
 * @args: arguments
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_up_hexes(va_list args, facts *factor)
{
	unsigned long h;
	int len = 0;
	char *s;

	if (factor->mod_l)
		h = (unsigned long)va_arg(args, unsigned long);
	else if (factor->mod_h)
		h = (unsigned short int)va_arg(args, unsigned int);
	else
		h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 16, CONV_USIGN, factor);
	if (factor->hash_f && h)
	{
		*--s = 'X';
		*--s = '0';
	}
	factor->un_sign = 1;
	return (len += print_no(s, factor));
}
/**
 * print_bi - prints binary
 * @args: arguments
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_bi(va_list args, facts *factor)
{
	unsigned int m = va_arg(args, unsigned int);
	char *s = conv(m, 2, CONV_USIGN, factor);
	int len = 0;

	if (factor->hash_f && m)
		*--s = '0';
	factor->un_sign = 1;
	return (len += print_no(s, factor));
}
/**
 * print_octs - prints octals
 * @args: arguments
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_octs(va_list args, facts *factor)
{
	unsigned long h;
	int len = 0;
	char *s;

	if (factor->mod_l)
		h = (unsigned long)va_arg(args, unsigned long);
	else if (factor->mod_h)
		h = (unsigned short int)va_arg(args, unsigned int);
	else
		h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 8, CONV_USIGN, factor);
	if (factor->hash_f && h)
		*--s = '0';
	factor->un_sign = 1;
	return (len += print_no(s, factor));
}
