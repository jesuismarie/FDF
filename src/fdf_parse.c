/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:14:42 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/22 20:42:13 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*read_str(char *file)
{
	char	s;
	char	*buf;
	int		fd;
	int		n;

	n = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &s, 1) > 0)
		n++;
	close(fd);
	fd = open(file, O_RDONLY);
	buf = malloc(n + 1);
	read(fd, buf, n);
	buf[n] = 0;
	close(fd);
	return (buf);
}

char	**splited_map(char *file)
{
	char	*s;
	char	**spl_nl;

	s = read_str(file);
	spl_nl = ft_split(s, '\n');
	free(s);
	return (spl_nl);
}

void	get_wh(t_fdf *map, char **str)
{
	map->height = 0;
	while (str[map->height])
		map->height++;
	map->width = word_count(str[0], ' ');
}

static void	create_matrix(t_fdf *map, int x, int y)
{
	int	i;

	i = 0;
	map->z_matrix = (int **)malloc(sizeof(int *) * y);
	map->mat = (int **)malloc(sizeof(int *) * y);
	while (i < y)
	{
		map->z_matrix[i] = (int *)malloc(sizeof(int) * x);
		map->mat[i] = (int *)malloc(sizeof(int) * x);
		i++;
	}
}

void	fill_matrix(char **str, t_fdf *map)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	j = 0;
	create_matrix(map, map->width, map->height);
	while (i < map->height)
	{
		s = ft_split(str[i], ' ');
		j = 0;
		while (j < map->width)
		{
			map->z_matrix[i][j] = ft_atoi(s[j]);
			map->mat[i][j] = ft_atoi(s[j]);
			j++;
		}
		free_malloc(s);
		free(str[i]);
		i++;
	}
	free(str);
}
