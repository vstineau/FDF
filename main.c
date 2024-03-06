/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:02 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/06 17:50:28 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"

int	main(int argc, char *argv[])
{
	t_vars	v;

	if (argc < 2)
		return (1);
	v.map = parse(argv[1], &v);
	v.mlx = mlx_init();
	if (!v.mlx)
		return (1);
	v.win = mlx_new_window(v.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx_hook(v.win, KeyPress, KeyPressMask, window_action, &v);
	mlx_loop(v.mlx);
	//mlx_destroy_image(v.mlx, v.img.img);
	mlx_destroy_window(v.mlx, v.win);
	mlx_destroy_display(v.mlx);
	free_end(&v);
}
