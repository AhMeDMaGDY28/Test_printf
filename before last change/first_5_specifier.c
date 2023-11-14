#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/

/**
 * print_ch - Print a character with specified formatting.
 * @args: The va_list containing the character to be printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_ch(va_list args)
{
	unsigned int c = va_arg(args, int);

	return (_putchar(c));
}
/**/
/**
 * print_string - Print a string with specified formatting.
 * @args: The va_list containing the string to be printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	unsigned int len = 0;

	if ((int)(!s))
	{
		s = "(null)";
	}
	len += _puts(s);
	return (len);
}

/**
 * print_percent - Print a percent symbol with specified formatting.
 * @args: The va_list (unused in this case).
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed (1 in this case).
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_num - Print a number with specified formatting.
 * @args: The va_list containing the number to be printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_num(va_list args)
{
	int h;

	h = (int)va_arg(args, int);
	return (print_no(conv(h, 10, 0)));
}

/**
 * print_unsign - Print an unsigned number with specified formatting.
 * @args: The va_list containing the unsigned number to be printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_unsign(va_list args)
{
	unsigned int z;

	z = (unsigned int)va_arg(args, unsigned int);
	return (print_no(conv(z, 10, 0)));
}
