/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:05:38 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:05:39 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void move_player(t_game *game, int dx, int dy)
{
  char move;
  int new_x;
  int new_y;

  new_x = game->player_x + dx;
  new_y = game->player_y + dy;

  move = game->map[new_y][new_x];
  if (move == '1')
  {
    ft_printf("Oops, a wall🧱\n");
    game->moves++;
    return ;
  }
  if (move == 'C')
  {
    game->collected++;
  }
  if (move == 'E')
  {
    if (game->collected == game->total_collectibles)
    {
      ft_printf("You win!🌟👏🌟\n");
      ft_printf("🟢Total number of movements: %d\n", game->moves);
      close_window(game);
    }
    else
    {
      ft_printf("You need more collectibles😣\n");
      return ;
    }
  }
  if (move == 'B')
  {
    ft_printf("You lose❌😣\n");
    close_window(game);
  }

  game->map[game->player_y][game->player_x] = '0';
  game->map[new_y][new_x] = 'P';
  game->player_x = new_x;
  game->player_y = new_y;

  game->moves++;

  draw_map(game);
}

int handle_key(int keycode, t_game *game)
{
  if (keycode == KEY_ESC)
    close_window(game);
  else if (keycode == KEY_W)
  {
    ft_printf("⬆️\n");
    move_player(game, 0, -1);
  }
    else if (keycode == KEY_S)
  {
    ft_printf("⬇️\n");
    move_player(game, 0, 1);
  }
    else if (keycode == KEY_A)
  {
    ft_printf("⬅️\n");
    move_player(game, -1, 0);
  }
    else if (keycode == KEY_D)
  {
    ft_printf("➡️\n");
    move_player(game, 1, 0);
  }
  
  return (0);
}
