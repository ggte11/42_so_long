/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:21:31 by mcardoso          #+#    #+#             */
/*   Updated: 2025/09/03 19:41:24 by mcardoso         ###   ########.fr       */
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

char	*read_to_line(int fd, t_data *data)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	*line;
	char	*temp;

	(void)data;
	if (!(line = ft_strdup("")))
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
	{
		free(line);
		return (NULL);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	return (line);
}

char	**read_map(int fd, t_data *data)
{
	char	**matrix;
	char	*line;
	char	*temp;

	line = read_to_line(fd, data);
	if (!line)
		return (NULL);
	if (!ver_newline(line))
	{
		free(line);
		return (NULL);
	}
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
	{
		temp = line;
		line = ft_substr(line, 0, ft_strlen(line) - 1);
		free(temp);
	}
	matrix = ft_split(line, '\n');
	free(line);
	return (matrix);
}
