/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:29:29 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/06 15:05:09 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_action(int keycode,t_vars	*vars)
{
	if (keycode == 4)
		vars->scale++;
	if (keycode == 5)
		vars->scale--;
	return (0);
}
