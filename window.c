/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/14 11:51:01 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

int	window_action(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx);
	return (0);
}

int	close_windows(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	loop(t_vars *vars)
{
	(void)vars->mlx;
	return (0);
}
