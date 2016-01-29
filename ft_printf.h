/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:10:49 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/29 15:39:19 by ebouther         ###   ########.fr       */
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
}				t_conv;

int	ft_printf(char *str, ...);

/*
** utils.c
*/
char	*ft_char_to_str(char c);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
