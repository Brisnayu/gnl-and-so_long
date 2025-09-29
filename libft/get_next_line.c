/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:40:23 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/07/09 17:18:10 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	line_len;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line_len = i;
	if (buffer[i] == '\n')
		line_len++;
	line = malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, line_len + 1);
	return (line);
}

static char	*ft_create_remainder(char *buffer, size_t start_index)
{
	char	*remainder;
	size_t	j;
	size_t	rem_len;

	if (!buffer[start_index])
	{
		free(buffer);
		return (NULL);
	}
	rem_len = ft_strlen(buffer) - start_index;
	remainder = malloc((rem_len + 1) * sizeof(char));
	if (!remainder)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[start_index])
		remainder[j++] = buffer[start_index++];
	remainder[j] = '\0';
	free(buffer);
	return (remainder);
}

static char	*get_remainder(char *buffer)
{
	size_t	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	return (ft_create_remainder(buffer, i));
}

static char	*read_file(int fd, char *buffer)
{
	char	*old_buffer;
	char	*new_buffer;

	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		old_buffer = buffer;
		new_buffer = ft_read_and_join(fd, buffer);
		if (!new_buffer)
			return (NULL);
		if (new_buffer == old_buffer)
			break ;
		buffer = new_buffer;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_remainder(buffer);
	return (line);
}
