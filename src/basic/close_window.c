/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:05:02 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:05:04 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int close_window(t_game *game)
{
  int i = 0;
  while (i < game->rows)
  {
    free(game->map[i]);
    i++;
  }
  free(game->map);

  mlx_destroy_window(game->mlx, game->win);
  mlx_destroy_display(game->mlx);

  exit (0);
}
