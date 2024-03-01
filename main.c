/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:02 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/01 16:34:25 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->adr + (y * data->line_lenght + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	close_windows(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_vars vars;
	int x = 500;
	int y = 500;
		
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 1089, "FDF TEST");
	vars.img.img = mlx_new_image(vars.mlx, 960, 1080);
	vars.img.adr = mlx_get_data_addr(vars.img.img, &vars.img.bit_per_pixel, &vars.img.line_lenght, &vars.img.endian);
	while (x < 800)
	{
		my_mlx_pixel_put(&vars.img, x++, y++, 0x00FF660);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	}
	mlx_hook(vars.win, KeyPress, KeyPressMask, close_windows, &vars);
	mlx_loop(vars.mlx);
}
