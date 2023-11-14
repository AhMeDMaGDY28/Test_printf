#include "main.h"
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
