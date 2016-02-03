#include "ft_printf.h"

#include <stdio.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;

	//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("{%10d}", 42);
	setbuf(stdout, NULL);
	printf("{%10R}");
	//printf("{%8c}", 0);
	printf("_______\n");
	len = ft_printf("{%10R}", 0);
	return (len);
}
