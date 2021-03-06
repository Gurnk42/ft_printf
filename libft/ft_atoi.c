/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 17:59:38 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/29 17:57:03 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(int chr)
{
	return ((chr >= 9 && chr <= 13) || chr == 32);
}

static const char	*ft_atoi_init(const char *nptr, int *neg)
{
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		*neg = ((*nptr == '-') ? 1 : 0);
		nptr++;
	}
	return (nptr);
}

int					ft_atoi(const char *nptr)
{
	int				result;
	unsigned int	digit;
	int				neg;

	result = 0;
	digit = 0;
	neg = 0;
	nptr = ft_atoi_init(nptr, &neg);
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = *nptr - '0';
		if (digit > 9)
			break ;
		if (!neg && (double)(result * 10 + digit) > 2147483647)
			return (2147483647);
		else if (neg && (double)((-result) * 10 + digit) < -2147483648)
			return (-2147483648);
		result = result * 10 + digit;
		nptr++;
	}
	if (neg)
		return (-result);
	return (result);
}
