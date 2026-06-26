/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:59:55 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/26 10:47:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);

int	ft_putnbr_hex(unsigned int n, int u)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_putnbr_hex(n / 16, u);
	c = n % 16;
	if (c < 10)
		c = c + '0';
	else if (u == 1)
		c = c - 10 + 'A';
	else
		c = c - 10 + 'a';
	len += ft_putchar(c);
	return (len);
}

int	ft_putptr_hex(unsigned long num)
{
	int		len;
	char	c;

	len = 0;
	if (num >= 16)
		len += ft_putptr_hex(num / 16);
	c = num % 16;
	if (c < 10)
		c = c + '0';
	else
		c = c - 10 + 'a';
	len += ft_putchar(c);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	addr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	len = ft_putstr("0x");
	len += ft_putptr_hex(addr);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putnbr_unsigned(num / 10);
	num = (num % 10) + '0';
	len += ft_putchar(num);
	return (len);
}
