/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:19:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/27 16:46:01 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_apl(char **map)
{
	int	i;
	int	cw;

	i = 0;
	cw = arg_per_line(&map[i]);
	while(map[i])
	{
		if (cw != arg_per_line(&map[i]))
		{
			ft_free_char_tab(map);
			perror("invalid map");
			exit(1);
		}
		else
			cw = arg_per_line(&map[i]);
		i++;		
	}
}
