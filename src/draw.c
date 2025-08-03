/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:41:15 by mnazarya          #+#    #+#             */
/*   Updated: 2025/08/02 15:04:47 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_fdf *map, int x, int y)
{
	char	*dst;

	if (map->img.addr && x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		dst = map->img.addr + (y * map->img.l + x * (map->img.bpp / 8));
		*(unsigned int *)dst = map->color;
	}
}

static void	draw_helper(t_fdf *map, t_line *c)
{
	int	i1;
	int	j1;
	int	i2;
	int	j2;

	i1 = c->x1;
	j1 = c->y1;
	i2 = c->x2;
	j2 = c->y2;
	colours(map, *c);
	c->x1 *= map->zoom;
	c->y1 *= map->zoom;
	c->x2 *= map->zoom;
	c->y2 *= map->zoom;
	if (!map->flag)
	{
		c->x1 = (c->x1 - c->y1) * cos(map->angle);
		c->y1 = ((c->x1 + c->y1) * sin(map->angle))
			- (map->z_matrix[j1][i1] * map->z_scale * map->zoom);
		c->x2 = (c->x2 - c->y2) * cos(map->angle);
		c->y2 = ((c->x2 + c->y2) * sin(map->angle))
			- (map->z_matrix[j2][i2] * map->z_scale * map->zoom);
	}
}

void	draw_line(t_fdf *map, t_line *c)
{
	float	delta_x;
	float	delta_y;
	int		max;

	draw_helper(map, c);
	delta_x = c->x2 - c->x1;
	delta_y = c->y2 - c->y1;
	if (fabsf(delta_x) > fabsf(delta_y))
		max = fabsf(delta_x);
	else
		max = fabsf(delta_y);
	delta_x /= max;
	delta_y /= max;
	while ((int)(c->x1 - c->x2) || (int)(c->y1 - c->y2))
	{
		my_mlx_pixel_put(map, c->x1 + map->cx, c->y1 + map->cy);
		c->x1 += delta_x;
		c->y1 += delta_y;
	}
}

void	draw(t_fdf *map)
{
	int		i;
	int		j;
	t_line	c;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			c.x1 = j;
			c.y1 = i;
			c.x2 = j + 1;
			c.y2 = i;
			if (c.x1 < map->width - 1)
				draw_line(map, &c);
			c.x1 = j;
			c.y1 = i;
			c.x2 = j;
			c.y2 = i + 1;
			if (c.y1 < map->height - 1)
				draw_line(map, &c);
		}
	}
}
