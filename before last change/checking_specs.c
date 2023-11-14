#include "main.h"
/*- the specifier*/
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
int (*spec(char *s))(va_list args)
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
