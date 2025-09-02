/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:03:16 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/01 18:27:44 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_matrix(t_data *data)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (data->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < data->height)
	{
		copy[i] = ft_strdup(data->matrix[i]);
		if (!copy[i])
		{
			while(--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	find_player_pos(t_data *data, int *px, int *py)
{
	int	i;
	int	j;

	j = 0;
	while (data->matrix[j])
	{
		i = 0;
		while (data->matrix[j][i])
		{
			if (data->matrix[j][i] == 'P')
			{
				*px = i;
				*py = j;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	exit_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->matrix[y])
	{
		x = 0;
		while (data->matrix[y][x])
		{
			if (data->matrix[y][x] == 'E')
			{
				data->y_exit = y;
				data->x_exit = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if(data->matrix[y][x] == '1' || data->matrix[y][x] == 'F')
		return ;
	data->matrix[y][x] = 'F';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
