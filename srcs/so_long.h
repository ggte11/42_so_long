/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:56:20 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/02 19:43:28 by mcardoso         ###   ########.fr       */
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
	void	*player;
}			t_sprites;

typedef struct s_game
{
	int		exit;
	int		moves;
	int		col_collected;
	int		col_total;
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


// map parsing
char	**read_map(int fd, t_data *data);
void	ver_empty_file(int bytes_read, t_data *data);
int		ver_newline(char *line);

// map validation
int		val_map_shape(t_data *data);
int		val_map_walls(t_data *data);
int		val_map_cont(t_data *data, int collect, int exit, int player);
int		val_map_chars(t_data *data);
int		val_path(t_data *data);

// map_val_utils
char	**copy_matrix(t_data *data);
int		find_player_pos(t_data *data, int *px, int *py);
void	flood_fill(t_data *data, int x, int y);
void	exit_pos(t_data *data);

// map initializer
void	initialize_game(t_data *data);
int		initialize_images(t_data *data);
void	draw_map(t_data *data);
void	draw_map2(t_data *data);

// movements
int		inputs(int key, t_data *data);
void	new_pos(t_data *data, int new_x, int new_y);
int		player_move(t_data *data, int x, int y);
int		close_game(t_data *data);

// utils
void	free_array(char **arr);
void	free_all(t_data *data);
void	free_maps(t_data *data);


#endif