/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:14:48 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/20 15:14:24 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_data *data)
{
	data->game.mlx = mlx_init();
	if(!data->game.mlx)
		return_error(6, &data);
	data->game.win = mlx_new_window(data->game.mlx, 1000, 1000, "so_long");
	if(!data->game.win)
	{
		mlx_destroy_display(data->game.mlx);
		return_error(6, &data);
	}
}