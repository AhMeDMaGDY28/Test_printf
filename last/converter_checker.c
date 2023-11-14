#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/*this file have 3 functions some to convert & to check*/
/**
 * conv - Convert a long integer to a string representation in a given base.
 * @i: The long integer to be converted.
 * @b: The base for the conversion.
 * @flag: Flags for conversion (CONV_LOW_C, CONV_USIGN).
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function converts a long integer (@i) to a
 * string representation in a given base (@b).
 * The conversion is influenced by flags (@flag)
 * that specify whether to use lowercase
 * ('CONV_LOW_C') or uppercase ('CONV_USIGN')
 * letters for hexadecimal representation.
 * The result is stored in a static character
 * array and a pointer to it is returned.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - A pointer to the string representation of the converted long integer.
 */
char *conv(long int i, int b, int flag, facts *factor)
{
	static char *a;
	static char box[50];
	char neg = 0;
	char *p;
	unsigned long j = i;
	(void)factor;

	if (!(flag & CONV_USIGN) && i < 0)
	{
		j = -i;
		neg = '-';
	}
	a = flag & CONV_LOW_C ? "0123456789abcdef" : "0123456789ABCDEF";
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
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function chooses the appropriate printing function
 * based on a specifier character (@s).
 * It retrieves the printing function using the `spec` function
 * and then executes it with the
 * provided variable arguments and formatting information.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The return value of the chosen printing function,
 * or 0 if no matching specifier is found.
 */
int chose_print_fun(char *s, va_list args, facts *factor)
{
	int (*f)(va_list, facts *) = spec(s);

	if (f)
	{
		return (f(args, factor));
	}
	return (0);
}
/**/
/**
 * fact - Initialize a structure containing formatting information.
 * @factor: A pointer to a structure (facts) to be initialized.
 * @args: The va_list containing the variable arguments.
 *
 * Description:
 * This function initializes a structure
 * (@factor) containing formatting information
 * for printing functions. It resets various
 * flags and fields in the structure to
 * their default values, preparing it for formatting
 * variables based on subsequent
 * specifier processing.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return: None
 */
void fact(facts *factor, va_list args)
{
	factor->un_sign = 0;
	factor->plus_f = 0;
	factor->space_f = 0;
	factor->hash_f = 0;
	factor->zero_f = 0;
	factor->minus_f = 0;
	factor->width_p = 0;
	factor->percs = UINT_MAX;
	factor->mod_h = 0;
	factor->mod_l = 0;
	(void)args;
}
