/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:02:48 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/27 12:06:08 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_numbers(char value, va_list args, int fd)
{
	int	num;

	if (value == 'd' || value == 'i')
	{
		num = va_arg(args, int);
		return (ft_putnbr_base_signed(num, BASE_DECIMAL, fd));
	}
	return (-1);
}

static int	handle_numbers_long(char value, va_list args, int fd)
{
	unsigned int	unum;
	unsigned long	ul_num;

	if (value == 'u')
	{
		unum = va_arg(args, unsigned int);
		return (ft_putnbr_base_unified((unsigned long)unum, BASE_DECIMAL, fd));
	}
	if (value == 'X')
	{
		unum = va_arg(args, unsigned int);
		ul_num = (unsigned long)unum;
		return (ft_putnbr_base_unified(ul_num, BASE_HEX_UPPER, fd));
	}
	if (value == 'x')
	{
		unum = va_arg(args, unsigned int);
		ul_num = (unsigned long)unum;
		return (ft_putnbr_base_unified(ul_num, BASE_HEX_LOWER, fd));
	}
	return (-1);
}

static int	handle_chars(char value, va_list args, int fd)
{
	char	*cstr;
	char	c;

	if (value == 'c')
	{
		c = (char)va_arg(args, int);
		return (ft_putchar_fd_printf(c, fd));
	}
	if (value == 's')
	{
		cstr = va_arg(args, char *);
		return (ft_characters(cstr, fd));
	}
	return (-1);
}

static int	handle_pointer(char value, va_list args)
{
	void	*ptr;

	if (value == 'p')
	{
		ptr = va_arg(args, void *);
		return (ft_print_pointer(ptr));
	}
	return (-1);
}

int	get_format(char value, va_list args)
{
	int	fd;

	fd = 1;
	if (value == 'd' || value == 'i')
		return (handle_numbers(value, args, fd));
	if (value == 'u' || value == 'x' || value == 'X')
		return (handle_numbers_long(value, args, fd));
	if (value == 'c' || value == 's')
		return (handle_chars(value, args, fd));
	if (value == 'p')
		return (handle_pointer(value, args));
	if (value == '%')
	{
		return (ft_putchar_fd_printf('%', fd));
	}
	ft_putchar_fd_printf('%', fd);
	ft_putchar_fd_printf(value, fd);
	return (2);
}
