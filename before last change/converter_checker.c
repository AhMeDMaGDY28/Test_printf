#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/*this file have 3 functions some to convert & to check*/
/**
 * conv - Convert a long integer to a string representation in a given base.
 * @i: The long integer to be converted.
 * @b: The base for the conversion.
 * @low: True for low unsigned and false for up unsigned.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - A pointer to the string representation of the converted integer.
 */
char *conv(int i, int b, int low)
{
	static char *a;
	static char box[50];
	char neg = 0;
	char *p;
	unsigned int j = i;

	if (i < 0)
	{
		j = -i;
		neg = '-';
	}
	a = "0123456789ABCDEF";
	if (low)
	{
		a = "0123456789abcdef";
	}
	p = &box[49];
	*p = '\0';
	do {
		*--p = a[j % b];
		j /= b;
	} while (j != 0);
	if (neg)
	{
		*--p = neg;
	}
	return (p);
}

/**
 * chose_print_fun - Choose and execute the appropriate
 * printing function based on a specifier.
 * @s: The specifier character.
 * @args: The va_list containing the variable arguments.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The return value of the chosen printing function,
 * or 0 if no matching specifier is found.
 */
int chose_print_fun(char *s, va_list args)
{
	int (*f)(va_list) = spec(s);

	if (f)
	{
		return (f(args));
	}
	return (0);
}
