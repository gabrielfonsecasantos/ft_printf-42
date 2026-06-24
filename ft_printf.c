/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:31:52 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/24 13:38:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_strlen(char *s);
int			ft_putnbr(int n);
int			ft_putstr(char *str);
int			ft_putchar(char c);

/*static int	ft_putptr(void *ptr)
{
	return (0);
}
*/

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

int	ft_formatter(char *str, va_list list)
{
	int	ret;

	if (*str == 'c')
		ret = ft_putchar(va_arg(list, int));
	if (*str == 's')
		ret = ft_putstr(va_arg(list, char *));
	if (*str == 'i' || *str == 'd')
		ret = ft_putnbr(va_arg(list, int));
	if (*str == 'u')
		ret = ft_putnbr_unsigned(va_arg(list, unsigned int));
	if (*str == 'x')
		ret = ft_putnbr_hex(va_arg(list, unsigned int), 0);
	if (*str == 'X')
		ret = ft_putnbr_hex(va_arg(list, unsigned int), 1);
	if (*str == '%')
		ret = write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		counter;
	int		ret;

	counter = 0;
	ret = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			ret += ft_formatter((char *)++str, list);
			if (ret == -1)
				return (-1);
			str++;
		}
		else
		{
			ret += ft_putchar(*str);
			if (ret == -1)
				return (-1);
			str++;
		}
	}
	va_end(list);
	return (counter + ret);
}

/*int	main(void)
{
	unsigned int	a;

	a = 3000000000;
	ft_printf("%s, %c, %i, %X.", "alou", '0', -214748364, 255);
	printf("\n");
	printf("%s, %c, %i, %X.", "alou", 'a', -214748364, 255);
	return (0);
}*/