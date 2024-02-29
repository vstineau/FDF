/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:02 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/29 14:45:09 by vstineau         ###   ########.fr       */
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 500;
	int y = 500;
		
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 1089, "FDF TEST");
	img.img = mlx_new_image(mlx, 960, 1080);
	img.adr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_lenght, &img.endian);
	while (x < 800)
	{
		my_mlx_pixel_put(&img, x++, y++, 0x00FF660);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	mlx_loop(mlx);
}
