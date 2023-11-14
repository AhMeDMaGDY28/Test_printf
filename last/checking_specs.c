#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/

/*A format specifier follows this prototype:*/
/*%[flags][width][.precision][length]specifier*/

/*1-first the flags*/

/**
 * flags - Process and set formatting flags based on a character.
 * @s: The character representing a formatting flag.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function processes and sets formatting flags based on a character (@s).
 * It updates the formatting information stored in the
 * structure pointed to by @factor.
 * Supported flags include '+' for always print a sign,
 * ' ' for print a space if no sign,
 * '#' for alternate form, '-' for left-justify, and '0' for zero-pad.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - 1 if the flag is successfully set, 0 otherwise.
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
/*2-second the width*/
/**
 * width - Process and set the width formatting based on a string.
 * @s: The string representing the width value.
 * @factor: A pointer to a structure containing formatting information.
 * @args: The va_list containing the variable arguments.
 *
 * Description:
 * This function processes and sets the width
 * formatting based on a string (@s).
 * It updates the formatting information stored in
 * the structure pointed to by @factor.
 * If the string begins with '*', it retrieves the width
 * value from the variable
 * arguments using va_arg. Otherwise, it parses the string
 * for a numerical width value.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - A pointer to the next character after processing
 * the width information in the string.
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
		for (; _isdigit(*s); s++)
		{
			k = k * 10 + (*s - '0');
		}
	}
	factor->width_p = k;
	return (s);
}
/*3- the percision*/
/**
 * perc - Process and set the precision formatting based on a string.
 * @o: The string representing the precision value.
 * @factor: A pointer to a structure containing formatting information.
 * @args: The va_list containing the variable arguments.
 *
 * Description:
 * This function processes and sets the precision
 * formatting based on a string (@o).
 * It updates the formatting information stored in the
 * structure pointed to by @factor.
 * If the string begins with '.', it retrieves the precision
 * value from the variable
 * arguments using va_arg. Otherwise, it parses the string
 * for a numerical precision value.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - A pointer to the next character after processing the
 * precision information in the string.
 */
char *perc(char *o, facts *factor, va_list args)
{
	int r = 0;

	if (*o != '.')
		return (o);
	o++;
	if (*o == '*')
	{
		r = va_arg(args, int);
		o++;
	}
	else
	{
		for (; _isdigit(*o); o++)
			r = r * 10 + (*o - '0');
	}
	factor->percs = r;
	return (o);
}
/*4- the length*/
/**
 * mods - Process and set length modifiers based on a character.
 * @s: The character representing a length modifier.
 * @factor: A pointer to a structure containing formatting information.
 *
 * Description:
 * This function processes and sets length modifiers based on a character (@s).
 * It updates the formatting information stored in
 * the structure pointed to by @factor.
 * Supported length modifiers include 'h' for short and 'l' for long.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - 1 if the length modifier is successfully set, 0 otherwise.
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

/*5- the specifier*/

/**
 * spec - Retrieve the appropriate printing function
 * based on a specifier character.
 * @s: The character representing a specifier.
 *
 * Description:
 * This function retrieves the appropriate printing
 * function based on a specifier character (@s).
 * It searches through an array of specifier-
 * function pairs and returns the corresponding
 * printing function for the given specifier.
 * If no matching specifier is found, it returns NULL.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - A pointer to the printing function for the
 * given specifier, or NULL if not found.
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
		{NULL, NULL}};
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
