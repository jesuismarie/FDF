/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:39:55 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/08 11:39:55 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(s);
	write(1, s, count);
	return (count);
}

int	ft_hex(unsigned long long n, short x)
{
	int	count;

	count = 0;
	if (x)
	{
		if (n < 16)
			count += ft_putchar("0123456789abcdef"[n % 16]);
		else
		{
			count += ft_hex(n / 16, x);
			count += ft_putchar("0123456789abcdef"[n % 16]);
		}
	}
	else
	{
		if (n < 16)
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		else
		{
			count += ft_hex(n / 16, x);
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		}	
	}
	return (count);
}
