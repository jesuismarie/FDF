/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:56:50 by mnazarya          #+#    #+#             */
/*   Updated: 2023/08/16 19:45:35 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1600
# define WIN_Y 1000

# ifdef __linux__
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
#  define ZOOM_IN1 61
#  define ZOOM_OUT1 45
#  define ZOOM_IN2 65451
#  define ZOOM_OUT2 65453
#  define PARALLEL 112
#  define ISO 105
#  define TOP 116
#  define ROT1 97
#  define ROT2 100
#  define Z_UP 119
#  define Z_DOWN 115
# else
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
#  define ZOOM_IN1 69
#  define ZOOM_OUT1 78
#  define ZOOM_IN2 24
#  define ZOOM_OUT2 27
#  define PARALLEL 35
#  define ISO 34
#  define TOP 17
#  define ROT1 0
#  define ROT2 2
#  define Z_UP 13
#  define Z_DOWN 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../includes/ft_printf.h"
# include "../minilibx_macos/mlx.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l;
	int		end;
}	t_image;

typedef struct s_fdf
{
	int		**z_matrix;
	int		**mat;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	float	zoom;
	int		color;
	int		cx;
	float	cy;
	int		cz;
	float	angle;
	int		flag;
	t_image	img;
}	t_fdf;

typedef struct s_line
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_line;

char	*ft_strrchr(const char *s, int c);
int		check_map(char *file);
int		check_fd(char *file);
int		display_error(int c, char *file);
char	*read_str(char *file);
size_t	ft_strlen(const char *s);
int		word_count(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		free_malloc(char **str);
char	**ft_split(char const *s, char c);
char	**splited_map(char *file);
int		map_error(char **str);
void	get_wh(t_fdf *map, char **str);
void	scale(t_fdf *map);
int		ft_atoi(const char *nptr);
void	fill_matrix(char **str, t_fdf *map);
void	set_default(t_fdf *map, char *file, char **str);
void	img_init(t_fdf *map);
void	my_mlx_pixel_put(t_fdf *map, int x, int y);
void	draw_line(t_fdf *map, t_line *c);
void	draw(t_fdf *map);
void	zoom(int key, t_fdf *map);
void	translate(int key, t_fdf *map);
void	view(int key, t_fdf *map);
void	rotate(int key, t_fdf *map);
void	z_move(int key, t_fdf *map);
void	colours(t_fdf *map, t_line c);

#endif