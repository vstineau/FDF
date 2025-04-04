/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:42:11 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/27 10:37:47 by vstineau         ###   ########.fr       */
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
	init_mat_p(vars);
	apply_matrix(vars->map1, vars->mat_p, vars);
}

void	height_down(t_vars *vars)
{
	vars->init = false;
	vars->height -= 0.1;
	init_mat_p(vars);
	apply_matrix(vars->map1, vars->mat_p, vars);
}
