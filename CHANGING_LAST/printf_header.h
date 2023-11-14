#ifndef PRINTF_HEADER_H
#define PRINTF_HEADER_H
/* author for this code : MahmoudMetwalli && AhMeDMaGDY28 */
/*adding the headers------->*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
/*the buffer for task 4*/
#define BUFF_LIMIT 1024
#define BUFF_FLUSHING -1
/*the unused for not bothirng with void*/
#define UNUSED(x) (void)(x)
/*the factors which will come latter in its own struct*/
#define FACTORS_N {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
/*the converstion */
#define CONV_LOW_C 1
#define CONV_USIGN 2
#define NULL_STRING "(_null_)"
/**
 * struct factors - to specify factor
 * @un_sign: unsigned
 * @plus_f: plus flag
 * @space_f: space flag
 * @hash_f: space_flag
 * @zero_f: zero space
 * @minus_f: minus flag
 * @width_p: width
 * @percs: precision
 * @mod_h: h modifier
 * @mod_l: l modifier
 *  * authors for this code :  MahmoudMetwalli && AhMeDMaGDY28
 */
typedef struct factors
{
	unsigned int un_sign :1;
	unsigned int plus_f :1;
	unsigned int space_f :1;
	unsigned int hash_f :1;
	unsigned int zero_f :1;
	unsigned int minus_f :1;
	unsigned int width_p;
	unsigned int percs;
	unsigned int mod_h :1;
	unsigned int mod_l :1;
} facts;

/**
 * struct sepcifiers - to select specifier with the appropriate func
 * @sp: specifier
 * @f: pointer to according func
 *  * authors for this code : MahmoudMetwalli && AhMeDMaGDY28
 */
typedef struct sepcifiers
{
	char *sp;
	int (*f)(va_list, facts *);
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

int print_ch(va_list args, facts *factor);
int print_string(va_list args, facts *factor);
int print_percent(va_list args, facts *factor);
int print_num(va_list args, facts *f);
int print_unsign(va_list args, facts *factor);

/*here is the protoypes in second_5_specifiers.c */
int print_bi(va_list args, facts *factor);
int print_octs(va_list args, facts *factor);
int print_low_hexes(va_list args, facts *factor);
int print_up_hexes(va_list args, facts *f);
int print_stringhex(va_list args, facts *factor);

/*here is the protoypes in last_specifiers.c */
int print_segment(char *front, char *end, char *out);
int print_rever(va_list args, facts *factor);
int print_rot13(va_list args, facts *factor);
int print_adrs(va_list args, facts *factor);

/*here is the protoypes in checkers.c */
int print_no(char *s, facts *factor);
int print_no_right_justified(char *s, facts *factor);
int print_no_left_justified(char *s, facts *f);

/*here is the protoypes in checking_specs.c */
int flags(char *s, facts *factor);
char *width(char *s, facts *factor, va_list args);
char *perc(char *o, facts *factor, va_list args);
int mods(char *s, facts *factor);
int (*spec(char *s))(va_list args, facts *factor);

/*here is the protoypes in converter&checker.c */
char *conv(long int i, int b, int flag, facts *factor);
int chose_print_fun(char *s, va_list args, facts *factor);
void fact(facts *f, va_list args);


#endif
