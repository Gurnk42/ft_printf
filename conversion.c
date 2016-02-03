/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:08:31 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/03 17:24:35 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_conversion(char *str, t_conv *conv, t_env *e)
{
	char	*tmp;
	char	*ret;
	int		i;
	char	*buf;
//	wchar_t	*wstr;

	buf = NULL;
	i = 0;
	tmp = NULL;	
	ret = NULL;
	if (ft_strchr("hljz sSpdDioOuUxXcC% .1234567890 #0-+", str[i]) == NULL)
		return (ft_strnew(0));
	while (str[i])
	{
		if (ft_strchr("sSpdDioOuUxXcC%", str[i]) != NULL)
		{
			conv->conversion = str[i];
			conv->conversion_pos = i;
			break ;
		}
		else if (ft_strchr("hljz .1234567890 #0-+", str[i]) == NULL)
			break ;
		i++;
	}
	if (conv->conversion == 0)
		return (NULL);
	// GET MODIFIER
	if (conv->conversion_pos >= 1)
	{
		i = 0;
		while (i <= conv->conversion_pos)
		{
			//DO NOT STRCHR to protect from '\0'
			if (str[(conv->conversion_pos - 2) + i] == 'h' ||
				str[(conv->conversion_pos - 2) + i] == 'l' ||
					str[(conv->conversion_pos - 2) + i] == 'j' ||
						str[(conv->conversion_pos - 2) + i] == 'z')
				conv->modifier = ft_strjoin_free(conv->modifier,
						ft_char_to_str(str[(conv->conversion_pos - 2) + i]));
			i++;
		}
	}
	if (conv->conversion == 'c')
		ret = ft_char_to_str((char)va_arg(*(e->ap), int));
	else if (conv->conversion == 'C')
	{
		buf = ft_strnew(4);
		ft_utf8_encode(buf, (wchar_t)va_arg(*(e->ap), wchar_t));
		if (*buf == '\0')
			ret = ft_strdup("0x00");
		else
			ret = ft_strdup(buf);
		ft_strdel(&buf);
	}
	else if (conv->conversion == 's')
	{
		if ((ret = ft_strdup((char *)va_arg(*(e->ap), char *))) == NULL)
		{
			ft_memdel((void **)&ret);
			ret = ft_strdup("(null)");
		}
	}
/*	else if (conv->conversion == 'S')
	{
		ret = ft_strnew(0);
		wstr = (wchar_t *)va_arg(*(e->ap), wchar_t *);
		i = 0;
		while (wstr[i])
		{
			ft_utf8_encode(buf, wstr[i]);
			ret = ft_strjoin(ret, ft_strdup(buf)); //LEAKS !!!
			i++;
		}
	}*/
	else if (conv->conversion == 'd' || conv->conversion == 'i')
	{
		if (ft_strcmp(conv->modifier, "l") == 0)
			ret = ft_lltoa_base((long long)va_arg(*(e->ap), long int), "0123456789");
		else if (ft_strcmp(conv->modifier, "ll") == 0)
			ret = ft_lltoa_base((long long)va_arg(*(e->ap), long long int), "0123456789");
		else if (ft_strcmp(conv->modifier, "h") == 0)
			ret = ft_lltoa_base((short int)va_arg(*(e->ap), int), "0123456789");
		else if (ft_strcmp(conv->modifier, "hh") == 0)
			ret = ft_lltoa_base((signed char)va_arg(*(e->ap), int), "0123456789");
		else if (ft_strcmp(conv->modifier, "j") == 0)
			ret = ft_lltoa_base((intmax_t)va_arg(*(e->ap), unsigned long long), "0123456789");
		else if (ft_strcmp(conv->modifier, "z") == 0)
			ret = ft_lltoa_base((size_t)va_arg(*(e->ap), unsigned long long), "0123456789");
		else
			ret = ft_itoa((int)va_arg(*(e->ap), int));
	}
	else if (conv->conversion == 'u')
	{
		if (ft_strcmp(conv->modifier, "l") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long), "0123456789");
		else if (ft_strcmp(conv->modifier, "ll") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long long), "0123456789");
		else if (ft_strcmp(conv->modifier, "h") == 0)
			ret = ft_llntoa_base((unsigned short)va_arg(*(e->ap), unsigned int), "0123456789");
		else if (ft_strcmp(conv->modifier, "hh") == 0)
			ret = ft_llntoa_base((unsigned char)va_arg(*(e->ap), unsigned int), "0123456789");
		else
		ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789");
	}
	else if (conv->conversion == 'U')
		ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789");
	else if (conv->conversion == 'x')
	{
		if (ft_strcmp(conv->modifier, "l") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long), "0123456789abcdef");
		else if (ft_strcmp(conv->modifier, "ll") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long long), "0123456789abcdef");
		else if (ft_strcmp(conv->modifier, "h") == 0)
			ret = ft_llntoa_base((unsigned short)va_arg(*(e->ap), unsigned int), "0123456789abcdef");
		else if (ft_strcmp(conv->modifier, "hh") == 0)
			ret = ft_llntoa_base((unsigned char)va_arg(*(e->ap), unsigned int), "0123456789abcdef");
		else
			ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789abcdef");
	}
	else if (conv->conversion == 'X')
	{
		if (ft_strcmp(conv->modifier, "l") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long), "0123456789ABCDEF");
		else if (ft_strcmp(conv->modifier, "ll") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long long), "0123456789ABCDEF");
		else if (ft_strcmp(conv->modifier, "h") == 0)
			ret = ft_llntoa_base((unsigned short)va_arg(*(e->ap), unsigned int), "0123456789ABCDEF");
		else if (ft_strcmp(conv->modifier, "hh") == 0)
			ret = ft_llntoa_base((unsigned char)va_arg(*(e->ap), unsigned int), "0123456789ABCDEF");
		else
		ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap),
					unsigned long long), "0123456789ABCDEF");
	}
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
	else if (conv->conversion == 'o')
	{
		if (ft_strcmp(conv->modifier, "l") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long), "01234567");
		else if (ft_strcmp(conv->modifier, "ll") == 0)
			ret = ft_llntoa_base((long long)va_arg(*(e->ap), unsigned long long), "01234567");
		else if (ft_strcmp(conv->modifier, "h") == 0)
			ret = ft_llntoa_base((unsigned short)va_arg(*(e->ap), unsigned int), "01234567");
		else if (ft_strcmp(conv->modifier, "hh") == 0)
			ret = ft_llntoa_base((unsigned char)va_arg(*(e->ap), unsigned int), "01234567");
		else
			ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap), unsigned long long),
				(char *)"01234567");
	}
	else if (conv->conversion == 'O')
		ret = ft_llntoa_base((unsigned long long)va_arg(*(e->ap), unsigned long long),
			(char *)"01234567");
	return (ret);
}
