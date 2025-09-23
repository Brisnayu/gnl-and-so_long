# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 20:05:23 by bpaez-mo          #+#    #+#              #
#    Updated: 2025/09/19 20:05:26 by bpaez-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd

FLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)
RM = rm -f

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

BASIC_SRC = read_map.c \
						draw_map.c \
						temporary_gnl.c \
						check_map.c \
						close_window.c \
						move_player.c

SRC = so_long.c print_map.c $(BASIC_SRC)
BONUS_SRC = so_long_bonus.c print_map_bonus.c bonus.c $(BASIC_SRC)

OBJDIR = obj
BASIC_OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJDIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)
	@echo "libft compiled successfully 😎"

$(PRINTF):
	@echo "Compiling printf..."
	$(MAKE) -C $(PRINTF_DIR)
	@echo "printf compiled successfully 👏🏻"

$(NAME): $(LIBFT) $(PRINTF) $(BASIC_OBJ)
	@echo "Compiling so_long basic..."
	@$(CC) $(FLAGS) $(BASIC_OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "🌟so_long basic compiled successfully🌟"

$(NAME_BONUS): $(BONUS_OBJ)
	@echo "Compiling so_long bonus..."
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "💫so_long_bonus compiled successfully💫"

$(OBJDIR): 
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
