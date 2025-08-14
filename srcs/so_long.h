/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:56:20 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/13 18:42:04 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"

# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**matrix;
}			t_map;

// so_long
void	return_error(int error_code, t_map **data);
void	map_val(t_map *data);
void	free_map(char **map);

// map parsing
char	**read_map(int fd, t_map *data);
int		map_is_valid(char *fdname);
void	ver_empty_file(int bytes_read, t_map *data);
int		ver_newline(char *line);

// map validation
int		val_map_shape(t_map *data);
int		val_map_walls(t_map *data);
int		val_map_cont(t_map *data, int collect, int exit, int player);
int		val_map_chars(t_map *data);

// utils


#endif