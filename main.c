#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;
	char c;

	setbuf(stdout, NULL);

	//printf("{%-15Z}", 123);
	//printf("{%10R}", 123);
	//printf("% Zoooo");
	//len = ft_printf("{%-15Z}", 123);
	//len = ft_printf("%#x", 42);
	//len = ft_printf("% Zoooo");
	//ft_printf("{%10R}", 123);
//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
/*	printf("%#.o, %#.0o", 0, 0);
	printf("\n_______\n");
	printf("%#.x, %#.0x", 0, 0);
	printf("\n_______\n");
	printf("%.p, %.0p", 0, 0);
	printf("\n_______\n");
	printf("{%05.c}", 0);
	printf("\n_______\n");
	printf("{%05.s}", 0);
	printf("\n_______\n");
	printf("{%05.%}", 0);
	printf("\n_______\n");
	printf("{%05.Z}", 0);
	printf("\n_______\n");
	printf("{%#.5x}", 1);
	printf("\n_______\n");
	printf("%#.3o", 1);
	printf("\n_______\n");
	printf("{%05.S}", L"42 c est cool");
	printf("\n_____======================_____\n");
	printf("\n_______\n");
	ft_printf("%#.o, %#.0o", 0, 0);
	printf("\n_______\n");
	ft_printf("%#.x, %#.0x", 0, 0);
	printf("\n_______\n");
	ft_printf("%.p, %.0p", 0, 0);
	printf("\n_______\n");
	ft_printf("{%05.c}", 0);
	printf("\n_______\n");
	ft_printf("{%05.s}", 0);
	printf("\n_______\n");
	ft_printf("{%05.%}", 0);
	printf("\n_______\n");
	ft_printf("{%05.Z}", 0);
	printf("\n_______\n");
	ft_printf("{%#.5x}", 1);
	printf("\n_______\n");
	ft_printf("%#.3o", 1);
	printf("\n_______\n");
	ft_printf("{%05.S}", L"42 c est cool");*/
	printf("\n_______\n");
	printf("%.p, %.0p", 0, 0);
	ft_printf("\n_______\n");
	ft_printf("%.p, %.0p", 0, 0);
	return (len);
}
