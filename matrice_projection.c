/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:35 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/26 10:47:25 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
//INITIALISATION DE LA MATRICE DE PROJECTION
//https://fr.wikipedia.org/wiki/Perspective_isom%C3%A9trique
//https://fr.wikihow.com/convertir-des-degr%C3%A9s-en-radians

void	init_mat_p(t_vars *v)
{
	if (v->init)
	{
		v->data.offset_x = WIN_WIDTH / 2.0;
		v->data.offset_y = WIN_HEIGHT / 6.0;
		v->a = 0.95445703708848;
		v->b = M_PI / 4;
	}
	v->mat_p.m[0][0] = cosf(v->b);
	v->mat_p.m[0][1] = -sinf(v->b);
	v->mat_p.m[0][2] = 0;
	v->mat_p.m[1][0] = sinf(v->b) * cosf(v->a);
	v->mat_p.m[1][1] = cosf(v->b) * cosf(v->a);
	v->mat_p.m[1][2] = -sinf(v->a);
	v->mat_p.m[2][0] = sinf(v->a) * sinf(v->b);
	v->mat_p.m[2][1] = sinf(v->a) * cosf(v->b);
	v->mat_p.m[2][2] = cosf(v->a);
}

//MULTIPLICATION DE CHAQUE VECTEUR PAR LA MATRICE DE PROJECTION ISOMETRIQUE
//POUR OBTENIR LES NOUVELLES COORDONNEES QUI REMPLACERONT LES ANCIENNES

void	init_map_iso(t_vars *v)
{
	int	y;
	int	x;
	t_point pt;

	y = 0;
	init_mat_p(v);
	v->scale = 15.5;
	while (y < v->line_nb)
	{
		x = 0;
		while (x < v->apl)
		{
			//printf("y = %f x = %f z = %f\n", v->map[y][x].y, v->map[y][x].x, v->map[y][x].z);
			//v->map[y][x].z *= v->height;
			pt = v->map[y][x];
			pt.x = v->mat_p.m[0][0] * v->map[y][x].x + v->mat_p.m[0][1] * v->map[y][x].y;
			pt.y = v->mat_p.m[1][0] * v->map[y][x].x + v->mat_p.m[1][1] * v->map[y][x].y + v->mat_p.m[1][2] * v->map[y][x].z * v->height;
			v->map[y][x] = pt;
			//printf("x = %f y = %f z = %f\n", v->map[y][x].x, v->map[y][x].y, v->map[y][x].z);
			x++;
		}
		y++;
	}
}
