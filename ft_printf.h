/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:10:49 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/04 15:28:46 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

typedef struct	s_env
{
		int		offset;
		char	*str;
		va_list	*ap;
		char	*res;
		char	*ret;
		char	*tmp;
		int		len_add;
}				t_env;

/*
** abcdef%#-45.12ldghijkl
*/
typedef struct	s_conv
{
	char		*modifier; // l
	char		conversion; // d (pos of the conversion in string to test if format ok)
	int			conversion_pos; // d (pos of the conversion in string to test if format ok)
	char		*flag; // #-
	int			flag_pos; // #-
	char		*precision; // .12
	int			precision_pos; // .12
	char		*padding; // 45
	int			padding_pos;
}				t_conv;

int		ft_printf(char *str, ...);
void	ft_init_conv(t_conv *conv);

/*
** utils.c
*/
char	*ft_char_to_str(char c);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_putstr_0(char *str);

/*
** conversion.c
*/
char	*ft_get_conversion(char *str, t_conv *conv, t_env *e);

/*
** precision.c
*/
char	*ft_get_precision(char *str, t_conv *conv, t_env *e);

/*
** flags.c
*/
char	*ft_get_flags(char *str, t_conv *conv, t_env *e);

/*
** padding.c
*/
char	*ft_get_padding(char *str, t_env *e);

#endif
