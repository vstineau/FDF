/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:08:46 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/27 13:32:24 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_point(t_point **tab, int linenumb)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < linenumb && tab[i])
		free(tab[i++]);
	free(tab);
}

void	error_ln(char *ln)
{
	if (!ln)
		exit(1);
	else
		return ;
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
	ft_free_point(v->map1, v->line_nb);
	free(v->mlx);
}
