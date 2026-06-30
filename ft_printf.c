/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviniciu <gviniciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:31:52 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/30 19:18:30 by gviniciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatter(char c, va_list *list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*list, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*list, void *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(*list, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*list, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(*list, unsigned int), 0));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(*list, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		counter;
	int		ret;

	if (!str)
		return (-1);
	counter = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
			ret = ft_formatter(*(++str), &list);
		else
			ret = ft_putchar(*str);
		if (ret == -1)
		{
			va_end(list);
			return (-1);
		}
		counter += ret;
		str++;
	}
	va_end(list);
	return (counter);
}
