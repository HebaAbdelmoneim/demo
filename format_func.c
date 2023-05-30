#include "main.h"

/**
 * print_func - print the function according to format
 * @ch: format type char
 * @pa: the parameters list
 * @fl: flags struct
 * Return: the numbers of printed char
 */

int print_func(char *ch, va_list pa, flag_ty *fl)
{
	int (*f)(va_list, flag_ty *) = check_format(ch);

	if (f)
		return (f(pa, fl));
	return (0);
}
