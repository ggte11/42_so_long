/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:13:42 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/02 19:03:48 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *data)
{
	if (data->matrix)
		free_array(data->matrix);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_data *data)
{
	if (data->sprites.collectible)
		mlx_destroy_image(data->game.mlx, data->sprites.collectible);
	if (data->sprites.floor)
		mlx_destroy_image(data->game.mlx, data->sprites.floor);
	if (data->sprites.wall)
		mlx_destroy_image(data->game.mlx, data->sprites.wall);
	if (data->sprites.exit)
		mlx_destroy_image(data->game.mlx, data->sprites.exit);
	if (data->sprites.player)
		mlx_destroy_image(data->game.mlx, data->sprites.player);
	if (data->game.mlx)
	{
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
	}
	free_maps(data);
}
