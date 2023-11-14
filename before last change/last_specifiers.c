#include "main.h"
/**/
/**
 * print_rever - Print a reversed string with specified formatting.
 * @args: The va_list containing the string to be reversed and printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_rever(va_list args)
{
	int len = 0, strlen = 0;
	char *s = va_arg(args, char *);
	int l, a;

	while (*(s + strlen) != '\0')
	{
		strlen++;
	}
	l = strlen;
	for (a = l - 1; a >= 0; a--)
	{
		_putchar(*(s + a));
	}
	return (len);
}
/**/
/**
 * print_rot13 - Print a string with ROT13 encryption.
 * @args: The va_list containing the string to be ROT13 encrypted and printed.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed.
 */
int print_rot13(va_list args)
{
	char *a = va_arg(args, char *);
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int d, e, len = 0;

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
