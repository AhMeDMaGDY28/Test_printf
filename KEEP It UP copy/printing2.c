#include "main.h"
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
/**
 * print_stringhex - prints string and \x for non-printable
 * @args: argument
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_stringhex(va_list args, facts *factor)
{
	char *s = va_arg(args, char *);
	char *hexes;
	int len = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			hexes = conv(*s, 16, 0, factor);
			if (!hexes[1])
				len += _putchar('0');
			len += _puts(hexes);
		}
		else
		{
			len += _putchar(*s);
		}
	}
	return (len);
}
