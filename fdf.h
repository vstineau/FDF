/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:38:36 by vstineau          #+#    #+#             */
/*   Updated: 2024/04/03 10:58:21 by vstineau         ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DEFAULT_COLOR 0xFFFFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
	float		offset_x;
	float		offset_y;
}				t_data;

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	unsigned int	color;
}				t_point;

typedef struct s_mat3
{
	float	m[3][3];
}				t_mat3;

typedef struct s_xorshift32_state
{
	uint32_t	rand_colo;
}				t_xorshift32_state;

typedef struct s_vars	t_vars;

typedef void			(*t_fn)(t_vars *vars);

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				line_nb;
	int				apl;
	float			scale;
	float			max_z;
	float			min_z;
	float			a;
	float			b;
	float			x0;
	float			x1;
	float			y0;
	float			y1;
	float			dx;
	float			dy;
	float			sx;
	float			sy;
	float			err;
	float			e2;
	bool			init;
	char			**temp_map;
	double			height;
	t_mat3			mat_p;
	t_point			**map;
	t_point			**map1;
	t_data			data;
	t_fn			f[0xFFFF];
	unsigned int	color;
	unsigned int	default_color;
}				t_vars;

//PARSING :
void			check_file(char *argv);
t_point			**parse(char *argv, t_vars *vars);
char			*read_map(char *argv);
int				arg_per_line(char **map);
void			check_apl(char **map);
void			set_scale(char *ln, t_vars *v);
//FONCTIONS POUR FREE :
void			free_end(t_vars *v);
void			ft_free_point(t_point **tab, int linenumb);
void			ft_free_int_tab(int **tab, int linenumb);
void			ft_free_int_tab2(int ***tab, int linenumb, int apl);
void			ft_free_char_tab(char **tab);
void			ft_free_and_exit(char **map, t_point **tab, t_vars *v);
void			ft_free_and_exit2(t_vars *v);
void			free_ln(char **map, char *ln);
void			error_ln(char *ln);
//MOUSE ACTION;
int				mouse_action(int keycode, t_vars *vars);
//WINDOWS ACTIONS
int				window_action(int keycode, t_vars *vars);
int				close_windows(t_vars *vars);
void			zoom(t_vars *vars);
void			unzoom(t_vars *vars);
void			go_middle(t_vars *vars);
void			go_right(t_vars *vars);
void			go_left(t_vars *vars);
void			go_up(t_vars *vars);
void			go_down(t_vars *vars);
void			height_up(t_vars *vars);
void			height_down(t_vars *vars);
void			clear_image(t_vars *v, int color);
void			change_color(t_vars *v);
void			switch_colors(t_vars *vars);
void			rotate_z(t_vars *vars);
void			rotate_x(t_vars *vars);
//MATRICES
int				*get_new_position(float **mat_p, int x, int y, int z);
void			apply_matrix(t_point **map, t_mat3 matrix, t_vars *v);
void			init_mat_p(t_vars *v);
void			init_map_iso(t_vars *v);
//AFFICHAGE DES PIXELS
void			start_image(t_vars *v);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
float			inverse_lerp(float min, float max, float z);
void			set_transparency(t_vars *v, t_point *p);
void			print_lines(t_vars *v);
void			print_column(t_vars *v);
void			set_z_max(t_vars *v);
void			set_z_min(t_vars *v);
unsigned int	get_color(const char *hexa_color);

#endif
