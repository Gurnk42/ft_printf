#include "ft_printf.h"

#include <stdio.h>

int main()
{
	unsigned int x = 3242334;

	ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	printf("-----------------------------------------------\n");
	printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	return (0);
}
