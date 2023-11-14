#include "printf_header.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/*this file have 3 functions some to convert & to check*/
/**
 * conv - translates int to chars
 * @i: int to be converted
 * @b: base of int
 * @flag: arguments flags
 * @factor: struct factor
 * Return: translated string
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
/**/
/**
 * chose_print_fun - selects the appropriate func
 * @s: character checked
 * @args: arguments
 * @factor: factors struct
 * Return: num of bytes printed
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
 * fact - to scan for factors
 * @factor: list of factors
 * @args: to compare with input
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
