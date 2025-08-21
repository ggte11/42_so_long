/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:56:20 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/20 16:19:02 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_sprites
{
	void	*collectible;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*open_exit;
	void	*closed_exit;
	void	*player;
}			t_sprites;

typedef struct s_game
{
	int		exit_open;
	int		moves;
	int		col_collected;
	void	*img;
	void	*mlx;
	void	*win;
}			t_game;

typedef struct s_data
{
	char		**matrix;
	int			x_exit;
	int			y_exit;
	int			x_player;
	int			y_player;
	int			width;
	int			height;
	t_game		game;
	t_sprites	sprites;
}				t_data;

// so_long
void	return_error(int error_code, t_data **data);
void	map_val(t_data *data);
void	free_map(char **map);

// map parsing
char	**read_map(int fd, t_data *data);
void	ver_empty_file(int bytes_read, t_data *data);
int		ver_newline(char *line);

// map validation
int		val_map_shape(t_data *data);
int		val_map_walls(t_data *data);
int		val_map_cont(t_data *data, int collect, int exit, int player);
int		val_map_chars(t_data *data);

// game initialization
void	initialize_game(t_data *data);


// utils


#endif