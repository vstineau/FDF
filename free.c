/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:08:46 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/06 15:17:35 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_int_tab(int **tab, int linenumb)
{
	int	i;

	i = 0;
	while (i < linenumb)
		free(tab[i++]);
	free(tab);
}

void	ft_free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_end(t_vars *v)
{
	ft_free_int_tab(v->map, v->line_nb);
	//free(v->win);
	free(v->mlx);
}
