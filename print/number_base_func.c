#include "main.h"

/**
 * print_hex_l - print unsigned hex number in lowercase
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */

int print_hex_l(va_list pa, flag_ty *fl)
{
	unsigned long l;
	int ch_num = 0;
	char *s;

	if (fl->long_mod)
		l = va_arg(pa, unsigned long);
	else if (fl->short_mod)
		l = (unsigned short int)va_arg(pa, unsigned int);
	else
		l = (unsigned int) va_arg(pa, unsigned int);

	s = _itoa(l, 16, CONV_UNSIG | CONV_LC);

	if (fl->hash_fl && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	fl->unsign = 1;
	ch_num += print_num(s, fl);
	return (ch_num);
}

/**
 * print_hex_u - print unsigned hex number in uppercase
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */

int print_hex_u(va_list pa, flag_ty *fl)
{
	unsigned long l;
	int ch_num = 0;
	char *s;

	if (fl->long_mod)
		l = va_arg(pa, unsigned long);
	else if (fl->short_mod)
		l = (unsigned short int)va_arg(pa, unsigned int);
	else
		l = (unsigned int)va_arg(pa, unsigned int);

	s = _itoa(l, 16, CONV_UNSIG);

	if (fl->hash_fl && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	fl->unsign = 1;
	ch_num += print_num(s, fl);
	return (ch_num);
}

/**
 * print_binary - print unsigned binary number
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */

int print_binary(va_list pa, flag_ty *fl)
{
	unsigned int n = va_arg(pa, unsigned int);
	char *s = _itoa(n, 2, CONV_UNSIG);
	int ch_num = 0;

	if (fl->hash_fl && n)
		*--s = '0';
	fl->unsign = 1;
	ch_num += print_num(s, fl);
	return (ch_num);
}

/**
 * print_octal - print unsigned octal number
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */

int print_octal(va_list pa, flag_ty *fl)
{
	unsigned long l;
	char *s;
	int ch_num = 0;

	if (fl->long_mod)
		l = va_arg(pa, unsigned long);
	else if (fl->short_mod)
		l = (unsigned short int)va_arg(pa, unsigned int);
	else
		l = (unsigned int)va_arg(pa, unsigned int);

	s = _itoa(l, 8, CONV_UNSIG);
	if (fl->hash_fl && l)
		*--s = '0';
	fl->unsign = 1;
	ch_num += print_num(s, fl);
	return (ch_num);
}
