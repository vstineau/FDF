/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:19:57 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/27 16:46:18 by vstineau         ###   ########.fr       */
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

static void	set_line(char **ls, int i, t_vars *v, t_point *map)
{
	int	j;
	int	k;

	j = 0;
	v->default_color = DEFAULT_COLOR;
	v->init = true;
	while (j < v->apl)
	{
		k = 0;
		map[j].x = j;
		map[j].y = i;
		while (ls[j][k] && ls[j][k] != ',')
		{
			map[j].z = (float)ft_atoi((const char *)ls[j] + k);
			while (ls[j][k] && ls[j][k] != ',')
				k++;
		}
		if (ls[j][k] == ',')
			map[j].color = get_color((const char *)ls[j] + k);
		else
			map[j].color = v->default_color;
		j++;
	}
}

static t_point	**ta_to_point(char **map, t_vars *v)
{
	t_point		**int_map;
	char		**ls;
	int			i;

	i = 0;
	v->apl = arg_per_line(map);
	v->height = 0.1;
	int_map = ft_calloc(sizeof(t_point *), v->line_nb);
	if (!int_map)
		ft_free_and_exit(map, int_map, v);
	while (i < v->line_nb)
	{
		int_map[i] = malloc(sizeof(t_point) * v->apl);
		if (!int_map)
			ft_free_and_exit(map, int_map, v);
		ls = ft_split(map[i], 32);
		if (!ls)
			ft_free_and_exit(map, int_map, v);
		set_line(ls, i, v, int_map[i]);
		ft_free_char_tab(ls);
		i++;
	}
	ft_free_char_tab(map);
	return (int_map);
}

int	arg_per_line(char **map)
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

t_point	**parse(char *argv, t_vars *v)
{
	int		fd;
	char	**map;
	char	*ln;
	char	*tp;

	fd = open(argv, O_RDONLY);
	tp = get_next_line(fd);
	if (!tp)
		return (NULL);
	ln = malloc(sizeof(char) * ft_strlen(tp) + 1);
	error_ln(ln);
	ft_strcpy(ln, tp);
	while (tp)
	{
		ln = ft_realloc(ln, ft_strlen(ln), ft_strlen(tp) + ft_strlen(ln) + 1);
		error_ln(ln);
		ft_strcat(ln, tp);
		free(tp);
		tp = get_next_line(fd);
	}
	v->line_nb = count_line(ln);
	free(tp);
	map = ft_split(ln, '\n');
	free_ln(map, ln);
	check_apl(map);
	close(fd);
	return (ta_to_point(map, v));
}
