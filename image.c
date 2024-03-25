/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:32:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/25 11:36:08 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

void	start_image(t_vars *v)
{
	v->data.img = mlx_new_image(v->mlx, WIN_WIDTH, WIN_HEIGHT);
	v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bit_per_pixel,
			&v->data.line_length, &v->data.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	x += data->offset_x;
	y += data->offset_y;
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
	{
		//printf("x = %d, y = %d\n", x, y);
		//exit(1);
		return ;
	}
	dest = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	clear_image(t_vars *v, int	color)
{
	int	y;
	int	x;
	char	*pixel;

	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = v->data.addr + ( y *  v->data.line_length + x * (v->data.bit_per_pixel / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}
