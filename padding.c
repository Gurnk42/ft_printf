/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:00:56 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/06 15:55:55 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_padding_switch_core(t_padding *p, t_conv *conv, int *offset)
{
	if (**(p->ret) == '-' && *(p->i) == 0)
	{
		*(p->padding) = ft_strjoin_free(*(p->padding), ft_strdup("-"));
		*offset = 1;
		(*(p->len))++;
	}
	else if (conv->padding_pos != -1 && conv->precision_pos != -1
			&& ft_strlen(conv->precision) > 0
			&& ft_atoi(conv->padding) > ft_atoi(conv->precision))
		*(p->padding) = ft_strjoin_free(*(p->padding), ft_strdup(" "));
	else
		*(p->padding) = ft_strjoin_free(*(p->padding), ft_strdup("0"));
}

static void	ft_padding_switch(t_padding *p, t_conv *conv, int *offset)
{
	if ((ft_strchr("oduixXcsSp%", conv->conversion) != NULL)
			|| (conv->conversion_pos == -1))
	{
		if (ft_strchr(conv->flag, '-') != NULL)
		{
			if (**(p->ret) == '-' && *(p->i) == 0)
			{
				*(p->padding) = ft_strjoin_free(*(p->padding), ft_strdup("-"));
				*offset = 1;
				(*(p->len))++;
			}
			else
				*(p->padding) = ft_strjoin_free(ft_strdup(" "), *(p->padding));
		}
		else if (ft_strchr(conv->flag, '0') != NULL)
			ft_padding_switch_core(p, conv, offset);
		else
			*(p->padding) = ft_strjoin_free(*(p->padding), ft_strdup(" "));
	}
	else
		*(p->padding) = ft_strjoin_free(*(p->padding), ft_strdup(" "));
}

static void	ft_do_padding_switch_4(t_conv *conv, char **ret,
		int offset, char *padding)
{
	char	*tmp2;
	char	*tmp;

	tmp2 = NULL;
	tmp = NULL;
	if (ft_strchr(conv->flag, '#') != NULL
			&& ft_strchr("X", conv->conversion) != NULL
			&& ft_strcmp(*ret, "0") != 0)
		*ret = ft_strjoin_free(
				padding = ft_strjoin_free(ft_strdup("0X"), padding), *ret);
	else
	{
		if (ft_strchr(conv->flag, '-') != NULL)
		{
			*ret = ft_strjoin(
				(tmp2 = *ret) + offset,
					tmp = padding);
			if ((*ret)[ft_strlen(*ret) - 1] == '-')
			{
				(*ret)[ft_strlen(*ret) - 1] = '\0';
				*ret = ft_strjoin_free(ft_strdup("-"), *ret);
			}
		}
		else
		{
			if (**ret == '+')
			{
				*ret = ft_strjoin_free(ft_strdup("+"), ft_strjoin(
							tmp = padding,
							(tmp2 = *ret) + offset + 1));
			}
			else
				*ret = ft_strjoin(
						tmp = padding,
						(tmp2 = *ret) + offset);
		}
	}
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

static void	ft_do_padding_switch_3(t_conv *conv, char **ret,
		int offset, char *padding)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (ft_strchr(conv->flag, '#') != NULL
			&& ft_strchr("x", conv->conversion) != NULL
			&& ft_strcmp(*ret, "0") != 0)
	{
		if (conv->precision_pos != -1 && ft_strcmp(*ret, "") == 0
				&& ft_strcmp(*ret, "0") != 0)
			*ret = ft_strjoin_free(padding, *ret);
		else
		{
			while (padding[i] == ' ')
				i++;
			if (i - 1 > 0 && i - 2 >= 0)
			{
				if (ft_strchr(conv->flag, '-') == NULL)
				{
					padding[i - 2] = '0';
					padding[i - 1] = 'x';
					*ret = ft_strjoin_free(
							padding, *ret);
				}
				else
				{
					if ((int)(ft_strlen(padding) - 2) >= 0)
						padding[ft_strlen(padding) - 2] = '\0';
					*ret = ft_strjoin_free(ft_strdup("0x"), ft_strjoin_free(
								*ret, padding));
					ft_strdel(&tmp);
				}
			}
			else
			{
				if (conv->padding_pos != -1)
				{
					padding[0] = '0';
					padding[1] = 'x';
					*ret = ft_strjoin_free(
						padding, *ret);
				}
				else
					*ret = ft_strjoin_free(ft_strdup("0x"), *ret);

			}
		}
	}
	else
		ft_do_padding_switch_4(conv, ret, offset, padding);
	ft_strdel(&tmp);
}

