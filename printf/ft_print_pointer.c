/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:12:12 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/06/02 12:14:57 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;

	if (ptr == NULL)
		return ((int)write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	return (2 + ft_putnbr_base_unified(addr, BASE_HEX_LOWER, 1));
}
