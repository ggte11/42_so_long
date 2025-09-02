/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:14:48 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/02 20:03:03 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_data *data)
{
	data->game.mlx = mlx_init();
	if(!data->game.mlx)
		return_error(6, &data);
	data->game.win = mlx_new_window(data->game.mlx, 64 * data
		->width, 64 * data->height, "so_long");
	if(!data->game.win)
	{
		mlx_destroy_display(data->game.mlx);
		return_error(6, &data);
	}
	initialize_images(data);
	draw_map(data);
}

int	initialize_images(t_data *data)
{
	int	width;
	int	height;

	data->sprites.floor = mlx_xpm_file_to_image(
		data->game.mlx, "sprites/grass.xpm", &width, &height);
	data->sprites.player = mlx_xpm_file_to_image(
		data->game.mlx, "sprites/lion.xpm", &width, &height);
	data->sprites.wall = mlx_xpm_file_to_image(
		data->game.mlx, "sprites/tree64.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image(
		data->game.mlx, "sprites/cave.xpm", &width, &height);
	data->sprites.collectible = mlx_xpm_file_to_image(
		data->game.mlx, "sprites/meat.xpm", &width, &height);
	if (!data->sprites.floor || !data->sprites.player || !data
		->sprites.wall || !data->sprites.exit || !data
		->sprites.collectible)
		return (0);
	return (1);
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->matrix[y])
	{
		x = 0;
		while (data->matrix[y][x])
		{
			if (data->matrix[y][x] == '1')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.wall, x * 64, y * 64);
			if (data->matrix[y][x] == '0')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.floor, x * 64, y * 64);
			if (data->matrix[y][x] == 'C')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.collectible, x * 64, y * 64);
			x++;
		}
		y++;
	}
	draw_map2(data);
}

void	draw_map2(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->matrix[y])
	{
		x = 0;
		while (data->matrix[y][x])
		{
			if (data->matrix[y][x] == 'P')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.player, x * 64, y * 64);
			if (data->matrix[y][x] == 'E')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}