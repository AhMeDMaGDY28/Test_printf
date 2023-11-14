#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**/
/**
 * print_bi - Print a binary number.
 * @args: The va_list containing the binary number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_bi(va_list args)
{
	unsigned int m = va_arg(args, unsigned int);
	char *s = conv(m, 2, 0);
	int len = 0;

	return (len += print_no(s));
}
/**/
/**
 * print_octs - Print an octal number.
 * @args: The va_list containing the octal number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_octs(va_list args)
{
	unsigned int h;
	int len = 0;
	char *s;

	h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 8, 0);
	return (len += print_no(s));
}
/**/
/**
 * print_low_hexes - Print a lowercase hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_low_hexes(va_list args)
{
	unsigned int h;
	int len = 0;
	char *s;

	h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 16, 1);
	return (len += print_no(s));
}
/**/

/**
 * print_up_hexes - Print an uppercase hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_up_hexes(va_list args)
{
	unsigned int h;
	int len = 0;
	char *s;

	h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 16, 0);
	return (len += print_no(s));
}
/**/

/**
 * print_stringhex - Print a string with non-printable characters
 * replaced by hexadecimal representation.
 * @args: The va_list containing the string to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_stringhex(va_list args)
{
	char *s = va_arg(args, char *);
	char *hexes;
	int len = 0;

	if ((int)(!s))
		return (_puts("(null)"));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			hexes = conv(*s, 16, 0);
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
