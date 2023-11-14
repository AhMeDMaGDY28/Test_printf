#ifndef PRINTF_HEADER_H
#define PRINTF_HEADER_H
/* author for this code : MahmoudMetwalli && AhMeDMaGDY28 */
/*adding the headers------->*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
/**
 * struct sepcifiers - to select specifier with the appropriate func
 * @sp: specifier
 * @f: pointer to according func
 *  * authors for this code : MahmoudMetwalli && AhMeDMaGDY28
 */
typedef struct sepcifiers
{
	char *sp;
	int (*f)(va_list);
} specs;

/*all the protoype */

/*here is the protoypes in our_old_simple_function.c*/
int _puts(char *s);
int _putchar(int i);
int _isdigit(int i);
int _strlen(char *d);

/*here is the prototype which alx gave us*/

int _printf(const char *format, ...);

/*here is the protoypes in first_5_specifier.c */

int print_ch(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_num(va_list args);
int print_unsign(va_list args);

/*here is the protoypes in second_5_specifiers.c */
int print_bi(va_list args);
int print_octs(va_list args);
int print_low_hexes(va_list args);
int print_up_hexes(va_list args);
int print_stringhex(va_list args);

/*here is the protoypes in last_specifiers.c */
int print_rever(va_list args);
int print_rot13(va_list args);

/*here is the protoypes in checkers.c */
int print_no(char *s);

/*here is the protoypes in checking_specs.c */
int (*spec(char *s))(va_list args);

/*here is the protoypes in converter&checker.c */
char *conv(int i, int b, int low);
int chose_print_fun(char *s, va_list args);

#endif
