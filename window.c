/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/19 15:25:18 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

int	window_action(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx);
	if (keycode == XK_h)
	{
		printf("h = %f\n", vars->height);
		vars->height += 0.1;
	}
	if (keycode == XK_b)
	{
		printf("h = %f\n", vars->height);
		vars->height -= 0.1;
	}
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
