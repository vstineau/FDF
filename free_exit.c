/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:58:17 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/08 12:59:15 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_and_exit(char **map, int **tab, t_vars *v)
{
	ft_free_int_tab(tab, v->line_nb);
	ft_free_char_tab(map);
	exit(1);
}

void	ft_free_and_exit2(t_vars *v)
{
	ft_free_int_tab((int**)v->matrice_p, 4);
	ft_free_int_tab2(v->map_iso, v->line_nb, v->apl);
	ft_free_int_tab(v->map, v->line_nb);
	exit(1);
}
