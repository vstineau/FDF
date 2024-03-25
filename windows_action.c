/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:42:11 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/25 13:14:26 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_vars *vars)
{
   	vars->init = false;
		vars->scale += 0.5;
}

void	unzoom(t_vars *vars)
{
   	vars->init = false;
		vars->scale -= 0.5;
}
void	height_up(t_vars *vars)
{
	vars->init = false;
	vars->height += 0.1;
	init_map_iso(vars);
}

void	height_down(t_vars *vars)
{
	vars->init = false;
	vars->height -= 0.1;
	init_map_iso(vars);
}

void	go_right(t_vars *vars)
{
	vars->init = false;
	vars->data.offset_x += 10;
}

void	go_left(t_vars *vars)
{
	vars->init = false;
	vars->data.offset_x -= 10;
}

void	go_up(t_vars *vars)
{
	vars->init = false;
	vars->data.offset_y -= 10;
}

void	go_down(t_vars *vars)
{
	vars->init = false;
	vars->data.offset_y += 10;
}

void	go_middle(t_vars *vars)
{
		vars->data.offset_x = WIN_WIDTH / 2.0;
		vars->data.offset_y = WIN_HEIGHT / 8.0;
}

void	rotation_handler(int keycode, t_vars* vars)
{
	if (keycode == XK_c)
	{
		vars->init = false;
		apply_matrix(vars->map, vars->mat_rx, vars);
	}
	if (keycode == XK_m)
	{
		vars->init = false;
		vars->b += 1;
		init_map_iso(vars);
	}
}
