/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:50:49 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/22 20:40:58 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_map(char *file)
{
	int	i;

	i = 0;
	file = ft_strrchr(file, '.');
	if (!file)
		return (0);
	while (file[i])
	{
		if (file[i] != ".fdf"[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_fd(char *file)
{
	char	*s;
	int		fd;
	int		n;

	n = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &s, 1) > 0)
		n++;
	if (n == 0)
		return (0);
	close(fd);
	return (1);
}

int	display_error(int c, char *file)
{
	if (c != 2)
	{
		ft_printf("Parametreri qanaky sxala yngers!\n");
		return (0);
	}
	if (!check_map(file))
	{
		ft_printf("Wronga axper!\n");
		return (0);
	}
	if (!check_fd(file))
	{
		ft_printf("Empty or invalid file!\n");
		return (0);
	}
	return (1);
}

int	map_error(char **str)
{
	int	a;
	int	i;

	i = 1;
	a = word_count(str[0], ' ');
	while (str[i])
	{
		if (word_count(str[i], ' ') != a)
		{
			free_malloc(str);
			ft_printf("Invalid map");
			return (0);
		}
		i++;
	}
	return (1);
}
