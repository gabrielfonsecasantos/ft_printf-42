/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviniciu <gviniciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:13:57 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/30 19:15:56 by gviniciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

int	ft_putnbr(int n)
{
	long	num;
	int		len;
	int		ret;

	num = n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
	}
	if (num >= 10)
	{
		ret = ft_putnbr(num / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar((num % 10) + '0');
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}
