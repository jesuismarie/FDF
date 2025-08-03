/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:51:15 by mnazarya          #+#    #+#             */
/*   Updated: 2025/08/03 17:04:23 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	colours(t_fdf *map, t_line c)
{
	int	parsed_color;

	parsed_color = map->color_matrix[(int)c.y1][(int)c.x1];
	if (parsed_color != -1)
	{
		map->color = parsed_color;
		return ;
	}
	if (fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) == 0)
		map->color = 0xfae20a;
	if (fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) > 0 &&
		fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) <= 20)
		map->color = 0x42f587;
	if (fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) > 20 &&
		fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) <= 80)
		map->color = 0xff0000;
	if (fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) > 80 &&
		fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) <= 200)
		map->color = 0x4287f5;
	if (fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) > 200 &&
		fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) <= 300)
		map->color = 0x9c42f5;
	if (fabsf(map->z_matrix[(int)c.y1][(int)c.x1]) > 300)
		map->color = 0x02f5c0;
}

int	ft_hex_to_int(const char *hex)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i])
	{
		result *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			result += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			result += hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			result += hex[i] - 'A' + 10;
		i++;
	}
	return (result);
}
