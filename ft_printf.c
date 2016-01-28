/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:09:41 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/28 21:32:33 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*static void	ft_print_arg_2(va_list *ap, char *str)
{
	if (*str == 'x')
		ft_putstr(ft_strdup(ft_itoa_base((unsigned int)va_arg(*ap,
			unsigned int), 16)));
}

static void	ft_print_arg(va_list *ap, char *str)
{
	if (*str == '%')
		ft_putchar('%');
	else if (*str == 'c')
		ft_putchar((char)va_arg(*ap, int));
	else if(*str == 's')
		ft_putstr((char *)va_arg(*ap, char *));
	else if(*str == 'd' || *str == 'i')
		ft_putnbr((int)va_arg(*ap, int));
	else if(*str == 'u')
		ft_putnbr((int)va_arg(*ap, unsigned int));
	else
		ft_print_arg_2(ap, str);
}
*/

static void	ft_get_conversion(char **str, t_conv *conv, char **ret, va_list *ap)
{
	char	*tmp;

	tmp = NULL;
	printf("YOP4\n");
	printf("*STR : '%s'\n", *str);
	if (**str == '%')
		ft_putchar('%');
	else if (**str == 'c')
		ft_strjoin_free(*ret, tmp = ft_char_to_str((char)va_arg(*ap, int)));
	else if (**str == 's')
		ft_strjoin_free(*ret, (char *)va_arg(*ap, char *));
	else if (**str == 'd' || **str == 'i')
		ft_strjoin_free(*ret, tmp = ft_itoa((int)va_arg(*ap, int)));
	else if (**str == 'u')
		ft_strjoin_free(*ret, tmp = ft_itoa((int)va_arg(*ap, unsigned int)));
	else if (**str == 'x')
		ft_strjoin_free(*ret, tmp = ft_itoa_base((unsigned int)va_arg(*ap,
			unsigned int), 16));
	if (tmp != NULL)
		ft_strdel(&tmp);
	printf("RET : '%s'\n", *ret);
}

static char	*ft_get_precision(char **str, t_conv *conv, char **ret, va_list *ap)
{
	printf("YOP3\n");
	ft_get_conversion(str, conv, ret, ap);
}

static char	*ft_get_flags(char **str, t_conv *conv, char **ret, va_list *ap)
{
	printf("YOP2\n");
	ft_get_precision(str, conv, ret, ap);
}

static char	*ft_get_padding(char **str, char **ret, va_list *ap)
{
	t_conv	conv;
	
	printf("YOP1\n");
	ft_get_flags(str, &conv, ret, ap);
}

static char	*ft_get_data(char **str, va_list *ap)
{
	int		i;
	char	*conv;

	i = 0;
	printf("YOP\n");
	conv = ft_strnew(0);
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if ((*str)[i] == '%')
	{
		(*str)[i] = '\0';
		printf("STR : '%s'\n", *str);
		conv = ft_strjoin_free(conv, *str);
		*str = *str + i + 1;
		ft_get_padding(str, &conv, ap);
		printf("CONV : '%s'\n", conv);
	}
	else
		conv = ft_strjoin_free(conv, *str);
		printf("YEP3\n");
	return (conv);
}

void		ft_printf(char *s, ...)
{
	va_list	ap;
	char	*ret;
	char	*str;
	char	*tmp;

	ret = NULL;
	str = ft_strdup(s);
	va_start(ap, s);
	ret = ft_strnew(0);
	while (*str != '\0')
	{
		/*if (*str == '%')
			ft_print_arg(&ap, ++str);
		else
			ft_putchar(*str);
			*/
		ft_putendl(ret = ft_strjoin_free(ret, tmp = ft_get_data(&str, &ap)));
		ft_strdel(&tmp);
	}
	va_end(ap);
	ft_strdel(&str);
}

