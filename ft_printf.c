/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:31:52 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/23 16:54:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static int	ft_strlen(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

static int	ft_putnbr(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len += write(1, "-", 1);
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	num = (num % 10) + '0';
	len += write(1, &num, 1);
	return (len);
}

static int	ft_putnbr_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putnbr_unsigned(num / 10);
	num = (num % 10) + '0';
	len += write(1, &num, 1);
	return (len);
}

static int	ft_putnbr_hex(unsigned int n, int u)
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
	len += write(1, &c, 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	char	c;
	char	*s;
	int		counter;

	counter = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				c = va_arg(list, int);
				counter += write(1, &c, 1);
			}
			if (*str == 's')
			{
				s = va_arg(list, char *);
				if (!s)
					s = "(null)";
				counter += write(1, s, ft_strlen(s));
			}
			if (*str == 'i' || *str == 'd')
				counter += ft_putnbr(va_arg(list, int));
			if (*str == 'u')
				counter += ft_putnbr_unsigned(va_arg(list, unsigned int));
			if (*str == 'x')
				counter += ft_putnbr_hex(va_arg(list, unsigned int), 0);
			if (*str == 'X')
				counter += ft_putnbr_hex(va_arg(list, unsigned int), 1);
			if (*str == '%')
				counter += write(1, "%", 1);
			str++;
		}
		else
		{
			c = *str;
			counter += write(1, &c, 1);
			str++;
		}
	}
	va_end(list);
	return (counter);
}

/*int	main(void)
{
	unsigned int	a;

	a = 3000000000;
	ft_printf("%s, %c, %i, %X.", "alou", '0', -214748364, 255);
	printf("\n");
	printf("%s, %c, %i, %X.", "alou", 'a', -214748364, 255);
	return (0);
}
*/