static void	ft_do_padding_switch_2(t_conv *conv, char **ret,
		int offset, char *padding)
{
	char	*tmp2;
	char	*tmp;
	int		i;

	tmp2 = NULL;
	tmp = NULL;
	i = 0;
	if (ft_strchr(conv->flag, '0') != NULL && conv->conversion == 'p')
		*ret = ft_strjoin(
				(tmp2 = *ret),
				tmp = padding);
	else if (ft_strchr(conv->flag, '#') != NULL
			&& ft_strchr("Oo", conv->conversion) != NULL
			&& ft_strcmp(*ret, "0") != 0)
	{
		if (conv->precision_pos != -1 && ft_strlen(conv->precision) > 0
				&& ft_strcmp(conv->precision, "0") != 0)
			*ret = ft_strjoin_free(padding, *ret);
		else
		{
			if (ft_strchr(conv->flag, '-') == NULL)
			{
				while (padding[i] == ' ')
					i++;
				if (i - 1 >= 0)
				{
					padding[i - 1] = '0';
					*ret = ft_strjoin_free(padding, *ret);
				}
				else
					*ret = ft_strjoin_free(
					padding = ft_strjoin_free(ft_strdup("0"), padding), *ret);
			}
			else
			{
				if ((int)ft_strlen(padding) > 1)
				{
				*ret = ft_strjoin(ft_strdup("0"), *ret);
				padding[ft_strlen(padding) - 1] = '\0';
				*ret = ft_strjoin_free(*ret, padding);
				}
			}
		}
	}
	else
		ft_do_padding_switch_3(conv, ret, offset, padding);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

static void	ft_do_padding_switch(t_conv *conv, char **ret, int len, int offset)
{
	char		*padding;
	int			i;
	t_padding	p;

	i = 0;
	padding = ft_strnew(0);
	p.ret = ret;
	p.padding = &padding;
	p.i = &i;
	p.len = &len;
	if (ft_strcmp(conv->padding, "") != 0)
	{
		while (i < len)
		{
			ft_padding_switch(&p, conv, &offset);
			i++;
		}
	}
	ft_do_padding_switch_2(conv, ret, offset, padding);
}

static void	ft_do_padding(char **ret, t_conv *conv, int len)
{
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	while ((*ret)[i])
	{
		if (ft_strncmp((const char *)((*ret) + i), C_0, 16) == 0)
			len += 15;
		i++;
	}
	ft_do_padding_switch(conv, ret, len, offset);
}

static char	*ft_padding_ret_null(char *str, t_conv *conv, t_env *e)
{
	char	*ret;

	ret = ft_strnew(0);
	if (conv->flag_pos == -1 && conv->precision_pos == -1
			&& conv->conversion_pos == -1)
	{
		ft_do_padding(&ret, conv,
				(int)(ft_atoi(conv->padding) - ft_strlen(ret)) - 1);
		e->offset = ft_strlen(conv->padding) + 1;
	}
	else if ((ft_strchr(conv->flag, '-') != NULL
				|| ft_strchr(conv->flag, '0') != NULL)
			&& conv->conversion_pos == -1)
	{
		ft_strdel(&ret);
		ret = ft_char_to_str(str[ft_strlen(conv->padding)
				+ ft_strlen(conv->flag) + ((conv->precision_pos != -1
						&& ft_strcmp(conv->precision, "") == 0) ? (1) : (0))]);
		ft_do_padding(&ret, conv, (int)(ft_atoi(conv->padding)
					- ft_strlen(ret)));
		e->offset = ft_strlen(conv->padding) + ft_strlen(conv->flag)
			+ ((conv->precision_pos != -1
						&& ft_strcmp(conv->precision, "") == 0) ? (1) : (0)) + 2;
	}
	return (ret);
}

static void	ft_padding_ret_di_core(t_conv *conv, char **ret)
{
	int	i;

	i = 0;
	if (ft_strchr(*ret, '-') == NULL)
	{
		if (ft_strcmp(*ret, "0") != 0)
		{
			if (ft_strchr(conv->flag, '0') == NULL)
				*ret = ft_strjoin_free(ft_strdup(" "), *ret);
			else
				*ret = ft_strjoin_free(ft_strdup("0"), *ret);
			ft_do_padding(ret, conv, (int)(ft_atoi(conv->padding)
						- ft_strlen(*ret)));
			while ((*ret)[i] == ' ')
				i++;
			if (i - 1 >= 0)
				(*ret)[i - 1] = '+';
			else
				**ret = '+';
		}
		else
		{
			ft_do_padding(ret, conv, (int)(ft_atoi(conv->padding)
						- ft_strlen(*ret)));
				if (**ret != '0' || ft_strchr(conv->flag, '0') != NULL)
					**ret = '+';
				else if (ft_strlen(conv->flag) == 1 && ft_strchr(conv->flag, '+') != NULL && conv->padding_pos == -1)
					*ret = ft_strjoin_free(ft_strdup("+"), *ret);
		}
	}
	else
			ft_do_padding(ret, conv, (int)(ft_atoi(conv->padding)
						- ft_strlen(*ret)));
}

static void	ft_padding_ret_di(t_conv *conv, char **ret, t_env *e)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr("di", conv->conversion) && ft_strcmp(conv->flag, " 0") == 0
			&& ft_strcmp(*ret, "0") == 0)
	{
		ft_do_padding(ret, conv, (int)(ft_atoi(conv->padding)
					- ft_strlen(*ret)));
		**ret = ' ';
	}
	else if (ft_strchr("di", conv->conversion)
			&& ft_strchr(conv->flag, '+') != NULL)
		ft_padding_ret_di_core(conv, ret);
	else if (ft_strchr("di", conv->conversion)
			&& ft_strchr(conv->flag, ' ') != NULL
			&& conv->conversion_pos == 1
			&& conv->flag_pos == 0 && ft_atoi(*ret) > 0)
		*ret = ft_strjoin_free(ft_strdup(" "), *ret);
	else
	{
		if (ft_atoi(*ret) < 0)
		{
		ft_do_padding(ret, conv, (int)(ft_atoi(conv->padding)
					- ft_strlen(*ret)));
			while (ft_strchr(conv->flag, '0') != NULL && ft_strlen(conv->flag) == 1 && (tmp = ft_strchr(*ret, ' ')) != NULL)
				*tmp = '0';
		}
		else
		{
			if (ft_strcmp(conv->flag, " 0") == 0
				|| ft_strcmp(conv->flag, "0 ") == 0)
				*ret = ft_strjoin_free(ft_strdup(" "), *ret);
			else
				ft_do_padding(ret, conv, (int)(ft_atoi(conv->padding)
					- ft_strlen(*ret)));
		}
	}
	e->offset = conv->conversion_pos + 2;
}

