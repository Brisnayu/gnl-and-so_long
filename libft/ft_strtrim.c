/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:03:32 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/18 11:28:12 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty(void)
{
	char	*src;

	src = malloc(1);
	if (!src)
		return (NULL);
	src[0] = '\0';
	return (src);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	s1_len;
	size_t	start;
	size_t	len;

	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start == s1_len)
		return (ft_empty());
	s1_len--;
	while (s1_len > start && ft_strchr(set, s1[s1_len]))
		s1_len--;
	len = s1_len - start + 1;
	strtrim = (char *)malloc(sizeof(char) * (len + 1));
	if (!strtrim)
		return (NULL);
	ft_memcpy(strtrim, &s1[start], len);
	strtrim[len] = '\0';
	return (strtrim);
}
