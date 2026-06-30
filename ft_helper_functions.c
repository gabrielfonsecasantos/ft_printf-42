/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviniciu <gviniciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:59:55 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/30 18:22:25 by gviniciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);

int	ft_putnbr_hex(unsigned int n, int u)
{
	int		len;
	int		ret;
	char	c;

	len = 0;
	if (n >= 16)
	{
		ret = ft_putnbr_hex(n / 16, u);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	c = n % 16;
	if (c < 10)
		c = c + '0';
	else if (u == 1)
		c = c - 10 + 'A';
	else
		c = c - 10 + 'a';
	ret = ft_putchar(c);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

int	ft_putptr_hex(unsigned long num)
{
	int		len;
	int		ret;
	char	c;

	len = 0;
	if (num >= 16)
	{
		ret = ft_putptr_hex(num / 16);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	c = num % 16;
	if (c < 10)
		c = c + '0';
	else
		c = c - 10 + 'a';
	ret = ft_putchar(c);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	int				ret;
	unsigned long	addr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	addr = (unsigned long)ptr;
	len = ft_putstr("0x");
	if (len == -1)
		return (-1);
	ret = ft_putptr_hex(addr);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

int	ft_putnbr_unsigned(unsigned int num)
{
	int	len;
	int	ret;

	len = 0;
	if (num >= 10)
	{
		ret = ft_putnbr_unsigned(num / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	num = (num % 10) + '0';
	ret = ft_putchar(num);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
