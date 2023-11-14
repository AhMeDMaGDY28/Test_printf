#include "main.h"
/**
 * _isdigit - function that checks for a digit
 * @c: char to check
 * Return: 1 if c is a digit otherwise 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * _strlen - returns the length of a string
 * @s: string to be determined
 * Return: length of string
 */
int _strlen(char *s)
{
	int b;

	for (b = 0; *s != '\0'; s++)
	++b;
	return (b);
}
/**
 * print_no - prints num
 * @s: num as string
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_no(char *s, facts *factor)
{
	unsigned int y = _strlen(s);
	int sign = (!factor->un_sign && *s == '-');

	if (!factor->percs && *s == '0' && !s[1])
		s = "";
	if (sign)
	{
		s++;
		y--;
	}
	if (factor->percs != UINT_MAX)
	{
		while (y++ < factor->percs)
		{
			*--s = '0';
		}
	}
	if (sign)
	{
		*--s = '-';
	}
	if (!factor->minus_f)
	{
		return (print_no_right_justified(s, factor));
	}
	else
	{
		return (print_no_left_justified(s, factor));
	}
}
/**
 * print_no_right_justified - prints num to right
 * @s: num as string
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_no_right_justified(char *s, facts *factor)
{
	unsigned int len = 0, sign_a, sign_b, l = _strlen(s);
	char pad = ' ';

	if (factor->zero_f && !factor->minus_f)
		pad = '0';
	sign_a = sign_b = (!factor->un_sign && *s == '-');
	if (sign_a && l < factor->width_p && pad == '0' && !factor->minus_f)
		s++;
	else
		sign_a = 0;
	if ((factor->plus_f && !sign_b) ||
	(!factor->plus_f && factor->space_f && !sign_b))
		l++;
	if (sign_a && pad == '0')
		len += _putchar('-');
	if (factor->plus_f && !sign_b && pad == '0' && !factor->un_sign)
		len += _putchar('+');
	else if (!factor->plus_f && factor->space_f && !sign_b &&
		!factor->un_sign && factor->zero_f)
		len += _putchar(' ');
	while (l++ < factor->width_p)
		len += _putchar(pad);
	if (sign_a && pad == ' ')
		len += _putchar('-');
	if (factor->plus_f && !sign_b && pad == ' ' && !factor->un_sign)
		len += _putchar('+');
	else if (!factor->plus_f && factor->space_f &&
		!sign_b && !factor->un_sign && !factor->zero_f)
		len += _putchar(' ');
	len += _puts(s);
	return (len);
}
/**
 * print_no_left_justified - prints num to right
 * @s: num as string
 * @factor: struct factor
 * Return: num of bytes printed
 */
int print_no_left_justified(char *s, facts *factor)
{
	unsigned int len = 0, sign_a, sign_b, l = _strlen(s);
	char pad = ' ';

	if (factor->zero_f && !factor->minus_f)
		pad = '0';
	sign_a = sign_b = (!factor->un_sign && *s == '-');
	if (sign_a && l < factor->width_p && pad == '0' && !factor->minus_f)
		s++;
	else
		sign_a = 0;
	if (factor->plus_f && !sign_b && !factor->un_sign)
		len += _putchar('+'), l++;
	else if (factor->space_f && !sign_b && !factor->un_sign)
		len += _putchar(' '), l++;
	len += _puts(s);
	while (l++ < factor->width_p)
		len += _putchar(pad);
	return (len);
}
