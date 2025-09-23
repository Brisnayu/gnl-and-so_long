/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:04:09 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/31 20:11:08 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (-1);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if ((base[i] == '+') || (base[i] == '-'))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_putnbr_base_unified(unsigned long nbr, char *base, int fd)
{
	size_t	base_number;
	int		count;

	if (ft_valid_base(base) == -1)
		return (0);
	base_number = (unsigned long)ft_strlen(base);
	count = 0;
	if (nbr >= base_number)
		count += ft_putnbr_base_unified(nbr / base_number, base, fd);
	count += ft_putchar_fd_printf(base[nbr % base_number], fd);
	return (count);
}

int	ft_putnbr_base_signed(long nbr, char *base, int fd)
{
	int				count;
	unsigned long	n;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_fd_printf('-', fd);
		if (nbr == LONG_MIN)
			n = (unsigned long)LONG_MAX + 1;
		else
			n = (unsigned long)(-nbr);
	}
	else
		n = (unsigned long)nbr;
	count += ft_putnbr_base_unified(n, base, fd);
	return (count);
}
