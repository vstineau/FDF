/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:35 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/07 15:20:42 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//INITIALISATION DE LA MATRICE DE PROJECTION
void	init_matrice_p(t_vars *v)
{
	v->matrice_p = malloc(sizeof(float *) * 4);
	v->matrice_p[0] = malloc(sizeof(float) * 4);
	v->matrice_p[1] = malloc(sizeof(float) * 4);
	v->matrice_p[2] = malloc(sizeof(float) * 4);
	v->matrice_p[3] = malloc(sizeof(float) * 4);
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

void	do_matrice_p(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	j	= 0;
	init_matrice_p(v);
	
}
