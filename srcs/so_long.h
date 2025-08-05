/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:56:20 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/05 18:14:19 by mcardoso         ###   ########.fr       */
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

// map parsing


#endif