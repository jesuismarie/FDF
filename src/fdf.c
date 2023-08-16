/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:22:24 by mnazarya          #+#    #+#             */
/*   Updated: 2023/08/16 19:30:51 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	colours(t_fdf *map, t_line c)
{
	if (abs(map->z_matrix[(int)c.y1][(int)c.x1]) == 0)
		map->color = 0xfae20a;
	if (abs(map->z_matrix[(int)c.y1][(int)c.x1]) > 0 && \
		abs(map->z_matrix[(int)c.y1][(int)c.x1]) <= 20)
		map->color = 0x42f587;
	if (abs(map->z_matrix[(int)c.y1][(int)c.x1]) > 20 && \
		abs(map->z_matrix[(int)c.y1][(int)c.x1]) <= 80)
		map->color = 0xff0000;
	if (abs(map->z_matrix[(int)c.y1][(int)c.x1]) > 80 && \
		abs(map->z_matrix[(int)c.y1][(int)c.x1]) <= 200)
		map->color = 0x4287f5;
	if (abs(map->z_matrix[(int)c.y1][(int)c.x1]) > 200 && \
		abs(map->z_matrix[(int)c.y1][(int)c.x1]) <= 300)
		map->color = 0x9c42f5;
	if (abs(map->z_matrix[(int)c.y1][(int)c.x1]) > 300)
		map->color = 0x02f5c0;
}

void	img_init(t_fdf *map)
{
	if (map->img.img)
		mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, WIN_X, WIN_Y);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp, \
		&map->img.l, &map->img.end);
	draw(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
}

int	keys(int keycode, t_fdf *map)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(map->mlx, map->img.img);
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	zoom(keycode, map);
	translate(keycode, map);
	view(keycode, map);
	rotate(keycode, map);
	z_move(keycode, map);
	img_init(map);
	return (0);
}

int	close_win(t_fdf *map)
{
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fdf	map;
	char	**str;

	map.img.img = NULL;
	map.flag = 0;
	if (!display_error(ac, av[1]))
		return (0);
	str = splited_map(av[1]);
	if (!(*str) || !str)
	{
		ft_printf ("Invalid map\n");
		exit (0);
	}
	if (map_error(str))
	{
		set_default(&map, av[1], str);
		mlx_hook(map.win, 2, 1l, &keys, &map);
		mlx_hook(map.win, 17, 1l<<15, &close_win, &map);
		mlx_loop(map.mlx);
	}
	return (0);
}
