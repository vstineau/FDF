/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:02:36 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/13 17:58:53 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://zingl.github.io/bresenham.html
//SI VERTICAL EST TRUE ALORS ON RELIE LES POINTS AVEC CELUI DU DESSOUS
//SINON ON RELIE LES POINT AVEC CELUI SUR LA DROITE
static void	pre_plotline(t_vars *v, int i, int j, bool vertical)
{
	if (vertical == true)
	{
		v->x0 = v->map[i][j].x;
		v->x1 = v->map[i + 1][j].x;
		v->y0 = v->map[i][j].y;
		v->y1 = v->map[i + 1][j].y;
	}
	else 
	{
		v->x0 = v->map[i][j].x;
		v->x1 = v->map[i + 1][j].x;
		v->y0 = v->map[i][j].y;
		v->y1 = v->map[i + 1][j].y;
	}
	v->dx = ft_abs(v->x0 - v->x1);
	v->dy = ft_abs(v->y0 - v->y1);
	v->err = v->dy + v->dx;
	if (v->x0 < v->x1)
		v->sx = 1;
	else
		v->sx = -1;
	if (v->y0 < v->y1)
		v->sy = 1;
	else
		v->sy = -1;
}
//ALGO DE TRACE DE SEGMENT DE BRESENHAM
static void	plotline(t_vars *v)
{
	v->color = 0x000000FF;
	while (v->x0 > v->x1 || v->y0 > v->y1)
	{
		my_mlx_pixel_put(&(v->data), v->x0, v->y0, v->color);
		v->e2 = 2 * v->err;
		if (v->e2 >= v->dy)
		{
			v->err += v->dy;
			v->x0 += v->sx;
		}
		if (v->e2 <= v->dx)
		{
			v->err += v->dx;
			v->x0 += v->sy;
		}
	}
}
//TRACE TOUTES LES LIGNES ENTRE LES POINTS D'UNE MEME LIGNE
void	print_lines(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->line_nb - 1)
	{
		j = 0;
		while (j < v->apl - 1)
		{
			pre_plotline(v, i, j++, false);
			plotline(v);
		}
		i++;
	}
}
//TRACE TOUTES LES LIGNES ENTRE LES POINTS D'UNE MEME COLONNE
void	print_column(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->line_nb - 1)
	{
		j = 0;
		while (j < v->apl - 1)
		{
			pre_plotline(v, i, j++, true);
			plotline(v);
		}
		i++;
	}
}

