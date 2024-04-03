/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_action2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:32:53 by vstineau          #+#    #+#             */
/*   Updated: 2024/04/03 11:14:58 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	vars->height = 0.1;
	vars->a = 0.95445703708848;
	vars->b = M_PI / 4;
	init_mat_p(vars);
	apply_matrix(vars->map1, vars->mat_p, vars);
}
