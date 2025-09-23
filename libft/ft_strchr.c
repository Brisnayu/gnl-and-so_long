/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:32:17 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/05 20:07:55 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	j;

	j = (unsigned char)c;
	while (*s)
	{
		if (*s == j)
			return ((char *)s);
		s++;
	}
	if (*s == j)
		return ((char *)s);
	return (NULL);
}
