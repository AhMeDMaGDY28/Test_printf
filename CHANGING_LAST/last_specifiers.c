#include "printf_header.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**
 * print_segment - prints a range of chars
 * @front: first char
 * @end: last char
 * @out: non - printed part
 * Return: num of bytes printed
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
 * print_rever - prints array from right to left
 * @args: argument including the string
 * @factor: struct factor
 * Return: num of bytes printed
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
 * print_rot13 - prints array in rot13 format
 * @args: arguments to get array
 * @factor: struct factor
 * Return: return num of bytes printed
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
