/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:06:17 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:06:19 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map_bonus(const char *filename)
{
    t_game_bonus game_bonus;

    game_bonus.base.mlx = mlx_init();
    game_bonus.base.imgs = load_images(game_bonus.base.mlx);

    game_bonus.base.map = read_map(filename, &game_bonus.base.rows, &game_bonus.base.cols);
    if (!game_bonus.base.map)
    {
        ft_printf("Error reading map file\n");
        exit (1);
    }

    check_map(&game_bonus.base);
    game_bonus.base.moves = 0;
    game_bonus.base.collected = 0;

    game_bonus.base.win = mlx_new_window(
        game_bonus.base.mlx,
        game_bonus.base.cols * game_bonus.base.imgs.width,
        game_bonus.base.rows * game_bonus.base.imgs.height,
        "MINI HERA BONUS"
    );

    draw_map(&game_bonus.base);

    mlx_expose_hook(game_bonus.base.win, draw_map, &game_bonus.base);
    mlx_hook(game_bonus.base.win, 17, 0, close_window, &game_bonus.base);
    mlx_hook(game_bonus.base.win, 2, 1L<<0, handle_key, &game_bonus.base);

    mlx_loop_hook(game_bonus.base.mlx, update_enemies, &game_bonus);

    mlx_loop(game_bonus.base.mlx);
}
