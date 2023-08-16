/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:39:49 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/18 13:30:24 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_hex(n, 1);
	return (count);
}

int	ft_check(const char *str, va_list arg)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (*str == 'x')
		count += ft_hex((unsigned long long)va_arg(arg, unsigned int), 1);
	else if (*str == 'X')
		count += ft_hex((unsigned long long)va_arg(arg, unsigned int), 0);
	else if (*str == '%')
		count += ft_putchar('%');
	else if (*str == 'u')
		count += ft_putnbr_u(va_arg(arg, unsigned int));
	else if (*str == 'p')
		count += ft_ptr(va_arg(arg, unsigned long long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_check(str, arg);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (count);
}
