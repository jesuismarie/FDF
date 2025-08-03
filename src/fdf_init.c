/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:08:29 by mnazarya          #+#    #+#             */
/*   Updated: 2025/08/03 14:14:19 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	get_wh(t_fdf *map, char **str)
{
	map->height = 0;
	while (str[map->height])
		map->height++;
	map->width = word_count(str[0], ' ');
}

static void	find_min_max_z(t_fdf *map)
{
	int	i;
	int	j;

	map->max_z = map->z_matrix[0][0];
	map->min_z = map->z_matrix[0][0];
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->z_matrix[i][j] > map->max_z)
				map->max_z = map->z_matrix[i][j];
			if (map->z_matrix[i][j] < map->min_z)
				map->min_z = map->z_matrix[i][j];
		}
	}
}

void	scale(t_fdf *map)
{
	float	proj_height;
	float	proj_width;
	float	map_size;
	float	z_range;

	find_min_max_z(map);
	proj_width = (map->width + map->height) * cos(map->angle);
	proj_height = (map->width + map->height) * sin(map->angle);
	if (proj_height < proj_width)
		map->zoom = (WIN_Y - 500) / proj_height;
	else
		map->zoom = (WIN_X - 500) / proj_width;
	map->z_scale = 0.5;
	if (map->max_z != map->min_z)
	{
		map_size = (map->width + map->height) / 2.0;
		z_range = map->max_z - map->min_z;
		map->z_scale = (map_size / z_range) * 0.15;
		if (map->z_scale < 0.05)
			map->z_scale = 0.05;
		if (map->z_scale > 2.0)
			map->z_scale = 2.0;
	}
	map->cx = WIN_X / 2;
	map->cy = WIN_Y / 4;
}

void	img_init(t_fdf *map)
{
	if (map->img.img)
		mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, WIN_X, WIN_Y);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp,
			&map->img.l, &map->img.end);
	draw(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
}

void	set_default(t_fdf *map, char *file, char **str)
{
	get_wh(map, str);
	map->angle = 0.8;
	map->z_angle = 0.0;
	fill_matrix(str, map);
	scale(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_X, WIN_Y, file);
	img_init(map);
}
