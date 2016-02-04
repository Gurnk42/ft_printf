/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:58:52 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/04 11:54:53 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_precision(char *str, t_conv *conv, t_env *e)
{
	char	*ret;
	char	*tmp;
	int		prec;
	int		i;
	int		n;

	tmp = NULL;
	i = 0;
	prec = -1;
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
	//if (conv->conversion == '%')
	//	return (ret);
/*	if (ft_strchr("dioOuxX", conv->conversion) && conv->conversion_pos != -1)
	{
		while ()
		{
			
		}
	}*/
	if (conv->precision_pos != -1 && ft_strchr("sS", conv->conversion) && ret != NULL)
	{
		if (ft_atoi(conv->precision) < (int)ft_strlen(ret))
		{
			ret = ft_strncat(ft_strnew(ft_atoi(conv->precision)), tmp = ret, ft_atoi(conv->precision));
			ft_strdel(&tmp);
		}
	}
	if (conv->precision_pos != -1 && ft_strchr("dioOuxX", conv->conversion) && ret != NULL)
	{
		prec = ft_atoi(conv->precision); 
		if (prec == 0 && ft_strcmp(ret, "0") == 0)
		{
			ft_strdel(&ret);
			ret = ft_strnew(0);
		}
		else
			while (prec > (int)ft_strlen(ret))
			{
				ret = ft_strjoin_free(ft_strdup("0"), ret);
				prec--;
			}
	}
	return (ret);
}
