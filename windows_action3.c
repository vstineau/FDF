/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_action3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:34:46 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/27 10:35:11 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_vars *vars)
{
	vars->init = false;
	vars->b += 0.1;
	init_mat_p(vars);
	apply_matrix(vars->map1, vars->mat_p, vars);
}

void	rotate_x(t_vars *vars)
{
	vars->init = false;
	vars->a += 0.1;
	init_mat_p(vars);
	apply_matrix(vars->map1, vars->mat_p, vars);
}
