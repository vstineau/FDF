/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:19:38 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/29 17:06:34 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_join_free(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	free(line);
	if (!temp)
		exit(1);
	return (temp);
}

void	check_apl(char **map)
{
	int	i;
	int	cw;

	i = 0;
	cw = arg_per_line(&map[i]);
	while (map[i])
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

void	check_file(char *argv)
{
	size_t	lenght;

	lenght = ft_strlen(argv);
	if (lenght < 5)
	{
		perror("invalid file");
		exit(1);
	}
	if (ft_strcmp(&argv[lenght - 4], ".fdf"))
	{
		perror("invalid file");
		exit(1);
	}
	else
		return ;
}

char	*read_map(char *argv)
{
	int		fd;
	int		rd;
	char	*map;
	char	buffer[4097];

	fd = open(argv, O_RDONLY);
	rd = 4096;
	map = ft_calloc(1, 1);
	if (!map)
		exit(1);
	while (rd >= 4096)
	{
		rd = read(fd, buffer, 4096);
		if (rd == -1)
		{
			free(map);
			return (NULL);
		}
		buffer[rd] = '\0';
		map = ft_join_free(map, buffer);
	}
	close(fd);
	return (map);
}
