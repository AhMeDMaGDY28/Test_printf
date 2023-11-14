#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**/
/**
 * print_bi - Print a binary number.
 * @args: The va_list containing the binary number to print.
 * @factor: A pointer to a facts structure containing formatting information.
 *
 * Description:
 * This function prints a binary number from the
 * va_list with optional formatting.
 * If the number is zero and the hash flag is set,
 * it will print '0' as the prefix.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
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
/**/
/**
 * print_octs - Print an octal number.
 * @args: The va_list containing the octal number to print.
 * @factor: A pointer to a facts structure containing formatting information.
 *
 * Description:
 * This function prints an octal number from the va_list
 * with optional formatting.
 * If the number is non-zero and the hash flag
 * is set, it will print '0' as the prefix.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
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
/**/
/**
 * print_low_hexes - Print a lowercase hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 * @factor: A pointer to a facts structure containing formatting information.
 *
 * Description:
 * This function prints a lowercase hexadecimal number
 * from the va_list with optional formatting.
 * If the number is non-zero and the hash flag is set,
 * it will print '0x' as the prefix.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
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
/**/

/**
 * print_up_hexes - Print an uppercase hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 * @factor: A pointer to a facts structure containing formatting information.
 *
 * Description:
 * This function prints an uppercase hexadecimal number
 * from the va_list with optional formatting.
 * If the number is non-zero and the hash flag is set,
 * it will print '0X' as the prefix.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
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
/**/

/**
 * print_stringhex - Print a string with non-printable characters
 * replaced by hexadecimal representation.
 * @args: The va_list containing the string to print.
 * @factor: A pointer to a facts structure containing formatting information.
 *
 * Description:
 * This function prints a string with non-printable characters
 * replaced by their hexadecimal representation.
 * Non-printable characters are replaced with
 * '\x' followed by the ASCII value in hexadecimal.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
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
