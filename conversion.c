/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:08:31 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/02 22:57:27 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

char	*ft_get_conversion(char *str, t_conv *conv, t_env *e)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	tmp = NULL;	
	ret = NULL;
	if (ft_strchr("hljz sSpdDioOuUxXcC% .1234567890#", str[i]) == NULL)
		return (ft_strnew(0));
	while (str[i])
	{
		if (ft_strchr("sSpdDioOuUxXcC%", str[i]) != NULL)
		{
			conv->conversion = str[i];
			conv->conversion_pos = i;
			break ;
		}
		else if (ft_strchr("hljz .1234567890#", str[i]) == NULL)
			break ;
		i++;
	}
	if (conv->conversion == 0)
		return (NULL);
	// GET MODIFIER
	if (conv->conversion_pos >= 2)
	{
		i = 0;
		while (i < 2)
		{
			if (ft_strchr("hljz", str[(conv->conversion_pos - 2) + i]) != NULL)
				conv->modifier = ft_strjoin_free(conv->modifier,
						ft_char_to_str(str[(conv->conversion_pos - 2) + i]));
			i++;
		}
	}
	if (conv->conversion == 'c')
		ret = ft_char_to_str((char)va_arg(*(e->ap), int));
	else if (conv->conversion == 's')
	{
		if ((ret = ft_strdup((char *)va_arg(*(e->ap), char *))) == NULL)
		{
			ft_memdel((void **)&ret);
			ret = ft_strdup("(null)");
		}
	}
	else if (conv->conversion == 'd' || conv->conversion == 'i')
		ret = ft_itoa((int)va_arg(*(e->ap), int));
	else if (conv->conversion == 'u' || conv->conversion == 'U')
		ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789");
	else if (conv->conversion == 'x')
		ret = ft_lltoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789abcdef");
	else if (conv->conversion == 'X')
		ret = ft_lltoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789ABCDEF");
	else if (conv->conversion == 'p')
	{
		if ((ret = ft_llntoa_base((unsigned long)va_arg(*(e->ap), void *),
						(char *)"0123456789abcdef")) == NULL)
		{
			ft_memdel((void **)&ret);
			ret = ft_strdup("(null)");
		}
		else
			ret = ft_strjoin_free(ft_strdup("0x"), ret);
	}
	else if (conv->conversion == '%')
		ret = ft_strdup("%");
	else if (conv->conversion == 'D')
		ret = ft_lltoa_base((long long)va_arg(*(e->ap), long), "0123456789");
	else if (conv->conversion == 'o' || conv->conversion == 'O')
		ret = ft_lltoa_base((long long)va_arg(*(e->ap), long long),
				(char *)"01234567");
	return (ret);
}
