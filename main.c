/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:02 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/28 15:04:49 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"

static void	handle_error_parse1(t_vars *v)
{
	if (!v->map)
	{
		perror("invalid map");
		exit(1);
	}
	else
		return ;
}

static void	handle_error_parse2(t_vars *v)
{
	if (!v->map1)
	{
		free_end(v);
		exit(1);
	}
	else
		return ;
}

static void	handle_error_mlx(t_vars *v)
{
	if (!v->mlx)
	{
		free_end(v);
		exit(1);
	}
	else
		return ;
}

int	main(int argc, char *argv[])
{
	t_vars	v;

	v = (t_vars){0};
	check_file(argv[1]);
	if (argc < 2)
		return (1);
	v.map = parse(argv[1], &v);
	handle_error_parse1(&v);
	v.map1 = parse(argv[1], &v);
	handle_error_parse2(&v);
	init_map_iso(&v);
	v.mlx = mlx_init();
	handle_error_mlx(&v);
	v.win = mlx_new_window(v.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	start_image(&v);
	print_lines(&v);
	print_column(&v);
	mlx_put_image_to_window(v.mlx, v.win, v.data.img, 0, 0);
	mlx_hook(v.win, DestroyNotify, 0, close_windows, &v);
	mlx_hook(v.win, KeyPress, KeyPressMask, window_action, &v);
	mlx_loop(v.mlx);
	mlx_destroy_image(v.mlx, v.data.img);
	mlx_destroy_window(v.mlx, v.win);
	mlx_destroy_display(v.mlx);
	free_end(&v);
}
