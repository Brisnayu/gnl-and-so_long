/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:06:26 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/09/19 20:06:28 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(const char *filename, int *rows, int *cols)
{
  int fd;
  char **map;
  char *line;

  fd = open(filename, O_RDONLY);
  if (fd < 0)
    return (NULL);

  map = NULL;
  *rows = 0;
  *cols = 0;

  while((line = get_next_line(fd)) != NULL)
  {
    map = realloc(map, sizeof(char *) * (*rows + 1));
    if (!map)
    {
      free(line);
      close(fd);
      return (NULL);
    }

    map[*rows] = line;
    if (*rows == 0)
    {
      while (line[*cols] && line[*cols] != '\n')
        (*cols)++;
    }
    (*rows)++;
  }
  close(fd);
  return (map);
}
