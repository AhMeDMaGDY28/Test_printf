#include "main.h"

int print_string(va_list args)
{
    int b = 0;
    char *s = va_arg(args, char *);

    while (*s != '\0')
    {
        _putchar(*s);
        s++;
        b++;
    }
    return (b);
}

/**
 * _strlen - Computes the length of a string.
 *
 * @s: A pointer to a string.
 *
 * Description: This function calculates the length
 * of the string pointed to by @s.
 *
 * Return: The length of the string (number of characters).
 *
 * Author: Ahmed Magdy
 * School: ALX CO 1 BLENDED
 */
int _strlen(char *s)
{
    int length = 0;

    while (s[length] != '\0')
    {
        length++;
    }

    return (length);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer to the standard output.
 *
 * @n: The integer to be printed.
 *
 * Description: This function takes an
 * integer @n and prints it to the standard output
 * character by character. It handles
 * both positive and negative integers, converting
 * the integer into its individual digits and printing them.
 *
 * Return: No return value (void).
 *
 * Author: Ahmed Magdy
 * School: ALX CO 1 BLENDED
 */

int print_number(va_list args)
{
	unsigned int k, m;
	int h = va_arg(args, int), b = 0;

	if (h == 0)
	{
		_putchar('0');
	}
	else
	{
		if (h < 0)
		{
			k = -h;
			_putchar('-');
		}
		else
		{
			k = h;
		}
		m = 1000000000;
		do {
			if (k >= m)
			{
				_putchar((k / m % 10) + '0');
			}
			m /= 10;
			b++;
		} while (m != 0);
	}
	return (b);
}

int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

