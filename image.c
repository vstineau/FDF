/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:32:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:59 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_image(t_vars *v)
{
	v->img.img = mlx_new_image(v->mlx, WIN_WIDTH, WIN_HEIGHT);
	v->img.addr = mlx_get_data_addr(v->img.img, &v->img.bit_per_pixel,
			&v->img.line_length, &v->img.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}
