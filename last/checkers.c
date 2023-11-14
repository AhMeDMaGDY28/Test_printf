#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/

/**
 * print_no - Print a number with specified formatting.
 * @s: The string representation of the number.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a number with specified
 * formatting based on the provided
 * factors. It takes a string representation of
 * the number (@s) and a pointer to
 * a structure (@factor) that contains information
 * about the formatting, such as
 * whether to include a sign, leading zeros, and justification. It adjusts the
 * formatting and calls the appropriate helper function for printing.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The total number of characters printed.
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
		for (; y++ < factor->percs;)
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
 * print_no_right_justified - Print a right-justified
 * number with specified formatting.
 * @s: The string representation of the number.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a right-justified number
 * with specified formatting based on
 * the provided factors. It takes a string representation
 * of the number (@s) and a
 * pointer to a structure (@factor) that contains
 * information about the formatting,
 * such as whether to include a sign, leading zeros, and width. It adjusts the
 * formatting and prints the number accordingly.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The total number of characters printed.
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
	for (; l++ < factor->width_p;)
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
 * print_no_left_justified - Print a left-justified
 * number with specified formatting.
 * @s: The string representation of the number.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function prints a left-justified number
 * with specified formatting based onthe provided factors.
 * It takes a string representation of the number (@s) and a
 * pointer to a structure (@factor) that contains
 *  information about the formatting,such as whether to include a sign,
 * leading zeros, and width. It adjusts the
 * formatting and prints the number accordingly.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The total number of characters printed.
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
	for (; l++ < factor->width_p;)
		len += _putchar(pad);
	return (len);
}
