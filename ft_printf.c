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
	if (*str == '%')
		ret = ft_strjoin_free(ret, ft_strdup("%"));
	else if (*str == 'c')
		ret = ft_strjoin_free(ret, ft_char_to_str((char)va_arg(*ap, int)));
	else if (*str == 's')
		ret = ft_strjoin_free(ret, ft_strdup((const char *)va_arg(*ap, char *)));
	else if (*str == 'd' || *str == 'i')
		ret = ft_strjoin_free(ret, ft_itoa((int)va_arg(*ap, int)));
	else if (*str == 'u')
		ret = ft_strjoin_free(ret, ft_itoa((int)va_arg(*ap, unsigned int)));
	else if (*str == 'x')
		ret = ft_strjoin_free(ret, ft_itoa_base((unsigned int)va_arg(*ap,
			unsigned int), 16));
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

int		ft_printf(char *s, ...)
{
	va_list	ap;
	char	*ret;
	char	*str;
	char	*res;
	int	len;
	int	i;
	int	offset;

	offset = 2;
	va_start(ap, s);
	ret = NULL;
	str = ft_strdup(s);
	res = ft_strnew(0);
	i = 0;
	while ((ret = ft_strchr(&(str[i]), '%')) != NULL)
	{
		*ret = '\0';
		res = ft_strjoin_free(res, ft_strjoin(str + i,
			ft_get_padding(ret + 1, &ap)));
		i += (int)(ret - (str + i)) + offset;
	}
	ft_putstr(res);
	len = ft_strlen(res);
	va_end(ap);
	ft_strdel(&res);
	ft_strdel(&str);
	return (len);
}
