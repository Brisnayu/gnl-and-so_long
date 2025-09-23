/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:04:53 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:04:55 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_rectangular(t_game *game)
{
  int i;
  int len;

  i = 0;
  while (i < game->rows)
  {
    len = ft_strlen(game->map[i]);
    if (len != game->cols)
      exit (1);
    i++;
  }
}

static void check_walls(t_game *game)
{
  int i;
  int j;

  i = 0;
  while (i < game->cols)
  {
    if(game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
      exit (1);
    i++;
  }
  j = 0;
  while (j < game->rows)
  {
    if(game->map[j][0] != '1' || game->map[j][game->cols - 1] != '1')
      exit (1);
    j++;
  }
}

static void check_characters(t_game *game)
{
  int i;
  int j;
  int player;
  int map_exit;
  int collectable;

  player = 0;
  map_exit = 0;
  collectable = 0;

  i = 0;
  while (i < game->rows)
  {
    j = 0;
    while (j < game->cols)
    {
      if (game->map[i][j] == 'P')
        player++;
      else if (game->map[i][j] == 'E')
        map_exit++;
      else if (game->map[i][j] == 'C')
        collectable++;
      else if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'B')
      {
        ft_printf("Invalid character 🫥\n");
        exit (1);
      }
      j++;
    }
    i++;
  }

  if(player != 1 || map_exit != 1 || collectable == 0)
  {
    ft_printf("The map must have 1 P, 1 E and at least 1 C\n");
    exit (1);
  }

  game->total_collectibles = collectable;

  ft_printf("Correct map ✅\n");
}

static char **copy_map(char **map, int rows, int cols)
{
  char **map_copy;
  int i;
  int j;

  map_copy = malloc(sizeof(char *) * (rows + 1));
  if (!map_copy)
      return (NULL);
  i = 0;
  while (i < rows)
  {
      map_copy[i] = malloc(sizeof(char) * (cols + 1));
      if (!map_copy[i])
          return (NULL);
      j = 0;
      while (j < cols)
      {
          map_copy[i][j] = map[i][j];
          j++;
      }
      map_copy[i][j] = '\0';
      i++;
  }
  map_copy[i] = NULL;
  return (map_copy);
}

static void flood_fill(char **map, t_game *game, int x, int y)
{
  if (x < 0 || y < 0 || x >= game->rows || y >= game->cols)
    return ;
  if (map[x][y] == '1' || map[x][y] == 'V')
    return ;

  if(map[x][y] == 'C')
    game->collectibles_found++;
  if(map[x][y] == 'E')
    game->exit_found++;

  map[x][y] = 'V';

  flood_fill(map, game, x+1, y);
  flood_fill(map, game, x-1, y);
  flood_fill(map, game, x, y+1);
  flood_fill(map, game, x, y-1);
}

static void flood_fill_from_P(t_game *game, char **temp_map)
{
  int i;
  int j;

  game->collectibles_found = 0;
  game->exit_found = 0;

  i = 0;
  while(i < game->rows)
  {
    j = 0;
    while(j < game->cols)
    {
      if(game->map[i][j] == 'P')
      {
        game->player_y = i;
        game->player_x = j;
        flood_fill(temp_map, game, i, j);
        return ;
      }
      j++;
    }
    i++;
  }
}

static void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void check_map(t_game *game)
{
  char **temp_map;

  check_rectangular(game);
  check_walls(game);
  check_characters(game);

  temp_map = copy_map(game->map, game->rows, game->cols);
  flood_fill_from_P(game, temp_map);

  free_map(temp_map);

  if(game->collectibles_found != game->total_collectibles || game->exit_found != 1)
  {
    ft_printf("Unsolvable map❌\n");
    //exit(1);
  }
}
