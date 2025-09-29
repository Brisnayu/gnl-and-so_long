/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:07:13 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:07:15 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_FUNCTIONS_H
# define SO_LONG_FUNCTIONS_H

# include "so_long.h"

//Imagenes
t_images load_images(void *mlx);
int      draw_map(t_game *game);

//Basic
void print_map(const char *filename);

char **read_map(const char *filename, int *rows, int *cols);

//check map
void check_map(t_game *game);

//cerrar ventana:
int close_window(t_game *game);

//move player
int handle_key(int keycode, t_game *game);

//-----------BONUS
void print_map_bonus(const char *filename);
int update_enemies(t_game_bonus *game_bonus);

#endif
