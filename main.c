#include "ft_printf.h"

#include <stdio.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;

	//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\nTEST:\n");
	//ft_printf("P : '%p'", &x);
	//printf("P : '%p'", &x);
	//printf("%i\n", (long)(-2147483648));
	//printf("CONV: '%s'\n", ft_lltoa_base(-42, "0123456789"));
	printf("%ld%ld\n", 0, 42);
	//printf("{%-10d}\n", -42);
	printf("_______\n");
	//len = ft_printf("{%ld}\n", (long)2147483647 + 1);
	ft_printf("%ld%ld\n", 0, 42);
	return (len);
}
