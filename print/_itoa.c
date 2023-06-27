#include "main.h"

/**
 * _itoa - convert integer to string
 * @num: number to be converted
 * @base: base of the number
 * @flag: parameters flag
 *
 * Return: pointer to the string
 */
char *_itoa(long int num, int base, int flag)
{
	static char *ar;
	static char buf[50];
	char *p;
	char sign = 0;
	unsigned long int n = num;

	if (!(flag & CONV_UNSIG) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	ar = (flag & CONV_LC) ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do {
		*--p = ar[n % base];
		n /= base;
		} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}
