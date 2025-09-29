/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:04:37 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:04:41 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void find_enemy(t_game_bonus *game_bonus)
{
  int i;
  int j;

  game_bonus->enemy_x = -1;
  game_bonus->enemy_y = -1;

  i = 0;
  while(i < game_bonus->base.rows)
  {
    j = 0;
    while(j < game_bonus->base.cols)
    {
      if(game_bonus->base.map[i][j] == 'B')
      {
        game_bonus->enemy_y = i;
        game_bonus->enemy_x = j;
        return ;
      }
      j++;
    }
    i++;
  }
}

int update_enemies(t_game_bonus *game_bonus)
{
  static int frames = 0;

  frames++;
  //Poner valor como una macro!!!
  //Tambien puedo indicar la velocidad por la terminal. Como dificultad
  if (frames < 5000)
    return (0);
  frames = 0;

  find_enemy(game_bonus);
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  int dir = rand() % 4;

  int new_x = game_bonus->enemy_x + dx[dir];
  int new_y = game_bonus->enemy_y + dy[dir];

  char move = game_bonus->base.map[new_y][new_x];

  if (move == 'E' || move == 'C')
    return (0);

  if (move != '1')
  {
    if (move == 'P')
    {
      ft_printf("Trapped, game over 😣\n");
      close_window(&game_bonus->base);
    }
    else
    {
      game_bonus->base.map[game_bonus->enemy_y][game_bonus->enemy_x] = '0';
      game_bonus->base.map[new_y][new_x] = 'B';
      game_bonus->enemy_x = new_x;
      game_bonus->enemy_y = new_y;
      draw_map(&game_bonus->base);
    }
  }

  return (0);
}
