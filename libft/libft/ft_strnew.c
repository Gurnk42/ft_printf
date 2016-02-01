/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:07:25 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/23 14:38:06 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (str[i])
		str[i++] = '\0';
	return (str);
}
