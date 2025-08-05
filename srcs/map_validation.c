/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:33:48 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/05 19:19:18 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	val_map_shape(char **matrix)
{
	int	i;
	int	first_len;
	int	current_len;

	if (!matrix || !matrix[0])
		return (0);
	first_len = ft_strlen(matrix[0]);
	i = 0;
	while (matrix[i])
	{
		current_len = ft_strlen(matrix[i]);
		if (current_len != first_len)
			return (0);
		i++;
	}
	return (1);
}

static int	val_map_walls(char **matrix)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	while (matrix[height])
		height++;
	width = ft_strlen(matrix[0]);
	i = 0;
	while (i < width)
	{
		if (matrix[0][i] != '1' || matrix[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (matrix[i][0] != '1' || matrix[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	val_map_cont(char **matrix, int collect, int exit, int player)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
				player++;
			if (matrix[i][j] == 'E')
				exit++;
			if (matrix[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collect < 1)
		return (1);
	return (0);
}

