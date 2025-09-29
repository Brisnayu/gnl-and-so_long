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

CYAN =          \033[0;96m
DARK_GREEN =    \033[38;2;75;179;82m
ORANGE =        \033[38;5;209m
PINK =			\033[0;35m

CC = gcc

MLX_PATH = ./libs/minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd

FLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)
RM = rm -f

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = libs/printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC_DIR = src
SRC_DIR_BASIC = src/basic

BASIC_SRC = src/basic/read_map.c \
			src/basic/draw_map.c \
			src/basic/check_map.c \
			src/basic/close_window.c \
			src/basic/move_player.c

SRC = src/so_long.c src/basic/print_map.c $(BASIC_SRC)
BONUS_SRC = src/bonus/so_long_bonus.c src/bonus/print_map_bonus.c src/bonus/bonus.c $(BASIC_SRC)

OBJDIR = obj
BASIC_OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
BONUS_OBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(BONUS_SRC))

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@echo "$(CYAN) Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "libft compiled successfully 😎"

$(PRINTF):
	@echo "$(DARK_GREEN) Compiling printf..."
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "printf compiled successfully 👏"

$(NAME): $(LIBFT) $(PRINTF) $(BASIC_OBJ)
	@echo "$(ORANGE) Compiling so_long basic..."
	@$(CC) $(FLAGS) $(BASIC_OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "🌟so_long basic compiled successfully🌟"

$(NAME_BONUS): $(BONUS_OBJ) all
	@echo "$(PINK) Compiling so_long bonus..."
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "💫so_long_bonus compiled successfully💫"

# $(OBJDIR): 
# 	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c 
	@mkdir -p $(OBJDIR)/$(SRC_DIR)
	@mkdir -p $(OBJDIR)/$(SRC_DIR_BASIC)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
	@echo "🗑️ clean successfully🗑️"

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "🗑️ fclean successfully🗑️"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus


#Revisar el relink en los makefiles!!!!