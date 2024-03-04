/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:19:57 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/04 11:05:16 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	**ta_to_ti(char **map)
{
	int **int_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{	
		while (map[i][j])
		{
			int_map[i][j] = ft_atoi((const char *)map[i] + j);
			j++;
		}
		i++;
	}
	return (int_map);
}

int	**parse(char *argv)
{
	int		fd;
	char	**map;
	char	*line;
	char	*temp;
	
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	temp = get_next_line(fd);
	while (temp)
	{
		line = ft_strjoin(line, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	map = ft_split(line, '\n');
	free(line);
	return (ta_to_ti(map));
}

