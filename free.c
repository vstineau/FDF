/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:08:46 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/22 15:10:10 by vstineau         ###   ########.fr       */
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
	ft_free_point(v->map, v->line_nb);
	free(v->mlx);
}
