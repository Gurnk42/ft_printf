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

static char	*ft_get_conversion(char *str, t_conv *conv, va_list *ap)
{
	char	*tmp;
	char	*ret;

	ret = ft_strnew(0);
	tmp = NULL;
	//printf("STR : '%s'\n", str);
/*	if (*str == '%')
		ft_strjoin_free(ret, (char *)"%");
	else if (*str == 'c')
		ft_strjoin_free(ret, tmp = ft_char_to_str((char)va_arg(*ap, int)));
	else if (*str == 's')
		ft_strjoin_free(ret, (char *)va_arg(*ap, char *));
	else if (*str == 'd' || *str == 'i')
		ft_strjoin_free(ret, tmp = ft_itoa((int)va_arg(*ap, int)));
	else if (*str == 'u')
		ft_strjoin_free(ret, tmp = ft_itoa((int)va_arg(*ap, unsigned int)));
	else if (*str == 'x')
		ft_strjoin_free(ret, tmp = ft_itoa_base((unsigned int)va_arg(*ap,
			unsigned int), 16));
	if (tmp != NULL)
		ft_strdel(&tmp);*/
	ret = ft_strjoin_free(ret, ft_strdup(" BONJOUR "));
	//printf("RET : '%s'\n", ret);
	return (ret);
}

static char	*ft_get_precision(char *str, t_conv *conv, va_list *ap)
{
	return (ft_get_conversion(str, conv, ap));
}

static char	*ft_get_flags(char *str, t_conv *conv, va_list *ap)
{
	return (ft_get_precision(str, conv, ap));
}

static char	*ft_get_padding(char *str, va_list *ap)
{
	t_conv	conv;

	return (ft_get_flags(str, &conv, ap));
}

/*static char	*ft_get_data(char *str, va_list *ap)
{
	int		i;
	char	*ret;

	i = 0;
	if (*str == )
	return (ret);
}*/

int		ft_printf(char *s, ...)
{
	va_list	ap;
	char	*ret;
	char	*str;
	char	*tmp;
	int	len;

	va_start(ap, s);
	ret = NULL;
	str = ft_strdup(s);
	tmp = str;
	while (*tmp != '\0' && (ret = ft_strchr(tmp, '%')) != NULL)
	{
		*ret = '\0';
		str = ft_strjoin(str, ft_get_padding(ret + 1, &ap));
		tmp = ret + 1;
		printf("TMP : '%s'\n", ret + 1);
	}
	ft_putstr(str);
	len = ft_strlen(str);
	va_end(ap);
	ft_strdel(&str);
	return (len);
}
