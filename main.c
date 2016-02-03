#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;
	char c;

	setbuf(stdout, NULL);
/*printf("\n_______");
	printf("{%010d}", 42);
printf("\n_______");
	printf("{%010d}", -42);
printf("\n_______");
	printf("{%04d}", 10000);
printf("\n_______");
	printf("{%030d}", 10000);
printf("\n_______");
	printf("{%030x}", 0xFFFF);
printf("\n_______");
	printf("{%030X}", 0xFFFF);
printf("\n_______");
	printf("{%03c}", 0);
printf("\n_______");
	printf("{%05s}", "abc");
//printf("\n_______");
//	printf("{%030S}", L"我是一只猫。");
printf("\n_______");
	printf("{%05p}", 0);
	
printf("\n_______");
printf("\n__MINE__");
printf("\n_______");
	ft_printf("{%010d}", 42);
printf("\n_______");
	ft_printf("{%010d}", -42);
printf("\n_______");
	ft_printf("{%04d}", 10000);
printf("\n_______");
	ft_printf("{%030d}", 10000);
printf("\n_______");
	ft_printf("{%030x}", 0xFFFF);
printf("\n_______");
	ft_printf("{%030X}", 0xFFFF);
printf("\n_______");
	ft_printf("{%03c}", 0);
printf("\n_______");
	ft_printf("{%05s}", "abc");
//printf("\n_______");
//	ft_printf("{%030S}", L"我是一只猫。");
printf("\n_______");
	ft_printf("{%05p}", 0);
*/
	len = ft_printf("%c", 0);
	printf("%c", 0);
	printf("LEN : '%d'\n", len);

	//printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);

//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	
	return (len);
}
