#include "printf_header.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**/
/**
 * print_ch - prints char
 * @args: argument
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_ch(va_list args, facts *factor)
{
	char pad = ' ';
	unsigned int n_pad = 1, len = 0, c = va_arg(args, int);

	if (factor->minus_f)
		len += _putchar(c);
	while (n_pad++ < factor->width_p)
		len += _putchar(pad);
	if (!factor->minus_f)
		len += _putchar(c);
	return (len);
}
/**/
/**
 * print_string - prints string
 * @args: argument
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_string(va_list args, facts *factor)
{
	char *s = va_arg(args, char *), pad = ' ';
	unsigned int n_pad = 0, len = 0, a = 0, b;

	UNUSED(factor);
	switch ((int)(!s))
		case 1:
			s = NULL_STRING;
	b = n_pad = _strlen(s);
	if (factor->percs < n_pad)
		b = n_pad = factor->percs;
	if (factor->minus_f)
	{
		if (factor->percs != UINT_MAX)
			for (a = 0; a < n_pad; a++)
				len += _putchar(*s++);
		else
			len += _puts(s);
	}
	while (b++ < factor->width_p)
		len += _putchar(pad);
	if (!factor->minus_f)
	{
		if (factor->percs != UINT_MAX)
			for (a = 0; a < n_pad; a++)
				len += _putchar(*s++);
		else
			len += _puts(s);
	}
	return (len);
}
/**/
/**
 * print_percent - prints percent
 * @args: argument
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_percent(va_list args, facts *factor)
{
	UNUSED(args);
	UNUSED(factor);
	return (_putchar('%'));
}
/**/
/**
 * print_num - prints ints
 * @args: argument
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_num(va_list args, facts *factor)
{
	long h;

	if (factor->mod_l)
		h = va_arg(args, long);
	else if (factor->mod_h)
		h = (short int)va_arg(args, int);
	else
		h = (int)va_arg(args, int);
	return (print_no(conv(h, 10, 0, factor), factor));
}
/**/
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
