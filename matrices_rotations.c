/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:58:19 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/25 10:58:22 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://fr.wikipedia.org/wiki/Matrice_de_rotation
//https://fr.wikihow.com/convertir-des-degr%C3%A9s-en-radians

void	init_mat_rx(t_vars *v)
{
	const float radiant = 1 * M_PI / 180;
	const float co = cosf(radiant);
	const float si = sinf(radiant);

	v->mat_rx.m[0][0] = 1;
	v->mat_rx.m[0][1] = 0;
	v->mat_rx.m[0][2] = 0;
	v->mat_rx.m[1][0] = 0;
	v->mat_rx.m[1][1] = co;
	v->mat_rx.m[1][2] = si;
	v->mat_rx.m[2][0] = 0;
	v->mat_rx.m[2][1] = -si;
	v->mat_rx.m[2][2] = co;
}

void	init_mat_ry(t_vars *v)
{
	const float radiant = 5 * M_PI / 180;
	const float co = cosf(radiant);
	const float si = sinf(radiant);

	v->mat_ry.m[0][0] = co;
	v->mat_ry.m[0][1] = 0;
	v->mat_ry.m[0][2] = -si;
	v->mat_ry.m[1][0] = 0;
	v->mat_ry.m[1][1] = 1;
	v->mat_ry.m[1][2] = 0;
	v->mat_ry.m[2][0] = si;
	v->mat_ry.m[2][1] = 0;
	v->mat_ry.m[2][2] = co;
}

void	init_mat_rz(t_vars *v)
{
	const float radiant = 5 * M_PI / 180;
	const float co = cosf(radiant);
	const float si = sinf(radiant);

	v->mat_rz.m[0][0] = co;
	v->mat_rz.m[0][1] = -si;
	v->mat_rz.m[0][2] = 0;
	v->mat_rz.m[1][0] = -si;
	v->mat_rz.m[1][1] = co;
	v->mat_rz.m[1][2] = 0;
	v->mat_rz.m[2][0] = 0;
	v->mat_rz.m[2][1] = 0;
	v->mat_rz.m[2][2] = 1;
}

void	apply_matrix(t_point **map, t_mat3 matrix, t_vars *v)
{
	int	y;
	int	x;
	t_point	temp;

	y = 0;
	while (y < v->line_nb)
	{
		x = 0;
		while (x < v->apl)
		{
			temp = map[y][x];
			temp.x = matrix.m[0][0] * map[y][x].x + matrix.m[0][1] * map[y][x].y + matrix.m[0][2] * map[y][x].z;
			temp.x = matrix.m[1][0] * map[y][x].x + matrix.m[1][1] * map[y][x].y + matrix.m[1][2] * map[y][x].z;
			map[y][x] = temp;
			x++;
		}
		y++;
	}
}
