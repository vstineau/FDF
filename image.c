/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:32:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/06 14:37:26 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data,  int x, int y, int color)
{
	char	*dest;

	dest = data->adr + (y * data->line_lenght + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}
