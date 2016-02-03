#include "ft_printf.h"

#include <stdio.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;

	//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
//	setbuf(stdout, NULL);
/*	printf("{%10R}\n");
	printf("% d\n", 9999);
	printf("% Zoooo\n");
	printf("%S\n", L"dsfsdfsd");
	printf("_______\n");
	len = ft_printf("% d\n", 9999);
	ft_printf("% Zoooo\n", 9999);
	ft_printf("{%10R}\n");
  
	const wchar_t c = L'α';
	char *buf = ft_strnew(4);*/
	//if (ft_utf8_encode(buf, (int)c))
	//printf("STR : '%S'\n", (wchar_t *)L"");
	ft_printf("STR : '%C'\n", 0);
	return (len);
}
