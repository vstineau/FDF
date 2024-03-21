/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:35 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/21 11:33:22 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
//INITIALISATION DE LA MATRICE DE PROJECTION
//https://fr.wikipedia.org/wiki/Perspective_isom%C3%A9trique
//https://fr.wikihow.com/convertir-des-degr%C3%A9s-en-radians

static void	mini_init_matrice_p(t_vars *v)
{
	if (v->init)
	{
		v->a = 0.95445703708848;
		v->b = 3.14159265359 / 4;
	}
	write(1, "ok\n", 3);
	v->matrice_p[0][0] = cosf(v->b);
	v->matrice_p[0][1] = -sinf(v->b);
	v->matrice_p[0][2] = 0;
	v->matrice_p[1][0] = sinf(v->b) * cosf(v->a);
	v->matrice_p[1][1] = cosf(v->b) * cosf(v->a);
	v->matrice_p[1][2] = -sinf(v->a);
	v->matrice_p[2][0] = sinf(v->a) * sinf(v->b);
	v->matrice_p[2][1] = sinf(v->a) * cosf(v->b);
	v->matrice_p[2][2] = cosf(v->a);
}

static void	init_matrice_p(t_vars *v)
{
	if (v->init)
	{
		v->matrice_p = malloc(sizeof(float *) * 3);
		if (!v->matrice_p)
			ft_free_and_exit2(v);
		v->matrice_p[0] = malloc(sizeof(float) * 3);
		if (!v->matrice_p)
			ft_free_and_exit2(v);
		v->matrice_p[1] = malloc(sizeof(float) * 3);
		if (!v->matrice_p)
			ft_free_and_exit2(v);
		v->matrice_p[2] = malloc(sizeof(float) * 3);
		if (!v->matrice_p)
			ft_free_and_exit2(v);
	}
	mini_init_matrice_p(v);
}
//MULTIPLICATION DE CHAQUE VECTEUR PAR LA MATRICE DE PROJECTION ISOMETRIQUE
//POUR OBTENIR LES NOUVELLES COORDONNEES QUI REMPLACERONT LES ANCIENNES

void	init_map_iso(t_vars *v)
{
	int	y;
	int	x;
	t_point pt;

	y = 0;
	init_matrice_p(v);
	v->scale = 15.5;
	while (y < v->line_nb)
	{
		x = 0;
		while (x < v->apl)
		{
			//printf("y = %f x = %f z = %f\n", v->map[y][x].y, v->map[y][x].x, v->map[y][x].z);
			//v->map[y][x].z *= v->height;
			pt = v->map[y][x];
			pt.x = v->matrice_p[0][0] * v->map[y][x].x + v->matrice_p[0][1] * v->map[y][x].y;
			pt.y = v->matrice_p[1][0] * v->map[y][x].x + v->matrice_p[1][1] * v->map[y][x].y + v->matrice_p[1][2] * v->map[y][x].z * v->height;
			v->map[y][x] = pt;
			//printf("x = %f y = %f z = %f\n", v->map[y][x].x, v->map[y][x].y, v->map[y][x].z);
			x++;
		}
		y++;
	}
}
