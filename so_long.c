/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:06:35 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:06:37 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    ft_printf("Please select the map you want to open!🤨\n");
    return (0);
  }

  print_map(argv[1]);

  return (0);
}
