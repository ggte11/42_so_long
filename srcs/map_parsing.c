/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:21:31 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/01 15:02:45 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ver_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ver_empty_file(int bytes_read, t_data *data)
{
	if (bytes_read == 0)
		return_error(2, &data);
}

char	**read_map(int fd, t_data *data)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	**matrix;
	char	*line;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	line = ft_strdup("");
	ver_empty_file(bytes_read, data);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		if (!line)
			return_error(2, &data);
		free(temp);
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	if (!ver_newline(line))
		return_error(3, &data);
	matrix = ft_split(line, '\n');
	free(line);
	return (matrix);
}
