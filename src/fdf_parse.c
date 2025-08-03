/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:14:42 by mnazarya          #+#    #+#             */
/*   Updated: 2025/08/03 14:10:52 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

static void	create_matrix(t_fdf *map, int x, int y)
{
	int	i;

	i = 0;
	map->z_matrix = (float **)malloc(sizeof(float *) * y);
	map->mat = (float **)malloc(sizeof(float *) * y);
	map->color_matrix = (int **)malloc(sizeof(int *) * y);
	while (i < y)
	{
		map->z_matrix[i] = (float *)malloc(sizeof(float) * x);
		map->mat[i] = (float *)malloc(sizeof(float) * x);
		map->color_matrix[i] = (int *)malloc(sizeof(int) * x);
		i++;
	}
}

void	fill_matrix(char **str, t_fdf *map)
{
	int		i;
	int		j;
	char	**s;
	int		color;

	i = 0;
	j = 0;
	create_matrix(map, map->width, map->height);
	while (i < map->height)
	{
		s = ft_split(str[i], ' ');
		j = 0;
		while (j < map->width)
		{
			map->z_matrix[i][j] = ft_atoi_with_color(s[j], &color);
			map->mat[i][j] = map->z_matrix[i][j];
			map->color_matrix[i][j] = color;
			j++;
		}
		free_malloc(s);
		free(str[i]);
		i++;
	}
	free(str);
}
