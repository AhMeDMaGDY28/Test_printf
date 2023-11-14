#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**
 * _printf - Custom printf function that formats and prints output.
 * @format: A string containing the format specifications.
 *
 * Description:
 * This function mimics the behavior of
 * the standard printf function but with some limitations.
 * It supports the following format specifiers:
 *   - %c: character
 *   - %s: string
 *   - %d: decimal (integer)
 *   - %i: integer
 *   - %u: unsigned integer
 *   - %o: octal
 *   - %x: lowercase hexadecimal
 *   - %X: uppercase hexadecimal
 *   - %%: percent sign
 *   - %b: binary
 *   - %S: string with non-printable characters replaced by hexadecimal
 *   - %r: reverse the string
 *   - %R: encode a string using ROT13
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The number of characters printed
 * (excluding the null byte used to end output to strings).
 * - Returns -1 on error.
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	char *o = (char *)format;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	while (*o)
	{
		if (*o != '%')
		{
			len += _putchar(*o);
			continue;
		}
		len += chose_print_fun(o, args);
	}

	_putchar(-1);
	va_end(args);
	return (len);
}
