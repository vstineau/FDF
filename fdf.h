/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:38:36 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/07 14:50:43 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "LIBFT/libft.h"

# define WIN_WIDTH 1920 //960
# define WIN_HEIGHT 1080 //540 

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int	bit_per_pixel;
	int	line_length;
	int	endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		**map;
	float	**matrice_p;
	int	line_nb;
	int	apl;
	t_data	img;
}				t_vars;

//PARSING :
int	**parse(char *argv, t_vars *vars);
//FONCTIONS POUR FREE :
void	free_end(t_vars *v);
void	ft_free_int_tab(int **tab, int linenumb);
void	ft_free_char_tab(char **tab);
void	ft_free_and_exit(char **map, int **tab, t_vars *v);
//MOUSE ACTION;
int	mouse_action(int keycode,t_vars	*vars);
//WINDOWS ACTIONS
int	window_action(int keycode, t_vars *vars);

#endif
