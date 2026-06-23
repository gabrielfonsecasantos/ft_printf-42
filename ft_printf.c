/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:31:52 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/23 12:58:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

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

int	ft_putnbr_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putnbr_unsigned(num / 10);
	num = (num % 10) + '0';
	len += write(1, &num, 1);
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
			// checks if the conversion is to char
			if (*str == 'c')
			{
				c = va_arg(list, int);
				counter += write(1, &c, 1);
			}
			// cheks if the conversion is to string
			if (*str == 's')
			{
				s = va_arg(list, char *);
				if (!s)
					s = "(null)";
				counter += write(1, s, ft_strlen(s));
			}
			// checks if the conversion is to an int
			if (*str == 'i' || *str == 'd')
				counter += ft_putnbr(va_arg(list, int));
			// checks if the conversion is to an unsigned int
			if (*str == 'u')
				counter += ft_putnbr_unsigned(va_arg(list, unsigned int));
			// checks if is necessary to print a % sign
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
	ft_printf("%s, %c, %i, %u.", "alou", '0', -214748364, a);
	printf("\n");
	printf("%s, %c, %i, %u.", "alou", 'a', -214748364, a);
	return (0);
}
*/