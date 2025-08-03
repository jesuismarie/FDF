/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:00:24 by mnazarya          #+#    #+#             */
/*   Updated: 2025/08/02 19:58:21 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
