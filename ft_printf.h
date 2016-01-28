/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:10:49 by ebouther          #+#    #+#             */
/*   Updated: 2016/01/28 21:32:35 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

/*
** abcdef%#-45.12ldghijkl
*/
typedef struct	s_conv
{
	char		*modifier; // l
	char		conversion; // d
	char		*flag; // #-
	char		*precision; // .12
	char		*padding; // 45
}				t_conv;

void	ft_printf(char *str, ...);

/*
** utils.c
*/
char	*ft_char_to_str(char c);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
