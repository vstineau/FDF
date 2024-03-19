/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:37:55 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/19 11:48:14 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(const char *hex_color)
{
	unsigned int	color;
	char	c;
	int	i;
	int	value;

	color = 0;
	i = 0;
	while (hex_color[i])
	{
		c = hex_color[i];
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
