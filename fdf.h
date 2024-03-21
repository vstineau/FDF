/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:38:36 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/21 14:51:27 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <stdint.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "LIBFT/libft.h"

# define WIN_WIDTH 960
# define WIN_HEIGHT 540
# define DEFAULT_COLOR 0xFFFFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define OFFSET_X WIN_WIDTH / 2
# define OFFSET_Y WIN_HEIGHT / 8

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	unsigned int color;
}				t_point;

typedef struct s_xorshift32_state
{
	uint8_t 	rand_colo;
}				t_xorshift8_state;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	float		**matrice_p;
	int			line_nb;
	int			apl;
	float		scale;
	double			height;
	unsigned int	color;
	unsigned int	default_color;
	float	a;
	float b;
	float	x0;
	float x1;
	float y0;
	float y1;
	float dx;
	float dy;
	float sx;
	float sy;
	float err;
	float e2;
	bool	init;
	t_point		**map;
	t_point		**map1;
	t_data		data;
}				t_vars;

//PARSING :
t_point		**parse(char *argv, t_vars *vars);
//FONCTIONS POUR FREE :
void	free_end(t_vars *v);
void	ft_free_point(t_point **tab, int linenumb);
void	ft_free_int_tab(int **tab, int linenumb);
void	ft_free_int_tab2(int ***tab, int linenumb, int apl);
void	ft_free_char_tab(char **tab);
void	ft_free_and_exit(char **map, t_point **tab, t_vars *v);
void	ft_free_and_exit2(t_vars *v);
//MOUSE ACTION;
int		mouse_action(int keycode, t_vars *vars);
//WINDOWS ACTIONS
int		window_action(int keycode, t_vars *vars);
int		close_windows(t_vars *vars);
void	zoom_handler(int keycode, t_vars *vars);
void	height_handler(int keycode, t_vars *vars);
void	rotation_handler(int keycode, t_vars* vars);
void	clear_image(t_vars *v, int	color);
int	loop(t_vars *vars);
unsigned int	randomize_color(t_xorshift8_state *state);
//MATRICE DE PROJECTION
int	*get_new_position(float **mat_p, int x, int y, int z);
void	init_map_iso(t_vars *v);
//AFFICHAGE DES PIXELS
void	start_image(t_vars *v);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_lines(t_vars *v);
void	print_column(t_vars *v);
unsigned int	get_color(const char *hexa_color);

#endif
