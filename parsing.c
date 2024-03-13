/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:19:57 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/13 14:53:33 by vstineau         ###   ########.fr       */
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

void	set_point(char *line, int i, int j, t_vars *v)
{
	int **ls;

	ls =
}

static t_point	**ta_to_point(char **map, t_vars *v)
{
	t_point	**int_map;
	int	i;
	int	j;

	i = 0;
	v->apl = arg_per_line(map);
	int_map = malloc(sizeof(t_point *) * v->line_nb);
	if (!int_map)
		ft_free_and_exit(map, int_map,v);
	while (i < v->line_nb)
	{
		j = 0;
		int_map[i] = malloc(sizeof(t_point) *v->apl);
		if (!int_map)
			ft_free_and_exit(map, int_map,v);
		while (j <v->apl)
		{
			set_point(map[i], i, j, v);
			int_map[i][j].z = ft_atoi((const char *)map[i] + j);
			int_map[i][j].x = j;
			int_map[i][j].y = i;
			j++;
		}
		i++;
	}
	ft_free_char_tab(map);
	return (int_map);
}

t_point	**parse(char *argv, t_vars *v)
{
	int		fd;
	char	**map;
	char	*ln;
	char	*tp;

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
	v->line_nb = count_line(ln);
	free(tp);
	map = ft_split(ln, '\n');
	free(ln);
	close(fd);
	return (ta_to_point(map, v));
}
