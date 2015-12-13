#include "ft_printf.h"

int main()
{
	ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%d'", (char)'y', "dat'sastr", -42);
	return (0);
}
