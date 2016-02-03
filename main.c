#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;
	char c;

	//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	setbuf(stdout, NULL);
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
/*	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
*/
	ft_printf("%s %d %p %% %S %D %i %o %O %u %U %x %X %c %C","bonjour", 42, &c, L"暖炉",
		LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	return (len);
}
