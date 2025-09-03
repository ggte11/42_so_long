/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:41:05 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/03 19:35:13 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_val(t_data *data)
{
	if (!val_map_cont(data, 0, 0, 0))
		return_error(4, &data);
	if (!val_map_shape(data))
		return_error(3, &data);
	if (!val_map_walls(data))
		return_error(3, &data);
	if (!val_map_chars(data))
		return_error(4, &data);
	if (!val_path(data))
		return_error(5, &data);
}

void	return_error(int error_code, t_data **data)
{
	if (error_code == 0)
		ft_putstr_fd("Error\nCode 0: No valid map file was provided \n", 2);
	else if (error_code == 1)
		ft_putstr_fd("Error\nCode 1: Unable to open file\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error\nCode 2: Empty map file \n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Error\nCode 3: Map with invalid shape/border \n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Error\nCode 4: Map with missing/invalid elements \n", 2);
	else if (error_code == 5)
		ft_putstr_fd("Error\nCode 5: Map with no valid path \n", 2);
	else if (error_code == 6)
		ft_putstr_fd("Error\nCode 6: Window initialization problem \n", 2);
	else if (error_code == 7)
		ft_putstr_fd("Error\nCode 7: Image initialization problem \n", 2);
	if (data)
		free_all(*data);
	exit (0);
}

int	main(int argc, char **argv)
{
	int		mapfd;
	t_data	*data;

	if (argc != 2 || (ft_strlen(argv[1]) <= 9)
		|| !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return_error (0, NULL);
	mapfd = open (argv[1], O_RDONLY);
	if (mapfd < 0)
		return_error(1, NULL);
	data = malloc (sizeof(t_data));
	if (!data)
		return (0);
	data = ft_memset (data, 0, sizeof(t_data));
	data->matrix = read_map(mapfd, data);
	close(mapfd);
	if (!data->matrix)
		return_error(2, &data);
	exit_pos(data);
	map_val(data);
	initialize_game(data);
	mlx_hook(data->game.win, KeyPress, KeyPressMask, inputs, data);
	mlx_hook(data->game.win, DestroyNotify, NoEventMask, close_game, data);
	mlx_loop(data->game.mlx);
	return (0);
}
