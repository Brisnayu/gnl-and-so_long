/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:47:06 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/07/08 21:46:39 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_and_join(int fd, char *buffer)
{
	char		*temp;
	char		*joined;
	ssize_t		r;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	r = read(fd, temp, BUFFER_SIZE);
	if (r == -1)
	{
		free(temp);
		if (buffer)
			free(buffer);
		return (NULL);
	}
	if (r == 0)
	{
		free(temp);
		return (buffer);
	}
	temp[r] = '\0';
	joined = ft_strjoin(buffer, temp);
	free(buffer);
	free(temp);
	return (joined);
}
