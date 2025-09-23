/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:10:58 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/18 11:22:46 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	j;
	char			*temp;

	temp = NULL;
	j = (unsigned char)c;
	while (*s)
	{
		if (*s == j)
			temp = ((char *)s);
		s++;
	}
	if (j == '\0')
		return ((char *)s);
	return (temp);
}
