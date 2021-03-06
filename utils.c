/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 20:05:07 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/06 16:06:33 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_to_str(char c)
{
	char	*ret;

	if (c != 0)
	{
		ret = ft_strnew(1);
		*ret = c;
	}
	else
		ret = ft_strdup(C_0);
	return (ret);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	if ((join = (char *)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (join);
}

int		ft_putstr_0(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (ft_strncmp((const char *)(str + i), C_0, 16) == 0)
		{
			ret++;
			ft_putchar('\0');
			i += 15;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (ret);
}
