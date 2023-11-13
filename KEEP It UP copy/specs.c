#include "main.h"
/**
 * spec - pointer to func required
 * @s: character checked
 * Return: num of bytes printed
 */
int (*spec(char *s))(va_list args, facts *factor)
{
	specs specses[] = {
		{"c", print_ch},
		{"d", print_num},
		{"i", print_num},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_bi},
		{"o", print_octs},
		{"u", print_unsign},
		{"x", print_low_hexes},
		{"X", print_up_hexes},
		{"p", print_adrs},
		{"S", print_stringhex},
		{"r", print_rever},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int g = 0;

	while (specses[g].sp)
	{
		if (*s == specses[g].sp[0])
		{
			return (specses[g].f);
		}
		g++;
	}
	return (NULL);
}
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
/**
 * flags - checks for flags
 * @s: charaters checked
 * @factor: factors sturct
 * Return: return for valid flags
 */
int flags(char *s, facts *factor)
{
	int r = 0;

	switch (*s)
	{
		case '+':
			r = factor->plus_f = 1;
			break;
		case ' ':
			r = factor->space_f = 1;
			break;
		case '#':
			r = factor->hash_f = 1;
			break;
		case '-':
			r = factor->minus_f = 1;
			break;
		case '0':
			r = factor->zero_f = 1;
			break;
	}
	return (r);
}
/**
 * mods - gets valid modifiers
 * @s: character checked
 * @factor: struct factor
 * Return: 1 if valid modifier
 */
int mods(char *s, facts *factor)
{
	int r = 0;

	switch (*s)
	{
		case 'h':
			r = factor->mod_h = 1;
			break;
		case 'l':
			r = factor->mod_l = 1;
			break;
	}
	return (r);
}
/**
 * width - gets valid width
 * @s: charachters to be checked
 * @factor: struct factor
 * @args: arguments to get width
 * Return: pointer for next char
 */
char *width(char *s, facts *factor, va_list args)
{
	int k = 0;

	if (*s == '*')
	{
		k = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
		{
			k = k * 10 + (*s++ - '0');
		}
	}
	factor->width_p = k;
	return (s);
}
