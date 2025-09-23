/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:40:23 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/07/12 11:51:58 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	strjoin_len;
	size_t	i;
	char	*strjoin;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	strjoin_len = ft_strlcpy(strjoin, s1, s1_len + s2_len + 1);
	i = 0;
	while (s2[i] && (strjoin_len + i + 1) < s1_len + s2_len + 1)
	{
		strjoin[strjoin_len + i] = s2[i];
		i++;
	}
	strjoin[strjoin_len + i] = '\0';
	return (strjoin);
}

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
