/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:29:29 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/20 16:41:56 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_action(int keycode,t_vars	*vars)
{
	if (keycode == 4)
		vars->scale += 0.5;
	if (keycode == 5)
		vars->scale -= 0.5;
	return (0);
}
