/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:00 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/29 16:46:03 by vstineau         ###   ########.fr       */
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
		v->x0 = v->map[i][j].x * v->scale;
		v->x1 = v->map[i + 1][j].x * v->scale;
		v->y0 = v->map[i][j].y * v->scale;
		v->y1 = v->map[i + 1][j].y * v->scale;
	}
	else
	{
		v->x0 = v->map[i][j].x * v->scale;
		v->x1 = v->map[i][j + 1].x * v->scale;
		v->y0 = v->map[i][j].y * v->scale;
		v->y1 = v->map[i][j + 1].y * v->scale;
	}
	v->dx = fabsf(v->x1 - v->x0);
	v->dy = -fabsf(v->y1 - v->y0);
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
	float	i;
	float	j;

	i = 0;
	j = 0;
	while ((int)i <= (int)v->dx || (int)j <= (int) -v->dy)
	{
		my_mlx_pixel_put(&(v->data), (int)v->x0, (int)v->y0, v->color);
		v->e2 = 2 * v->err;
		if (v->e2 >= v->dy)
		{
			v->err += v->dy;
			v->x0 += v->sx;
		}
		if (v->e2 <= v->dx)
		{
			v->err += v->dx;
			v->y0 += v->sy;
		}
		i += fabs(v->sx);
		j += fabs(v->sy);
	}
}

//TRACE TOUTES LES LIGNES ENTRE LES POINTS D'UNE MEME LIGNE
void	print_lines(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->line_nb)
	{
		j = 0;
		while (j < v->apl - 1)
		{
			v->color = v->map[i][j].color;
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
		while (j < v->apl)
		{
			v->color = v->map[i][j].color;
			pre_plotline(v, i, j++, true);
			plotline(v);
		}
		i++;
	}
}
