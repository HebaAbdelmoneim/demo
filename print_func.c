#include  "main.h"

/**
 * print_char - print char
 * @pa: the parameters list
 * @fl: parameters struct
 *
 * Return: the numbers of printed char
 */

int print_char(va_list pa, flag_ty *fl)
{
	char pad = ' ';
	unsigned int p  = 1, ch_num = 0, ch = va_arg(pa, int);

	if (fl->minus_fl)
		ch_num += _putchar(ch);
	while (p++ < fl->width)
		ch_num += _putchar(pad);
	if (!fl->minus_fl)
		ch_num += _putchar(ch);
	return (ch_num);
}

/**
 * print_int - print integer
 * @pa: the parameters list
 * @fl: parameters struct
 *
 * Return: the numbers of printed char
 */

int print_int(va_list pa, flag_ty *fl)
{
	long in;
	int ch_num;

	if (fl->long_mod)
		in = va_arg(pa, long);
	else if (fl->short_mod)
		in = (short int)va_arg(pa, int);
	else
		in = va_arg(pa, int);
	ch_num = print_num(_itoa(in, 10, 0), fl);
	return (ch_num);
}

/**
 * print_string - print string
 * @pa: the parameters list
 * @fl: parameters struct
 *
 * Return: the numbers of printed char
 */

int print_string(va_list pa, __attribute__((unused)) flag_ty *fl)
{
	char *str = va_arg(pa, char *), pad = ' ';
	unsigned int p = 0, ch_num = 0, i = 0, j;

	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = p = strlen(str);
	if (fl->prec < p)
		j = p = fl->prec;

	if (fl->minus_fl)
	{
		if (fl->prec != UINT_MAX)
		{
			for (i = 0; i < p; i++)
				ch_num += _putchar(*str++);
		}
		else
			ch_num += _putstr(str);
	}
	while (j++ < fl->width)
		ch_num += _putchar(pad);

	if (!fl->minus_fl)
	{
		if (fl->prec != UINT_MAX)
		{
			for (i = 0; i < p; i++)
				ch_num += _putchar(*str++);
		}
		else
			ch_num += _putstr(str);
	}
	return (ch_num);
}

/**
 * print_percent - print percent
 * @pa: the parameters list
 * @fl: parameters struct
 *
 * Return: the numbers of printed char
 */

int print_percent(va_list pa, flag_ty *fl)
{
	(void)pa;
	(void)fl;
	return (_putchar('%'));
}

/**
 * print_S - print string
 * @pa: the parameters list
 * @fl: parameters struct
 *
 * Return: the numbers of printed char
 */

int print_S(va_list pa, __attribute__((unused)) flag_ty *fl)
{
	char *str = va_arg(pa, char *);
	char *hex;
	int ch_num, i;
	int len = strlen(str);

	if (str == NULL)
		return (_putstr(NULL_STR));

	for (i = 0; i < len; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			ch_num += _putchar('\\');
			ch_num += _putchar('x');
			hex = _itoa(str[i], 16, 0);
			if (!hex[1])
				ch_num += _putchar('0');
			ch_num += _putstr(hex);
		}
		else
			ch_num += _putchar(str[i]);
	}
	return (ch_num);
}
