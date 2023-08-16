/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:59 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/01 16:23:59 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;

	b = (char)c;
	i = ft_strlen((char *)s);
	while (i > 0)
	{
		if (s[i] == b)
			return ((char *)s + i);
		i--;
	}
	if (s[0] == b)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c++;
	return (c);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (!ptr)
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	n = ft_strlen(s);
	if ((size_t)start >= n)
		return (ft_strdup(""));
	if (len > n - (size_t)start)
		len = n - (size_t)start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	j = 1;
	while (nptr[i] == '\n' || nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\f' || nptr[i] == '\v' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j = -j;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		nb = (nb * 10) + (nptr[i++] - 48);
	return (nb * j);
}
