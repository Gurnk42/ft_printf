/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:58:52 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/06 15:53:04 by ebouther         ###   ########.fr       */
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
	while (str[i] && str[i] != '%' && ft_strchr("hljz sSpdDioOuUxXcC% .1234567890 #0-+", str[i]) != NULL)
	{
		if (str[i] == '.')
		{
			n = 1;
			conv->precision_pos = i;
			while (ft_isdigit(str[i + n]) == 1)
			{
				conv->precision = ft_strjoin_free(conv->precision,
						ft_char_to_str(str[i + n]));
				n++;
			}
			break ;
		}
		i++;
	}
	ret = ft_get_conversion(str, conv, e);
	//printf("RET : '%s'\n", ret);
	if (conv->precision_pos != -1 && ft_strchr("sS", conv->conversion) && ret != NULL)
	{
		if (ft_atoi(conv->precision) < (int)ft_strlen(ret))
		{
			i = 0;
			n = 0;
			while (ret[i] && i < ft_atoi(conv->precision))
			{
				if (ret[i] >= 0x0000 && ret[i] <= 0x007F)
				{
					n = 0;
					i++;
				}
				else
				{
					i += 3;
					n = 1;
				}
			}
			if (i > ft_atoi(conv->precision) && n == 1)
				i -= 3;
			ret = ft_strncat(ft_strnew(ft_atoi(conv->precision)), tmp = ret, i);
			ft_strdel(&tmp);
		}
	}
	if (conv->precision_pos != -1 && ft_strchr("dioOuxX", conv->conversion)
			&& ret != NULL)
	{
		i = 0;
		if (ft_atoi(ret) >= 0)
			i = 1;
		if (ft_atoi(conv->precision) == 0 && ft_strcmp(ret, "0") == 0)
		{
			ft_strdel(&ret);
			ret = ft_strnew(0);
		}
		else
		{
			while ((int)ft_strlen(ret) < ft_atoi(conv->precision))
			{
				if (i > 0)
					ret = ft_strjoin_free(ft_strdup("0"), ret);
				else
				{
					i--;
					if (i == -1 && *ret == '-')
						*ret = '0';
					else
						ret = ft_strjoin_free(ft_strdup("0"), ret);
				}
			}
			if (i < 0)
				ret = ft_strjoin_free(ft_strdup("-"), ret);
		}
	}
	return (ret);
}
