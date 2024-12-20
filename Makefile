# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:38:27 by fidrandr          #+#    #+#              #
#    Updated: 2024/12/20 12:43:51 by fidrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scale

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -I./minilibx-linux -I./libft -I./include

SRC = ./main.c

OBJ = $(SRC:.c=.o)

MLX = ./minilibx-linux/libmlx_Linux.a

LIBFT = ./libft/libft.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

do: all
	./$(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx-linux

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./libft -L./minilibx-linux/ -lft  -lpng -lmlx_Linux -lm -lXext -lX11 -o $(NAME) 

clean:
# 	make clean -C ./libft
# 	make clean -C ./minilibx-linux
	rm -f $(OBJ)

fclean: clean
# 	rm -rf $(LIBFT)
# 	rm -rf $(MLX)
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean re all
