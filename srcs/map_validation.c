/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:33:48 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/13 18:39:23 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	val_map_shape(t_map *data)
{
	int	i;
	int	first_len;
	int	current_len;

	if (!data->matrix || !data->matrix[0])
		return (0);
	first_len = ft_strlen(data->matrix[0]);
	i = 0;
	while (data->matrix[i])
	{
		current_len = ft_strlen(data->matrix[i]);
		if (current_len != first_len)
			return (0);
		i++;
	}
	return (1);
}

int	val_map_walls(t_map *data)
{
	int	i;
	int	width;

	i = 0;
	while (data->matrix[i])
		i++;
	data->height = i;
	width = ft_strlen(data->matrix[0]);
	i = 0;
	while (i < width)
	{
		if (data->matrix[0][i] != '1' || data->matrix[data->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->matrix[i][0] != '1' || data->matrix[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	val_map_cont(t_map *data, int collect, int exit, int player)
{
	int	i;
	int	j;

	i = 0;
	while (data->matrix[i])
	{
		j = 0;
		while (data->matrix[i][j])
		{
			if (data->matrix[i][j] == 'P')
				player++;
			if (data->matrix[i][j] == 'E')
				exit++;
			if (data->matrix[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collect < 1)
		return (0);
	return (1);
}

int	val_map_chars(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->matrix[i])
	{
		j = 0;
		while (data->matrix[i][j])
		{
			if (data->matrix[i][j] != '1' && data->matrix[i][j] != '0'
				&& data->matrix[i][j] != 'C' && data->matrix[i][j] != 'P'
				&& data->matrix[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_map *data, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}