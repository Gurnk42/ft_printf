/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:09:41 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/29 17:54:57 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	ft_init_conv(t_conv *conv)
{
	conv->conversion = 0;
	conv->conversion_pos = -1;
	conv->precision = NULL;
	conv->precision_pos = -1;
	conv->flag = ft_strnew(0);
	conv->flag_pos = -1;
	conv->padding = ft_strnew(0);
}

static void	ft_init_env(char *s, va_list *ap, t_env *e)
{
	e->str = ft_strdup(s);
	e->ap = ap;
	e->res = ft_strnew(0);
	e->tmp = NULL;
	e->ret = NULL;
	e->offset = 2;
}

static char	*ft_get_conversion(char *str, t_conv *conv, t_env *e)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	tmp = NULL;	
	/*if (*str == '%') // YOU LIAR, THERE'S NO WAY YOU'D FIND DAT !!
	{
		conv->conversion = *str;
		return (ft_strdup("%"));
	}*/
	while (str[i] && str[i] != '%')
	{
		if (str[i] == 'c' ||
				str[i] == 's' ||
				str[i] == 'd' ||
				str[i] == 'i' ||
				str[i] == 'u' ||
				str[i] == 'x')
		{
			conv->conversion = str[i];
			conv->conversion_pos = i;
			break ;
		}
		i++;
	}
	if (conv->conversion == 0)
		return (NULL); // strjoin_free should manage dis
	else if (conv->conversion == 'c')
		ret = ft_char_to_str((char)va_arg(*(e->ap), int));
	else if (conv->conversion == 's')
		ret = ft_strdup((const char *)va_arg(*(e->ap), char *));
	else if (conv->conversion == 'd' || conv->conversion == 'i')
		ret = ft_itoa((int)va_arg(*(e->ap), int));
	else if (conv->conversion == 'u')
		ret = ft_itoa((int)va_arg(*(e->ap), unsigned int));
	else if (conv->conversion == 'x')
		ret = ft_itoa_base((unsigned int)va_arg(*(e->ap),
					unsigned int), 16);
	return (ret);
}

static char	*ft_get_precision(char *str, t_conv *conv, t_env *e)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	conv->precision = ft_strnew(0);
	while (str[i] && str[i] != '%')
	{
		if (str[i] == '.')
		{
			n = 1;
			conv->precision_pos = i;
			while (ft_isdigit(str[i + n]) == 1)
			{
				conv->precision = ft_strjoin_free(conv->precision, ft_char_to_str(str[i + n]));
				n++;
			}
			break ;
		}
		i++;
	}
	ret = ft_get_conversion(str, conv, e);
	if (conv->conversion == '%')
		return (ret);
	return (ret);
}

static char	*ft_get_flags(char *str, t_conv *conv, t_env *e)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	ret = ft_get_precision(str, conv, e);
	while (str[i] && str[i] != '%')
	{
		n = 0;
		while (str[i + n] == '#' ||
				str[i + n] == '0' ||
				str[i + n] == '-' ||
				str[i + n] == ' ' ||
				str[i + n] == '+')
		{
			if ((i + n) < conv->precision_pos) // gotta check if flag is not part of precision.
			{
				conv->flag = ft_strjoin(conv->flag, ft_char_to_str(str[i + n]));
				if (conv->flag_pos == -1)
					conv->flag_pos = i + n;
			}
			n++;
		}
		i++;
	}
	return (ret);
}

static char	*ft_get_padding(char *str, t_env *e)
{
	t_conv	conv;
	char	*ret;
	int		i;
	int		n;

	i = 0;
	ft_init_conv(&conv);
	ret = ft_get_flags(str, &conv, e);
	while (str[i] && str[i] != '%')
	{
		n = 0;
		if (ft_isdigit(str[i + n]) && ((i + n) < conv.conversion_pos))
		{
			while (ft_isdigit(str[i + n]) && ((i + n) < conv.conversion_pos))
			{
				// gotta check if flag is not part of precision.
				if (((conv.precision_pos != -1) && ((i + n) < conv.precision_pos))
						|| (conv.precision_pos == -1))
					conv.padding = ft_strjoin(conv.padding, ft_char_to_str(str[i + n]));
				n++;
			}
			break;
		}
		i++;
	}
#ifdef EBUG
	printf("PRECISION : '%s'\n", conv.precision);
	printf("PRECISION_POS : '%d'\n", conv.precision_pos);
	printf("CONVERSION : '%c'\n", conv.conversion);
	printf("CONVERSION_POS : '%d'\n", conv.conversion_pos);
	printf("FLAGS : '%s'\n", conv.flag);
	printf("FLAG_POS : '%d'\n", conv.flag_pos);
	printf("PADDING : '%s'\n", conv.padding);
	//ft_strdel(&conv.precision);
#endif
	e->offset = conv.conversion_pos + 2;
	return (ret);
}

int		ft_printf(char *s, ...)
{
	t_env	env;
	va_list	ap;
	int	len;
	int	i;

	i = 0;
	va_start(ap, s);
	ft_init_env(s, &ap, &env);
	len = ft_strlen(s);
	while (i < len && (env.ret = ft_strchr(env.str + i, '%')) != NULL)
	{
		*env.ret = '\0';
		if (*(env.ret + 1) == '%')
			env.res = ft_strjoin_free(env.res, ft_strjoin(env.str + i, ft_char_to_str('%')));
		else
			env.res = ft_strjoin_free(env.res, ft_strjoin(env.str + i,
				env.tmp = ft_get_padding(env.ret + 1, &env)));
		i += (int)(env.ret - (env.str + i)) + env.offset;
		ft_strdel(&env.tmp);
	}
	ft_putstr(env.res);
	len = ft_strlen(env.res);
	va_end(*(env.ap));
	ft_strdel(&env.res);
	ft_strdel(&env.str);
	return (len);
}
