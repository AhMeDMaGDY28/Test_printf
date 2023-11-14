#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**
 * print_segment - Print a segment of a string with specified formatting.
 * @front: Pointer to the beginning of the segment.
 * @end: Pointer to the end of the segment.
 * @out: Pointer to the character to be excluded from printing (optional).
 *
 * Description:
 * This function prints a segment of a string, excluding a specific character
 * indicated by the @out pointer, with specified formatting.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_segment(char *front, char *end, char *out)
{
	int len = 0;

	while (front <= end)
	{
		if (front != out)
			len += _putchar(*front);
		front++;
	}
	return (len);
}
/**/
/**
 * print_rever - Print a reversed string with specified formatting.
 * @args: The va_list containing the string to be reversed and printed.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a reversed string from
 * the va_list (@args) with specified formatting.
 * The formatting is controlled by
 * the structure pointed to by @factor, which may include
 * width, precision, and other flags.
 * The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_rever(va_list args, facts *factor)
{
	int len = 0, strlen = 0;
	char *a = va_arg(args, char *);
	(void)factor;

	if (a)
	{
		while (a[strlen])
		{
			strlen++;
		}
		strlen--;
		while (strlen >= 0)
		{
			len += _putchar(a[strlen]);
			strlen--;
		}
	}
	return (len);
}
/**/
/**
 * print_rot13 - Print a string with ROT13 encryption.
 * @args: The va_list containing the string to be ROT13 encrypted and printed.
 * @factor: A pointer to a structure containing formatting
 * information (unused).
 *
 * Description:
 * This function prints a string with ROT13
 * encryption from the va_list (@args).
 * ROT13 is a simple letter substitution cipher
 * that replaces a letter with the 13th
 * letter after it in the alphabet.
 *  The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_rot13(va_list args, facts *factor)
{
	char *a = va_arg(args, char *);
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int d, e, len = 0;

	UNUSED(factor);
	for (d = 0; a[d] != '\0'; d++)
	{
		e = 0;
		while (e < 52)
		{
			if (a[d] == b[e])
			{
				a[d] = c[e];
				break;
			}
			e++;
		}
	}
	while (*a)
	{
		len += _putchar(*a);
	}
	return (len);
}
/**/
/**
 * print_adrs - Print the address from a va_list in hexadecimal format.
 * @args: The va_list containing the address to be printed.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints the address from the va_list
 * (@args) in hexadecimal format.
 * The formatting is controlled by the structure pointed
 * to by @factor, which may include
 * width, precision, and other flags.
 * The function returns the number of characters printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
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
