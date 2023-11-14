#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/*most of the names of old functions changed for kimba*/
/*this file will have our old c files and some simple changes*/
/**
 * _putchar - Write a character to the standard output.
 * @i: The character to be written, or BUFF_FLUSHING to flush the buffer.
 *
 * Description:
 * This function writes a character to the standard output. If the character is
 * BUFF_FLUSHING or the buffer is full,
 * the function flushes the buffer and writes
 * its contents to the standard output.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns 1 on success.
 */
int _putchar(int i)
{
	static int j;
	static char buffer[1024];

	if (i == -1 || j >= 1024)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (i != -1)
		buffer[j++] = i;
	return (1);
}
/**
 * _puts - Write a string to the standard output.
 * @s: The string to be written.
 *
 * Description:
 * This function writes a string to the standard output,
 * character by character.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters written.
 */
int _puts(char *s)
{
	char *f = s;

	while (*s)
	{
		_putchar(*s++);
	}
	return (s - f);
}
/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 *
 * Description:
 * This function calculates the length of a string by counting each character
 * until the null terminator is encountered.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the length of the string.
 */
int _strlen(char *s)
{
	int b;

	for (b = 0; *s != '\0'; s++)
	++b;
	return (b);
}
/**
 * _isdigit - Check if a character is a digit.
 * @c: The character to be checked.
 *
 * Description:
 * This function checks whether the given character is a digit (0-9).
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
