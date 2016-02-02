/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:09:41 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/02 22:35:37 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	ft_init_conv(t_conv *conv)
{
	conv->modifier = ft_strnew(0);
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
	if (ft_strcmp(s, "%") == 0)
	{
		env.res = ft_strdup("");
		len = 0;
	}
	else
	{
		while (i < len && (env.ret = ft_strchr(env.str + i, '%')) != NULL)
		{
			*env.ret = '\0';
			env.res = ft_strjoin_free(env.res, ft_strjoin(env.str + i,
							env.tmp = ft_get_padding(env.ret + 1, &env)));
			i += (int)(env.ret - (env.str + i)) + env.offset;
			ft_strdel(&env.tmp);
		}
		if (i < len)
		{
			env.res = ft_strjoin(env.tmp = env.res, env.str + i);
			ft_strdel(&env.tmp);
		}
		len = ft_strlen(env.res);
		len -= ft_putstr_0(env.res) * 3;
	}
	va_end(*(env.ap));
	ft_strdel(&env.res);
	ft_strdel(&env.str);
	return (len);
}
