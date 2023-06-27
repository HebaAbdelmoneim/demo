#ifndef MAIN_H
#define MAIN_H

/* std header files */
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

/* definitions */
#define LOCAL_BUF 1024
#define CLEAR_BUF -1

#define INIT_FLAG {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NULL_STR "(nil)"

#define CONV_LC 1
#define CONV_UNSIG 2

/* struct definitions */
/**
 * struct flags - struct flags
 *
 * @plus_fl: flag for plus sign
 * @minus_fl: flag for minus sign
 * @zero_fl: flag for zero
 * @space_fl: flag for space
 * @hash_fl: flag for hashtag sign
 * @unsign: flag for the unsign
 * @width: flag for width size
 * @prec: flag for precision
 * @short_mod: flag for short modifier
 * @long_mod: flag for long modifier
 */
typedef struct flags
{
	unsigned int plus_fl;
	unsigned int minus_fl;
	unsigned int zero_fl;
	unsigned int space_fl;
	unsigned int hash_fl;
	unsigned int unsign;
	unsigned int width;
	unsigned int prec;
	unsigned int short_mod;
	unsigned int long_mod;
} flag_ty;

/**
 * struct spec - Struct specifiers
 *
 * @sp: The parameter type
 * @f: The function associated
 */
typedef struct spec
{
	char *sp;
	int (*f)(va_list, flag_ty *);
} spec_ty;

/* write functions */
int _putstr(char *str);
int _putchar(int c);

/* specifier format functions */
int print_char(va_list pa, flag_ty *fl);
int print_int(va_list pa, flag_ty *fl);
int print_string(va_list pa, flag_ty *fl);
int print_percent(va_list pa, flag_ty *fl);
int print_S(va_list pa, flag_ty *fl);

/* check the flags and format functions */
int (*check_format(char *ch))(va_list pa, flag_ty *fl);
int check_flag_ch(char *s, flag_ty *fl);
int check_modifier(char *s, flag_ty *fl);
char *check_width(char *s, flag_ty *fl, va_list pa);
char *check_prec(char *s, flag_ty *fl, va_list pa);

/* convert number depending on the base format functions */
int print_hex_l(va_list pa, flag_ty *fl);
int print_hex_u(va_list pa, flag_ty *fl);
int print_binary(va_list pa, flag_ty *fl);
int print_octal(va_list pa, flag_ty *fl);

/* special print functions */
int print_part(char *bg, char *end, char *exclude);
int print_unsigned(va_list pa, flag_ty *fl);
int print_address(va_list pa, flag_ty *fl);
int print_rev(va_list pa, flag_ty *fl);
int print_rot13(va_list pa, flag_ty *fl);

/* print numbers depending on the format functions */
int print_num(char *s, flag_ty *fl);
int print_num_ap(char *s, flag_ty *fl);
int print_num_bp(char *s, flag_ty *fl);

/*convert integer to string*/
char *_itoa(long int num, int base, int flag);

/* initialization of the flags function */
void init_flags(flag_ty *fl);

/* print format function  */
int print_func(char *ch, va_list pa, flag_ty *fl);

/* prinf function */
int _printf(const char *format, ...);

#endif /*MAIN_H*/
