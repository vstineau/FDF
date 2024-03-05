/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:38:36 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/05 11:24:11 by vstineau         ###   ########.fr       */
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
	char	*adr;
	int	bit_per_pixel;
	int	line_lenght;
	int	endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		**map;	
	int		scale;
	t_data	img;
}				t_vars;


int	**parse(char *argv);

#endif
