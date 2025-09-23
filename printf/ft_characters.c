/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:16:26 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/30 18:20:24 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_characters(char *c, int fd)
{
	int	i;

	if (c == NULL)
		return ((int)write(1, "(null)", 6));
	i = 0;
	while (c[i])
	{
		ft_putchar_fd_printf(c[i], fd);
		i++;
	}
	return (i);
}
