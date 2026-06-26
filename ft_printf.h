/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:32:54 by gabriel           #+#    #+#             */
/*   Updated: 2026/06/26 10:43:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(char *s);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putptr_hex(unsigned long num);
int	ft_putptr(void *ptr);
int	ft_putnbr_unsigned(unsigned int num);
int	ft_putnbr_hex(unsigned int n, int u);

#endif