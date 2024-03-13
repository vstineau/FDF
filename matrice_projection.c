/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:35 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/13 17:04:28 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//INITIALISATION DE LA MATRICE DE PROJECTION
static void	mini_init_matrice_p(t_vars *v)
{
	v->matrice_p[0][0] = 0.70;
	v->matrice_p[0][1] = -0.70;
	v->matrice_p[0][2] = 0;
	v->matrice_p[0][3] = 0;
	v->matrice_p[1][0] = 0.40;
	v->matrice_p[1][1] = 0.40;
	v->matrice_p[1][2] = -0.82;
	v->matrice_p[1][3] = 0;
	v->matrice_p[2][0] = 0.40;
	v->matrice_p[2][1] = 0.40;
	v->matrice_p[2][2] = 0.82;
	v->matrice_p[2][3] = 0;
	v->matrice_p[3][0] = 0;
	v->matrice_p[3][1] = 0;
	v->matrice_p[3][2] = 0;
	v->matrice_p[3][3] = 1;
}

static void	init_matrice_p(t_vars *v)
{
	v->matrice_p = malloc(sizeof(float *) * 4);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	v->matrice_p[0] = malloc(sizeof(float) * 4);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	v->matrice_p[1] = malloc(sizeof(float) * 4);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	v->matrice_p[2] = malloc(sizeof(float) * 4);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	v->matrice_p[3] = malloc(sizeof(float) * 4);
	if (!v->matrice_p)
		ft_free_and_exit2(v);
	mini_init_matrice_p(v);
}
//MULTIPLICATION DE CHAQUE VECTEUR PAR LA MATRICE DE PROJECTION ISOMETRIQUE
//POUR OBTENIR LES NOUVELLES COORDONNEES QUI REMPLACERONT LES ANCIENES

void	init_map_iso(t_vars *v)
{
	int	y;
	int	x;

	y = 0;
	init_matrice_p(v);
	while (y < v->line_nb)
	{
		x = 0;
		while (x < v->apl)
		{
			v->map[y][x].x = v->map[y][x].x * v->matrice_p[0][0]
				- v->map[y][x].y * v->matrice_p[0][1];
			v->map[y][x].y = v->map[y][x].x * v->matrice_p[1][0]
				- v->map[y][x].y * v->matrice_p[1][1]
				- v->map[y][x].z * v->matrice_p[2][2];
			v->map[y][x].y = v->map[y][x].x * v->matrice_p[2][0]
				- v->map[y][x].y * v->matrice_p[2][1]
				- v->map[y][x].z * v->matrice_p[2][2];
			x++;
		}
		y++;
	}
}
