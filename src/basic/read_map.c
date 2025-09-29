/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:06:26 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:06:28 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static void	free_map(char **map, int rows)
{
	while (rows > 0)
		free(map[--rows]);
	free(map);
}

static int	handle_realloc_error(char **map, char *line, int rows, int fd)
{
	free(line);
	free_map(map, rows);
	close(fd);
	return (0);
}

static int	add_line_to_map(char ***map, char *line, int *rows, int *cols)
{
	char	**new_map;

	new_map = realloc(*map, sizeof(char *) * (*rows + 1));
	if (!new_map)
		return (0);
	*map = new_map;
	remove_newline(line);
	(*map)[*rows] = line;
	if (*rows == 0)
		*cols = ft_strlen(line);
	(*rows)++;
	return (1);
}

char	**read_map(const char *filename, int *rows, int *cols)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	*rows = 0;
	*cols = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line_to_map(&map, line, rows, cols))
		{
			handle_realloc_error(map, line, *rows, fd);
			return (NULL);
		}
	}
	close(fd);
	return (map);
}
