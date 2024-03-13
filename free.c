/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:08:46 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/13 11:43:38 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_point(t_point **tab, int linenumb)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < linenumb)
		free(tab[i++]);
	free(tab);
}

void	ft_free_int_tab2(int ***tab, int linenumb, int apl)
{
	int	i;
	int	j;

	if (!tab)
		return ;
	i = 0;
	j = 0;
	while (i < linenumb)
	{
		while(j < apl)
			free(tab[i][j++]);
		free(tab[i++]);
	}
	free(tab);
}

void	ft_free_char_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_end(t_vars *v)
{
	ft_free_int_tab(v->map, v->line_nb);
	ft_free_int_tab((int**)v->matrice_p, 4);
	ft_free_int_tab2(v->map_iso, v->line_nb, v->apl);
	//free(v->win);
	free(v->mlx);
}
