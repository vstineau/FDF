/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:19:57 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/05 15:34:11 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_line(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static int	arg_per_line(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[0][i])
	{
		if (map[0][i] != 32)
			count++;
		while (map[0][i] != 32 && map[0][i])
			i++;
		if (map[0][i] == 32)
			i++;
	}
	return (count);
}

static int	**ta_to_ti(char **map, int lins_number)
{
	int	**int_map;
	int	i;
	int	j;

	i = 0;
	int_map = malloc(sizeof(int *) * lins_number);
	while (map[i])
	{
		j = 0;
		map[i] = malloc(sizeof(int) * arg_per_line(map));
		while (j < ft_strleni(map[i]))
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
	char	*ln;
	char	*tp;
	int		n;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tp = get_next_line(fd);
	ln = malloc(sizeof(char) * ft_strlen(tp) + 1);
	ft_strcpy(ln, tp);
	while (tp)
	{
		lin = ft_realloc(ln, ft_strlen(ln), ft_strlen(tp) + ft_strlen(ln) + 1);
		ft_strcat(ln, tp);
		free(tp);
		tp = get_next_line(fd);
	}
	n = count_line(ln);
	free(tp);
	map = ft_split(ln, '\n');
	free(ln);
	close(fd);
	return (ta_to_ti(map, n));
}
