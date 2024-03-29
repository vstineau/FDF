/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:58:17 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/29 13:49:08 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_int_tab(int **tab, int linenumb)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < linenumb && tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_and_exit(char **map, t_point **tab, t_vars *v)
{
	if (!tab)
		return ;
	ft_free_point(tab, v->line_nb);
	if (!map)
		return ;
	ft_free_char_tab(map);
	exit(1);
}

void	ft_free_and_exit2(t_vars *v)
{
	if (v->map)
		ft_free_point(v->map, v->line_nb);
	if (v->map1)
		ft_free_point(v->map1, v->line_nb);
	if (v->temp_map)
		ft_free_char_tab(v->temp_map);
	exit(1);
}

void	free_ln(char **map, char *ln)
{
	if (!map)
	{
		free(ln);
		exit(1);
	}
	else
		free(ln);
}
