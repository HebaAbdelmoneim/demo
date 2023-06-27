#include "main.h"

/**
 * print_num - print number according to flags
 * @s: string of the number
 * @fl: flags struct
 *
 * Return: pointer to string
 */

int print_num(char *s, flag_ty *fl)
{
	unsigned int len = strlen(s);
	int sign = (!fl->unsign && *s == '-');

	if (!fl->prec && *s == '0' && !s[1])
		s = "";

	if (sign)
	{
		s++;
		len--;
	}

	if (fl->prec != UINT_MAX)
	{
		while (len++ < fl->prec)
			*--s = '0';
	}

	if (sign)
		*--s = '-';

	if (fl->minus_fl)
		return (print_num_ap(s, fl));
	else
		return (print_num_bp(s, fl));
}

/**
 * print_num_ap - print number after the point
 * @s: string of the number
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */
int print_num_ap(char *s, flag_ty *fl)
{
	unsigned int ch_num = 0, sign, sign2, len = strlen(s);
	char pad = ' ';

	if (fl->zero_fl  && !fl->minus_fl)
		pad = '0';

	sign = sign2 = (!fl->unsign && *s == '-');

	if (sign && len < fl->width && pad == '0' && !fl->minus_fl)
		s++;
	else
		sign = 0;

	if ((fl->plus_fl && sign2) || (!fl->plus_fl && fl->space_fl && !sign2))
		len++;

	if (sign && pad == '0')
		ch_num += _putchar('-');

	if (fl->plus_fl && !sign2 && pad == '0' && !fl->unsign)
		ch_num += _putchar('+');
	else if (!fl->plus_fl && fl->space_fl && !sign2 && !fl->unsign && fl->zero_fl)
		ch_num += _putchar(' ');

	while (len++ < fl->width)
		ch_num += _putchar(pad);

	if (sign && pad == ' ')
		ch_num += _putchar('-');

	if (fl->plus_fl && !sign2 && pad == ' ' && !fl->unsign)
		ch_num += _putchar('+');
	else if (!fl->plus_fl && fl->space_fl
			&& !sign2 && !fl->unsign && !fl->zero_fl)
		ch_num += _putchar(' ');
	ch_num += _putstr(s);
	return (ch_num);
}

/**
 * print_num_bp - print number before the point
 * @s: string of the number
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */
int print_num_bp(char *s, flag_ty *fl)
{
	unsigned int ch_num = 0, sign, sign2, len = strlen(s);
	char pad = ' ';

	if (fl->zero_fl && !fl->minus_fl)
		pad = '0';

	sign = sign2 = (!fl->unsign && *s == '-');

	if (sign && len < fl->width && pad == '0' && !fl->minus_fl)
		s++;
	else
		sign = 0;

	if (fl->plus_fl && !sign2 && !fl->unsign)
		ch_num += _putchar('+'), len++;
	else if (fl->space_fl && !sign2 && !fl->unsign)
		ch_num += _putchar(' '), len++;

	ch_num += _putstr(s);
	while (len++ < fl->width)
		ch_num += _putchar(pad);
	return (ch_num);
}
