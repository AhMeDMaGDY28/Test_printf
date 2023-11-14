#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/

/**
 * print_no - Print a number with specified formatting.
 * @s: The string representation of the number.
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The total number of characters printed.
 */
int print_no(char *s)
{
	unsigned int len = 0;

	len += _puts(s);
	return (len);
}
