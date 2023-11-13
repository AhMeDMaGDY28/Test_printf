#include "main.h"
/**
 * perc - gets valid percision
 * @o: format array
 * @factor: struct factor
 * @args: arguments
 * Return: point to next char
*/
char *perc(char *o, facts *factor, va_list *args)
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
		while (_isdigit(*o))
			r = r * 10 + (*o++ - '0');
	}
	factor->percs = r;
	return (r);
}
