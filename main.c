/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:02 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/05 12:20:12 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->adr + (y * data->line_lenght + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	mouse_action(int keycode, t_vars *vars)
{
	if (keycode == 4)
	{
		vars->x++;
		vars->y++;
	}
	if (keycode == 5)
	{
		vars->x--;
		vars->y--;
	}
	return (0);
} 

int	windows_action(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	exit(0);
	return (0);
}
*/
int	main(int argc, char *argv[])
{
	t_vars	v;

	if (argc < 2)
		return (1);
	v.map = parse(argv[1]);
}
