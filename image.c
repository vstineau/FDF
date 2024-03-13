/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:32:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/13 17:30:35 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_image(t_vars *v)
{
	v->data.img = mlx_new_image(v->mlx, WIN_WIDTH, WIN_HEIGHT);
	v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bit_per_pixel,
			&v->data.line_length, &v->data.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;
	
	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	dest = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}
