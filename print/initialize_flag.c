#include "main.h"

/**
 * init_flags - initialize the flags
 * @fl: flags struct
 *
 * Return: void
 */

void init_flags(flag_ty *fl)
{
	fl->plus_fl = 0;
	fl->minus_fl = 0;
	fl->zero_fl = 0;
	fl->space_fl = 0;
	fl->hash_fl = 0;
	fl->unsign = 0;
	fl->width = 0;
	fl->prec = UINT_MAX;
	fl->short_mod = 0;
	fl->long_mod = 0;
}
