/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:06:46 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:06:48 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"
//# include <stdlib.h> //exit

//Revisar y cambiar con mi librería de get next line
# include <fcntl.h> //open
//# include <unistd.h> //close

//Variables para mover mi jugador
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_images
{
  void *hera;
  void *wall;
  void *empty;
  void *collectable;
  void *exit;
  void *bad_puppy;
  int width;
  int height;
} t_images;

typedef struct s_game
{
  void        *mlx; 
  void        *win;
  t_images    imgs;
  char        **map;
  int         rows;
  int         cols;
  int         total_collectibles;
  int         collectibles_found;
  int         exit_found;
  int         player_x;
  int         player_y;
  int         moves;
  int         collected;
} t_game;

typedef struct s_game_bonus
{
  t_game      base;
  int         enemy_x;
  int         enemy_y;
} t_game_bonus;

# include "so_long_functions.h"

#endif
