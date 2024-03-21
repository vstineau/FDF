/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:42:11 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/21 14:59:52 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_d)
	{
		vars->init = false;
		vars->scale -= 0.5;
	}
	if (keycode == XK_z)
	{
   	vars->init = false;
		vars->scale += 0.5;
	}
}

void	height_handler(int keycode, t_vars *vars)
{
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
}

void	rotation_handler(int keycode, t_vars* vars)
{
	if (keycode == XK_c)
	{
		printf("a = %f\n", vars->a);
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
}
