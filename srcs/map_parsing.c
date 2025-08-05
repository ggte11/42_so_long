/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:21:31 by mcardoso          #+#    #+#             */
/*   Updated: 2025/08/05 18:20:54 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	**matrix;
	char	*line;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	line = ft_strdup("");
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	matrix = ft_split(line, '\n');
	free(line);
	return (matrix);
}

int	map_is_valid(char *fdname)
{
	int	len;

	len = ft_strlen(fdname);
	return(len > 4 && !ft_strncmp(fdname + len - 4, ".ber", 4));
}

