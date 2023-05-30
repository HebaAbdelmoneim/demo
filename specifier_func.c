#include"main.h"

/**
 * check_format - specify the function format
 * @ch: format type char
 *
 * Return: the numbers of printed char
 */

int (*check_format(char *ch))(va_list pa, flag_ty *fl)
{
	spec_ty specs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_l},
		{"X", print_hex_u},
		{"S", print_S},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].sp)
	{
		if (*ch == specs[i].sp[0])
		{
			return (specs[i].f);
		}
		i++;
	}
	return (NULL);
}


/**
 * check_flag_ch - check for flags characters
 * @s: format type char
 * @fl: flags struct
 *
 * Return: Return: On success 1.
 */

int check_flag_ch(char *s, flag_ty *fl)
{
	int i = 0;

	switch (*s)
	{
		case '#':
			i = fl->hash_fl = 1;
			break;
		case '0':
			i = fl->zero_fl = 1;
			break;
		case '-':
			i = fl->minus_fl = 1;
			break;
		case ' ':
			i = fl->space_fl = 1;
			break;
		case '+':
			i = fl->plus_fl = 1;
			break;
	}
	return (i);
}

/**
 * check_modifier - check for length modifier
 * @s: format type char
 * @fl: flags struct
 *
 * Return: Return: On success 1.
 */
int check_modifier(char *s, flag_ty *fl)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = fl->short_mod = 1;
			break;
		case 'l':
			i = fl->long_mod = 1;
			break;
	}
	return (i);
}

/**
 * check_width - check for field width
 * @s: format type string
 * @fl: flags struct
 * @pa: the parameters list
 *
 * Return: pointer to string
 */
char *check_width(char *s, flag_ty *fl, va_list pa)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(pa, int);
		s++;
	}
	else
	{
		while (isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	fl->width = i;
	return (s);
}

/**
 * check_prec - check for Precision
 * @s: format type string
 * @fl: flags struct
 * @pa: the parameters list
 *
 * Return: pointer to string
 */
char *check_prec(char *s, flag_ty *fl, va_list pa)
{
	int i = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		i = va_arg(pa, int);
		s++;
	}
	else
	{
		while (isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	fl->prec = i;
	return (s);
}
