/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:57:15 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/01 15:57:15 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
	return (1);
}

int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	**fill_str(char **store, char const *str, char c)
{
	size_t		len;
	size_t		i;
	char const	*st;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (*str && *str != c)
			{
				len++;
				str++;
			}
			st = str - len;
			store[i] = ft_substr(st, 0, len);
			if (!store[i++])
				return (0);
		}
		else
			str++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_str;
	size_t	len;

	if (!s)
		return (0);
	len = word_count(s, c);
	splited_str = malloc(sizeof(char *) * (len + 1));
	if (!splited_str)
		return (0);
	splited_str = fill_str(splited_str, s, c);
	if (!splited_str && free_malloc(splited_str))
		return (0);
	return (splited_str);
}

void	set_default(t_fdf *map, char *file, char **str)
{
	get_wh(map, str);
	map->angle = 0.8;
	scale(map);
	fill_matrix(str, map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_X, WIN_Y, file);
	img_init(map);
}
