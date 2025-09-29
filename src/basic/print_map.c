/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:05:53 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:06:03 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void print_map(const char *filename)
{
  t_game game;

  game.mlx = mlx_init();
  game.imgs = load_images(game.mlx);

  game.map = read_map(filename, &game.rows, &game.cols);
  if (!game.map)
  {
    ft_printf("Error reading map file\n");
    exit (1);
  }

  check_map(&game);
  game.moves = 0;
  game.collected = 0;
  
  game.win = mlx_new_window(game.mlx, game.cols * game.imgs.width, game.rows * game.imgs.height, "MINI HERA");

  draw_map(&game);

  mlx_expose_hook(game.win, draw_map, &game);

  mlx_hook(game.win, 17, 0, close_window, &game);

  mlx_hook(game.win, 2, 1L<<0, handle_key, &game);

  mlx_loop(game.mlx);
}
