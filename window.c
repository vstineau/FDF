/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/21 13:50:08 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

int	window_action(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx);
	clear_image(vars, 0);
	if (keycode == XK_h)
	{
		vars->init = false;
		vars->height += 0.1;
		init_map_iso(vars);
	}
	if (keycode == XK_b)
	{
		vars->init = false;
		vars->height -= 0.1;
		init_map_iso(vars);
	}
	if (keycode == XK_d)
	{
		vars->init = false;
		vars->scale -= 1;
	}
	if (keycode == XK_z)
	{
		vars->init = false;
		vars->scale += 1;
	}
	if (keycode == XK_c)
	{
		vars->init = false;
		vars->a += 1;
		init_map_iso(vars);
	}
	if (keycode == XK_m)
	{
		vars->init = false;
		vars->b += 1;
		init_map_iso(vars);
	}
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
	t_xorshift8_state	state;

	state.rand_colo = vars->default_color;
	vars->default_color = randomize_color(&state);
	return (0);
}
