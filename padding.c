/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:00:56 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/03 12:23:25 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	ft_padding_switch(char **ret, t_conv *conv, int *i, char **padding, int *offset, int *len)
{
	if (conv->conversion == 'd' || conv->conversion == 'i')
	{
		if (ft_strchr(conv->flag, '0') != NULL)
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
		else if (ft_strchr(conv->flag, '-') != NULL)
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
		else
			*padding = ft_strjoin_free(*padding, ft_strdup(" "));
	}
	else
		*padding = ft_strjoin_free(*padding, ft_strdup(" "));
}

static void	ft_do_padding(char **ret, t_conv *conv)
{
	int		i;
	char	*tmp2;
	char	*tmp;
	char	*padding;
	int		offset;
	int		len;

	i = 0;
	offset = 0;
	tmp2 = NULL;
	tmp = NULL;
	len = (int)(ft_atoi(conv->padding) - ft_strlen(*ret));
	//TEST FOR DAT F***ING '\0'
	while ((*ret)[i])
	{
		if (ft_strncmp((const char *)((*ret) + i), "0x00", 4) == 0)
			len += 3;
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
	if (ft_strchr(conv->flag, '-') != NULL)
		*ret = ft_strjoin((tmp2 = *ret) + offset, tmp = padding);
	else
		*ret = ft_strjoin(tmp = padding, (tmp2 = *ret) + offset);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

char	*ft_get_padding(char *str, t_env *e)
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
		if ((ft_isdigit(str[i + n]) && ((i + n) < conv.conversion_pos)) || conv.conversion_pos == -1)
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
			//GET OFFSET THERE TO START AFTER PADDING ETC.
			break;
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
	//ft_strdel(&conv.precision);
#endif

	if (ret == NULL)
		ret = ft_strnew(0);
	ft_do_padding(&ret, &conv);
	//else
	//	return (ft_strnew(0));
	e->offset = conv.conversion_pos + 2;
	ft_strdel(&conv.flag);
	ft_strdel(&conv.padding);
	ft_strdel(&conv.precision);
	return (ret);
}
