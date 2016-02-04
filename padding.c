/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:00:56 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/04 20:14:08 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	ft_padding_switch(char **ret, t_conv *conv, int *i, char **padding, int *offset, int *len)
{
	if ((ft_strchr("dixXcsSp%", conv->conversion) != NULL) || (conv->conversion_pos == -1))
	{
		if (ft_strchr(conv->flag, '-') != NULL)// && ft_strchr("dixXcsSp", conv->conversion) != NULL)
		{
			if (**ret == '-' && *i == 0)
			{
				*padding = ft_strjoin_free(*padding, ft_strdup("-"));
				*offset = 1;
				(*len)++;
			}
			else
				*padding = ft_strjoin_free(*padding, ft_strdup(" "));
		}
		else if (ft_strchr(conv->flag, '0') != NULL)
		{
			if (**ret == '-' && *i == 0)
			{
				*padding = ft_strjoin_free(*padding, ft_strdup("-"));
				*offset = 1;
				(*len)++;
			}
			else
				*padding = ft_strjoin_free(*padding, ft_strdup("0"));
		}
		else
			*padding = ft_strjoin_free(*padding, ft_strdup(" "));
	}
	else
	{
		*padding = ft_strjoin_free(*padding, ft_strdup(" "));
	}
}

static void	ft_do_padding(char **ret, t_conv *conv, int len)
{
	int		i;
	char	*tmp2;
	char	*tmp;
	char	*padding;
	int		offset;

	i = 0;
	offset = 0;
	tmp2 = NULL;
	tmp = NULL;
	//TEST FOR DAT F***ING '\0'
	while ((*ret)[i])
	{
		if (ft_strncmp((const char *)((*ret) + i),
					"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b", 16) == 0)
			len += 15;
		i++;
	}
	i = 0;
	padding = ft_strnew(0);
	if (ft_strcmp(conv->padding, "") != 0)
		while (i < len)
		{
			ft_padding_switch(ret, conv, &i, &padding, &offset, &len);
			i++;
		}
	if (ft_strchr(conv->flag, '0') != NULL && conv->conversion == 'p')
		*ret = ft_strjoin((tmp2 = *ret), tmp = padding);
	else if (ft_strchr(conv->flag, '#') != NULL
			&& ft_strchr("Oo", conv->conversion) != NULL
			&& ft_strcmp(*ret, "0") != 0)
	{
		if (conv->precision_pos != -1 && ft_strlen(conv->precision) > 0 && ft_strcmp(conv->precision, "0") != 0)
			*ret = ft_strjoin_free(padding, *ret);
		else
			*ret = ft_strjoin_free(padding = ft_strjoin_free(ft_strdup("0"), padding), *ret);
	}
	else if (ft_strchr(conv->flag, '#') != NULL
			&& ft_strchr("x", conv->conversion) != NULL
			&& ft_strcmp(*ret, "0") != 0)
	{
		if (conv->precision_pos != -1 && ft_strcmp(*ret, "") == 0 && ft_strcmp(*ret, "0") != 0)
			*ret = ft_strjoin_free(padding, *ret);
		else
			*ret = ft_strjoin_free(padding = ft_strjoin_free(ft_strdup("0x"), padding), *ret);
	}
	else if (ft_strchr(conv->flag, '#') != NULL
			&& ft_strchr("X", conv->conversion) != NULL
			&& ft_strcmp(*ret, "0") != 0)
		*ret = ft_strjoin_free(padding = ft_strjoin_free(ft_strdup("0X"), padding), *ret);
	else
	{
		if (ft_strchr(conv->flag, '-') != NULL)
			*ret = ft_strjoin((tmp2 = *ret) + offset, tmp = padding);
		else
			*ret = ft_strjoin(tmp = padding, (tmp2 = *ret) + offset);
	}
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

char	*ft_get_padding(char *str, t_env *e)
{
	t_conv	conv;
	char	*ret;
	char	*tmp;
	int		i;
	int		n;

	tmp = NULL;
	i = 0;
	ft_init_conv(&conv);
	ret = ft_get_flags(str, &conv, e);
	while (str[i] && str[i] != '%')
	{
		n = 0;
		if (((str[i + n] > '0' && str[i + n] <= '9') && ((i + n) < conv.conversion_pos))
				|| ((str[i + n] > '0' && str[i + n] <= '9') && conv.conversion_pos == -1))
		{
			while ((ft_isdigit(str[i + n]) && ((i + n) < conv.conversion_pos))
					|| (ft_isdigit(str[i + n]) && conv.conversion_pos == -1))
			{
				if (((conv.precision_pos != -1) && ((i + n) < conv.precision_pos))
						|| (conv.precision_pos == -1))
				{
					if (conv.padding_pos == -1)
						conv.padding_pos = i + n;
					conv.padding = ft_strjoin_free(conv.padding, ft_char_to_str(str[i + n]));
				}
				n++;
			}
			break ;
		}
		i++;
	}
#ifdef EBUG
	printf("MODIFIER : '%s'\n", conv.modifier);
	printf("PRECISION : '%s'\n", conv.precision);
	printf("PRECISION_POS : '%d'\n", conv.precision_pos);
	printf("CONVERSION : '%c'\n", conv.conversion);
	printf("CONVERSION_POS : '%d'\n", conv.conversion_pos);
	printf("FLAGS : '%s'\n", conv.flag);
	printf("FLAG_POS : '%d'\n", conv.flag_pos);
	printf("PADDING : '%s'\n", conv.padding);
	printf("PADDING_POS : '%d'\n", conv.padding_pos);
	printf("\n");
#endif
	if (ret == NULL)
	{
		ret = ft_strnew(0);
		// for {%10R} and "% Zooo"
		if (conv.flag_pos == -1 && conv.precision_pos == -1
				&& conv.conversion_pos == -1)
		{
			ft_do_padding(&ret, &conv, (int)(ft_atoi(conv.padding) - ft_strlen(ret)) - 1);
			e->offset = ft_strlen(conv.padding) + 1;
		}
		//for printf("{%-15Z}", 123) && {%05.Z}
		else if ((ft_strchr(conv.flag, '-') != NULL || ft_strchr(conv.flag, '0') != NULL)
				&& conv.conversion_pos == -1)
		{
			ret = ft_char_to_str(str[ft_strlen(conv.padding)
					+ ft_strlen(conv.flag) + ((conv.precision_pos != -1
							&& ft_strcmp(conv.precision, "") == 0) ? (1) : (0))]);
			ft_do_padding(&ret, &conv, (int)(ft_atoi(conv.padding) - ft_strlen(ret)));
			e->offset = ft_strlen(conv.padding) + ft_strlen(conv.flag)
				+ ((conv.precision_pos != -1 && ft_strcmp(conv.precision, "") == 0) ? (1) : (0)) + 2;
		}
	}
	else
	{
		if (conv.precision_pos != -1 && ft_strchr("p", conv.conversion)
				&& ret != NULL && ft_strcmp(conv.flag, "") == 0)
		{

			if (ft_atoi(conv.padding) > ft_atoi(conv.precision))
			{
				while (((int)ft_strlen(ret) - 2) < ft_atoi(conv.precision))
				{
					ret = ft_strjoin_free(ret, ft_strdup("0"));
				}
			}
			else if (ft_strncmp(ret, "0x", 2) == 0)
			{
				tmp = ret;
				ret = ft_strdup(ret + 2);
				ft_strdel(&tmp);
				while (((int)ft_strlen(ret) - 2) < ft_atoi(conv.precision))
					ret = ft_strjoin_free(ft_strdup("0"), ret);
				ret[0] = '0';
				ret[1] = 'x';
			}
		}
		if (ft_strchr("di", conv.conversion) && ft_strcmp(conv.flag, " 0") == 0 && ft_strcmp(ret, "0") == 0)
		{
			ft_do_padding(&ret, &conv, (int)(ft_atoi(conv.padding) - ft_strlen(ret)));
			*ret = ' ';
		}
		else if (ft_strchr("di", conv.conversion) && ft_strchr(conv.flag, '+') != NULL)
		{
			if (ft_strchr(ret, '-') == NULL)
			{
				if (ft_strcmp(ret, "0") != 0) //&& ft_atoi(conv.padding) < (ft_strlen(ret)))
				{
					ret = ft_strjoin_free(ft_strdup("+"), ret);
					ft_do_padding(&ret, &conv, (int)(ft_atoi(conv.padding) - ft_strlen(ret)));
				}
				else
				{
					ft_do_padding(&ret, &conv, (int)(ft_atoi(conv.padding) - ft_strlen(ret)));
					*ret = '+';
				}
			}
		}
		else if (ft_strchr("di", conv.conversion) && ft_strchr(conv.flag, ' ') != NULL
				&& conv.conversion_pos == 1 && conv.flag_pos == 0 && ft_atoi(ret) > 0)
			ret = ft_strjoin_free(ft_strdup(" "), ret);
		else
			ft_do_padding(&ret, &conv, (int)(ft_atoi(conv.padding) - ft_strlen(ret)));
		e->offset = conv.conversion_pos + 2;
	}
	ft_strdel(&conv.flag);
	ft_strdel(&conv.padding);
	ft_strdel(&conv.precision);
	return (ret);
}
