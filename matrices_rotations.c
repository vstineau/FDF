/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:58:19 by vstineau          #+#    #+#             */
/*   Updated: 2024/04/02 11:18:13 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//https://fr.wikipedia.org/wiki/Matrice_de_rotation
//https://fr.wikihow.com/convertir-des-degr%C3%A9s-en-radians

void	apply_matrix(t_point **map, t_mat3 matrix, t_vars *v)
{
	int		y;
	int		x;
	t_point	temp;

	y = 0;
	while (y < v->line_nb)
	{
		x = 0;
		while (x < v->apl)
		{
			temp = v->map[y][x];
			temp.x = matrix.m[0][0] * map[y][x].x + matrix.m[0][1]
				* map[y][x].y + matrix.m[0][2] * map[y][x].z;
			temp.y = matrix.m[1][0] * map[y][x].x + matrix.m[1][1]
				* map[y][x].y + matrix.m[1][2] * map[y][x].z * v->height;
			temp.z = matrix.m[2][0] * map[y][x].x + matrix.m[2][1]
				* map[y][x].y + matrix.m[2][2] * map[y][x].z * v->height;
			v->map[y][x] = temp;
			x++;
		}
		y++;
	}
	set_z_min(v);
	set_z_min(v);
}

//https://www.gamedev.net/articles/programming/
//general-and-gameplay-programming/inverse-lerp-a-super-
//useful-yet-often-overlooked-function-r5230/

float	inverse_lerp(float min, float max, float z)
{
	return ((z - min) / (max - min));
}

void	set_transparency(t_vars *v, t_point *p)
{
	unsigned char	t;

	t = (unsigned char)(255 * inverse_lerp(v->min_z, v->max_z, p->z));
	p->color = p->color | (t << 24);
}
