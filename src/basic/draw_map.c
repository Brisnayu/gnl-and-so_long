/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:05:12 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:05:14 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_images  load_images(void *mlx)
{
  t_images imgs;

  imgs.width = 0;
  imgs.height = 0;

  imgs.hera = mlx_xpm_file_to_image(mlx, "./texture/hera.xpm", &imgs.width, &imgs.height);
  imgs.wall = mlx_xpm_file_to_image(mlx, "./texture/wall.xpm", &imgs.width, &imgs.height);
  imgs.empty = mlx_xpm_file_to_image(mlx, "./texture/empty.xpm", &imgs.width, &imgs.height);
  imgs.collectable = mlx_xpm_file_to_image(mlx, "./texture/collectable.xpm", &imgs.width, &imgs.height);
  imgs.exit = mlx_xpm_file_to_image(mlx, "./texture/exit.xpm", &imgs.width, &imgs.height);
  imgs.bad_puppy = mlx_xpm_file_to_image(mlx, "./texture/bad_puppy.xpm", &imgs.width, &imgs.height);

  if (!imgs.hera || !imgs.wall || !imgs.empty || !imgs.collectable || !imgs.exit)
  {
    ft_printf("Error loading some image\n");
    exit(1);
  }
  return (imgs);
}

static void draw_values(t_game *game, char value, int x, int y)
{
  if (value == 'P')
    mlx_put_image_to_window(game->mlx, game->win, game->imgs.hera, x * game->imgs.width, y * game->imgs.height);
  else if (value == '1')
    mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall, x * game->imgs.width, y * game->imgs.height);
  else if (value == '0')
    mlx_put_image_to_window(game->mlx, game->win, game->imgs.empty, x * game->imgs.width, y * game->imgs.height);
  else if (value == 'C')
    mlx_put_image_to_window(game->mlx, game->win, game->imgs.collectable, x * game->imgs.width, y * game->imgs.height);
  else if (value == 'E')
    mlx_put_image_to_window(game->mlx, game->win, game->imgs.exit, x * game->imgs.width, y * game->imgs.height);
  else if (value == 'B')
    mlx_put_image_to_window(game->mlx, game->win, game->imgs.bad_puppy, x * game->imgs.width, y * game->imgs.height);
}

int draw_map(t_game *game)
{
  int i;
  int j;

  i = 0;
  while (i < game->rows)
  {
    j = 0;
    while (j < game->cols)
    {
      draw_values(game, game->map[i][j], j, i);
      j++;
    }
    i++;
  }
  return (0);
}
