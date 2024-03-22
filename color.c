/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:37:55 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/22 15:16:21 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(const char *hexa_color)
{
	unsigned int	color;
	char	c;
	int	i;
	int	value;

	color = 0;
	i = 2;
	while (hexa_color[i])
	{
		c = hexa_color[i];
		value = 0;
		if (c >= '0' && c <= '9')
			value = c - 0;
		else if (c >= 'a' && c <= 'f')
			value = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value = c - 'A' + 10;
		color =  (color << 4) | value;
		i++;
	}
	return (color);
}

//https://en.wikipedia.org/wiki/Xorshift
unsigned int	randomize_color(t_xorshift32_state *state)
{
	uint32_t	x;

	x = state->rand_colo;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	state->rand_colo = x;
	return (x);	
}
