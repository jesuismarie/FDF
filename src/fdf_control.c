/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:56:39 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/21 17:58:25 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_fdf *map)
{
	if (key == ZOOM_IN1 || key == ZOOM_IN2)
		map->zoom += 0.2;
	if (key == ZOOM_OUT1 || key == ZOOM_OUT2)
		map->zoom -= 0.2;
}

void	translate(int key, t_fdf *map)
{
	if (key == UP)
		map->cy -= 5;
	if (key == DOWN)
		map->cy += 5;
	if (key == LEFT)
		map->cx -= 5;
	if (key == RIGHT)
		map->cx += 5;
}

void	view(int key, t_fdf *map)
{
	if (key == TOP)
		map->flag = 1;
	if (key == ISO)
	{
		map->flag = 0;
		map->angle = 0.8;
	}
	if (key == PARALLEL)
	{
		map->flag = 0;
		map->angle = 0;
	}
}

void	rotate(int key, t_fdf *map)
{
	if (key == ROT1)
		map->angle += 0.04;
	if (key == ROT2)
		map->angle -= 0.04;
}

void	z_move(int key, t_fdf *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->cz = 0;
	if (key == Z_UP)
		map->cz += 2;
	if (key == Z_DOWN)
		map->cz -= 2;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->mat[i][j] != 0)
				map->z_matrix[i][j] += map->cz;
			j++;
		}
		i++;
	}
}
