/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:54:32 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/12 19:08:11 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy_s;

	len = ft_strlen(s);
	copy_s = (char *)malloc((len + 1) * sizeof(char));
	if (!copy_s)
		return (NULL);
	ft_strlcpy(copy_s, s, len + 1);
	return (copy_s);
}
