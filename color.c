/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:37:55 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/17 02:55:45 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(int trgb)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	color;

	t = (trgb >> 24) & 0xFF;
	r = (trgb >> 16) & 0xFF;
	g = (trgb >> 8) & 0xFF;
	b = trgb & 0xFF;
	color = t << 24 | r << 16 | g << 8 | b;
	return (color);
}
