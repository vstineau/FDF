/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:35 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/19 15:30:29 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//INITIALISATION DE LA MATRICE DE PROJECTION
//https://fr.wikipedia.org/wiki/Perspective_isom%C3%A9trique

static void	mini_init_matrice_p(t_vars *v)
{
	v->matrice_p[0][0] = 0.707;
	v->matrice_p[0][1] = -0.707;
	v->matrice_p[0][2] = 0;
	v->matrice_p[1][0] = 0.408;
	v->matrice_p[1][1] = 0.408;
	v->matrice_p[1][2] = -0.816;
}

static void	init_matrice_p(t_vars *v)
{
	v->matrice_p = malloc(sizeof(float *) * 2);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	v->matrice_p[0] = malloc(sizeof(float) * 3);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	v->matrice_p[1] = malloc(sizeof(float) * 3);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
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
			pt = v->map[y][x];
			pt.x = v->matrice_p[0][0] * v->map[y][x].x + v->matrice_p[0][1] * v->map[y][x].y;
			pt.y = v->matrice_p[1][0] * v->map[y][x].x + v->matrice_p[1][1] * v->map[y][x].y + v->matrice_p[1][2] * v->map[y][x].z;
			v->map[y][x] = pt;
			//printf("x = %f y = %f z = %f\n", v->map[y][x].x, v->map[y][x].y, v->map[y][x].z);
			x++;
		}
		y++;
	}
}
