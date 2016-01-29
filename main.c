#include "ft_printf.h"

#include <stdio.h>

int main()
{
	unsigned int x = 3242334;

	ft_printf("char : '%.10c',\nstr: '%s',\n%%: '%%'\nint: '%d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	printf("-----------------------------------------------\n");
	printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	return (0);
}
