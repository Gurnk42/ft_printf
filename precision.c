/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:58:52 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/04 11:31:38 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_precision(char *str, t_conv *conv, t_env *e)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		n;

	tmp = NULL;
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
	return (ret);
}
