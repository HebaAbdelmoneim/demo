#include "main.h"

/**
 * _printf - print any type
 * @format: pointer to string
 *
 * Return: the numbers of printed char
 */
int _printf(const char *format, ...)
{
	int ch_num = 0;
	va_list pa;
	char *p, *start, *fr;
	flag_ty flags = INIT_FLAG;

	va_start(pa, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_flags(&flags);
		if (*p != '%')
		{
			ch_num += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (check_flag_ch(p, &flags))
			p++;
		p = check_width(p, &flags, pa);
		p = check_prec(p, &flags, pa);
		if (check_modifier(p, &flags))
			p++;
		if (!check_format(p))
		{
			fr = (flags.long_mod || flags.short_mod) ? p - 1 : 0;
			ch_num += print_part(start, p, fr);
		}
		else
			ch_num += print_func(p, pa, &flags);
	}
	_putchar(CLEAR_BUF);
	va_end(pa);
	return (ch_num);
}
