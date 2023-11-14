#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/

/**
 * print_ch - Print a character with specified formatting.
 * @args: The va_list containing the character to be printed.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a character from the va_list
 * (@args) with specified formatting.
 * The formatting is controlled by the structure
 * pointed to by @factor, which may include
 * width and alignment information.
 * The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
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
 * print_string - Print a string with specified formatting.
 * @args: The va_list containing the string to be printed.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a string from the va_list
 * (@args) with specified formatting.
 * The formatting is controlled by the structure pointed
 * to by @factor, which may include
 * width, precision, and alignment information.
 * The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
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
 * print_percent - Print a percent symbol with specified formatting.
 * @args: The va_list (unused in this case).
 * @factor: A pointer to a structure containing formatting
 * information (unused in this case).
 *
 * Description:
 * This function prints a percent symbol with specified formatting.
 * The formatting information is not used in this function.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed (1 in this case).
 */
int print_percent(va_list args, facts *factor)
{
	UNUSED(args);
	UNUSED(factor);
	return (_putchar('%'));
}

/**
 * print_num - Print a number with specified formatting.
 * @args: The va_list containing the number to be printed.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a number from the va_list (@args)
 * with specified formatting.
 * The formatting is controlled by the
 * structure pointed to by @factor, which may include
 * width, precision, and other flags.
 * The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
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
 * print_unsign - Print an unsigned number with specified formatting.
 * @args: The va_list containing the unsigned number to be printed.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints an unsigned number from
 * the va_list (@args) with specified formatting.
 * The formatting is controlled by the structure
 * pointed to by @factor, which may include
 * width, precision, and other flags.
 * The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
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
