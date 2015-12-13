/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:09:41 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/19 23:38:09 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_arg(va_list *ap, char *str)
{
	if (*str == '%')
		ft_putchar('%');
	else if (*str == 'c')
		ft_putchar((char)va_arg(*ap, int));
	else if(*str == 's')
		ft_putstr((char *)va_arg(*ap, char *));
	else if(*str == 'd' || *str == 'i')
		ft_putnbr((int)va_arg(*ap, int));
}

void	ft_printf(char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			ft_print_arg(&ap, ++str);
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
}

