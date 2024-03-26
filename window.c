/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/26 10:58:56 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

static void f_init(t_vars *vars)
{
	ft_memset(vars->f, 0, 0xFFF);
	vars->f[XK_Escape] = (void *)close_windows;
	vars->f[XK_0] = (void *)zoom;
	vars->f[XK_9] = (void *)unzoom;
	vars->f[XK_h] = (void *)height_up;
	vars->f[XK_b] = (void *)height_down;
	vars->f[XK_Left] = (void *)go_left;
	vars->f[XK_Right] = (void *)go_right;
	vars->f[XK_Up] = (void *)go_up;
	vars->f[XK_Down] = (void *)go_down;
	vars->f[XK_m] = (void *)go_middle;
	vars->f[XK_w] = (void *)change_color;
	vars->f[XK_x] = (void *)rotate_x;
	vars->f[XK_z] = (void *)rotate_z;
}

int	window_action(int keycode, t_vars *vars)
{
	f_init(vars);
	clear_image(vars, 0);
	if (!vars->f[keycode])
		return (0);
	else
		vars->f[keycode](vars);
/*	if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx);
	clear_image(vars, 0);
	zoom_handler(keycode, vars);
	height_handler(keycode, vars);
	rotation_handler(keycode, vars);*/
	print_lines(vars);
	print_column(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

int	close_windows(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

void	switch_colors(t_vars *vars)
{
	change_color(vars);
}
