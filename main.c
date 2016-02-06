#include "printf.h"

#include <stdio.h>
#include <limits.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;
	char c;

	setbuf(stdout, NULL);
  
/*  printf("% ");
  printf("% h");
  printf("% hZ");
  printf("% hZ%");
  printf("%ll#x", 9223372036854775807);
printf("\n________\n");*/
  printf("'%0 d'", 42);
printf("\n________\n");
  printf("'% 0d'", 42);
printf("\n________\n");
printf("\n________\n");
printf("\n________\n");
printf("\n________\n");
	ft_printf("'%0 d'", 42);
printf("\n________\n");
	ft_printf("'% 0d'", 42);
printf("\n________\n");
/*
printf("\n________\n");
  printf("%5+d", 42);
  printf("%-5+d", 42);
  printf("%zhd", "4294967296");
  printf("%jzd", "9223372036854775807");
  printf("%jhd", "9223372036854775807");
  printf("%lhl", "9223372036854775807");
  printf("%lhlz", "9223372036854775807");
  printf("%zj", "9223372036854775807");
  printf("%lhh", "2147483647");
  printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
  printf("@main_ftprintf: %####0000 33..1d", 256);
  printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);//irintf("{%-15Z}", 123);
*/

	return (len);
}
