/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:19:57 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/06 11:20:39 by vstineau         ###   ########.fr       */
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

static int	**ta_to_ti(char **map, int line_number, t_vars *vars)
{
	int	**int_map;
	int	i;
	int	j;

	i = 0;
	vars->apl = arg_per_line(map);
	vars->line_nb = line_number;
	int_map = malloc(sizeof(int *) * line_number);
	while (i < line_number)
	{
		j = 0;
		int_map[i] = malloc(sizeof(int) * vars->apl);
		while (j < vars->apl)
		{
			int_map[i][j] = ft_atoi((const char *)map[i] + j);
			j++;
		}
		i++;
	}
	ft_free_char_tab(map);
	return (int_map);
}

int	**parse(char *argv, t_vars *vars)
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
		ln = ft_realloc(ln, ft_strlen(ln), ft_strlen(tp) + ft_strlen(ln) + 1);
		ft_strcat(ln, tp);
		free(tp);
		tp = get_next_line(fd);
	}
	n = count_line(ln);
	free(tp);
	map = ft_split(ln, '\n');
	free(ln);
	close(fd);
	return (ta_to_ti(map, n, vars));
}