static void	ft_padding_ret(t_conv *conv, char **ret, t_env *e)
{
	char	*tmp;

	tmp = NULL;
	if (conv->precision_pos != -1 && ft_strchr("p", conv->conversion) != NULL
			&& *ret != NULL && ft_strcmp(conv->flag, "") == 0)
	{
		if (ft_atoi(conv->padding) > ft_atoi(conv->precision))
		{
			while (((int)ft_strlen(*ret) - 2) < ft_atoi(conv->precision))
				*ret = ft_strjoin_free(*ret, ft_strdup("0"));
		}
		else if (ft_strncmp(*ret, "0x", 2) == 0)
		{
			tmp = *ret;
			*ret = ft_strdup(*ret + 2);
			ft_strdel(&tmp);
			while (((int)ft_strlen(*ret) - 2) < ft_atoi(conv->precision))
				*ret = ft_strjoin_free(ft_strdup("0"), *ret);
			(*ret)[0] = '0';
			(*ret)[1] = 'x';
		}
	}
	ft_padding_ret_di(conv, ret, e);
}

static void	ft_store_padding_core(char *str, t_conv *conv, int *i, int *n)
{
	while ((ft_isdigit(str[*i + *n]) && ((*i + *n) < conv->conversion_pos))
			|| (ft_isdigit(str[*i + *n]) && conv->conversion_pos == -1))
	{
		if (((conv->precision_pos != -1)
					&& ((*i + *n) < conv->precision_pos))
				|| (conv->precision_pos == -1))
		{
			if (conv->padding_pos == -1)
				conv->padding_pos = *i + *n;
			conv->padding = ft_strjoin_free(conv->padding,
					ft_char_to_str(str[*i + *n]));
		}
		(*n)++;
	}
}

static void	ft_store_padding(char *str, t_conv *conv)
{
	int		i;
	int		n;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		n = 0;
		if (((str[i + n] > '0' && str[i + n] <= '9')
					&& ((i + n) < conv->conversion_pos))
				|| ((str[i + n] > '0' && str[i + n] <= '9')
					&& conv->conversion_pos == -1))
		{
			ft_store_padding_core(str, conv, &i, &n);
			break ;
		}
		i++;
	}
}

char	*ft_get_padding(char *str, t_env *e)
{
	t_conv	conv;
	char	*ret;
	char	*tmp;

	tmp = NULL;
	ft_init_conv(&conv);
	ret = ft_get_flags(str, &conv, e);
	ft_store_padding(str, &conv);
	if (ret == NULL)
		ret = ft_padding_ret_null(str, &conv, e);
	else
		ft_padding_ret(&conv, &ret, e);
	ft_strdel(&conv.flag);
	ft_strdel(&conv.padding);
	ft_strdel(&conv.precision);
	ft_strdel(&conv.modifier);
	return (ret);
}
