/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:06:59 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:07:01 by bpaez-mo         ###   ########.fr       */
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

  print_map_bonus(argv[1]);

  return (0);
}
