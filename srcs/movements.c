/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:23:06 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/02 19:37:23 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	inputs(int key, t_data *data)
{
	if (key == XK_Escape)
		close_game(data);
	if (key == XK_w)
		player_move(data, 0, -1);
	if (key == XK_s)
		player_move(data, 0, 1);
	if (key == XK_a)
		player_move(data, -1, 0);
	if (key == XK_d)
		player_move(data, 1, 0);
	return (1);
}

void	new_pos(t_data *data, int new_x, int new_y)
{
	if (data->y_player == data->y_exit && data->x_player == data->x_exit)
		data->matrix[data->y_player][data->x_player] = 'E';
	else
		data->matrix[data->y_player][data->x_player] = '0';
	data->y_player = new_y;
	data->x_player = new_x;
	data->matrix[new_y][new_x] = 'P';
	draw_map(data);
	ft_printf("Moves: %d\n", data->game.moves);
}

int	player_move(t_data *data, int x, int y)
{
	int		new_x;
	int		new_y;
	char	coords;

	new_x = data->x_player + x;
	new_y = data->y_player + y;
	coords = data->matrix[new_y][new_x];
	if (coords == '1')
		return (0);
	data->game.moves++;
	new_pos(data, new_x, new_y);
	if (coords == 'E' && data->game.exit == 1)
	{
		ft_printf("Im gonna Mimir -_-");
		close_game(data);
	}
	if( coords == 'C')
	{
		data->game.col_collected++;
		if (data->game.col_collected == data->game.col_total)
			data->game.exit = 1;
	}
	return (1);
}

int	close_game(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}
