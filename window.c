/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/22 17:28:04 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

static void f_init(t_vars *vars)
{
	ft_memset(vars->f, 0, 0xFFF);
	vars->f[XK_Escape] = (void *)close_windows;
	vars->f[XK_z] = (void *)zoom;
	vars->f[XK_d] = NULL;
}

int	window_action(int keycode, t_vars *vars)
{
	if (!vars->f[keycode])
		return (0);
	f_init(vars);
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

int	loop(t_vars *vars)
{
	t_xorshift32_state	state;

	state.rand_colo = vars->default_color;
	vars->default_color = randomize_color(&state);
	return (0);
}
