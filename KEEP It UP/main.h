#ifndef M_PRINT
#define M_PRINT
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define BUFF_LIMIT 1024
#define BUFF_FLUSHING -1
#define UNUSED void(x)

#define FACTORS_N {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOW_C 1
#define CONV_USIGN 2

#define NULL_STRING "(null)"
/**
 * struct sepcifiers - to select appropriate func
 * @sp: specifier
 * @f: pointer to according func
 */
typedef struct sepcifiers
{
	char sp;
	int (*f)(va_list, facts *);
} specs;
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
 */
typedef struct factors
{
	unsigned int un_sign :1;
	unsigned int plus_f :1;
	unsigned int space_f :1;
	unsigned int hash_f :1;
	unsigned int zero_f :1;
	unsigned int minus_f :1;
	unsigned int width_p :1;
	unsigned int percs :1;
	unsigned int mod_h :1;
	unsigned int mod_l :1;
} facts;
int _printf(const char *format, ...);
int _puts(char *s);
int _putchar(int i);
int print_ch(va_list args, facts *f);
int print_num(va_list args, facts *f);
int print_string(va_list args, facts *f);
int print_percent(va_list args, facts *f);
int print_stringhex(va_list args, facts *f);

char *conv(long int i, int b, int flag, facts *factor);
int print_unsign(va_list args, facts *factor);
int print_adrs(va_list args, facts *factor);

int (*spec(char *s))(va_list args, facts *f);
int chose_print_fun(char *s, va_list args, facts *factor);
int flags(char *s, facts *factor);
int mods(char *s, facts *factor);
char *width(char *s, facts *factor, va_list args);

int print_low_hexes(va_list args, facts *factor);
int print_up_hexes(va_list args, facts *f);
int print_bi(va_list args, facts *factor);
int print_octs(va_list args, facts *factor);
int print_segment(char *front, char *end, char *out);
int print_rever(va_list args, facts *factor);
int print_rot13(va_list args, facts *factor);

int _isdigit(int i);
int _strlen(char *d);
int print_no(char *s, facts *factor);
int print_no_right_justified(char *s, facts *factor);
int print_no_left_justified(char *s, facts *f);
void fact(facts *f, va_list args);
char *perc(char *o, facts *factor, va_list *f);

#endif
