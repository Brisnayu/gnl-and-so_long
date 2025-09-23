/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:28:11 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/27 12:34:26 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_DECIMAL    "0123456789"
# define BASE_HEX_LOWER  "0123456789abcdef"
# define BASE_HEX_UPPER  "0123456789ABCDEF"

# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);

int		get_format(char value, va_list args);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_putnbr_base_unified(unsigned long nbr, char *base, int fd);
int		ft_putnbr_base_signed(long nbr, char *base, int fd);
int		ft_characters(char *c, int fd);
int		ft_print_pointer(void *ptr);

size_t	ft_strlen(const char *s);
#endif
