# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:46:45 by dvalino-          #+#    #+#              #
#    Updated: 2023/06/26 14:55:33 by dvalino-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_PATH = ./lib/libft/

LIBFT_FILE = libft.a

MLX_FILE = libmlx.a

LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

LIB = libft/libft.a

MLX = mlx/Makefile.gen

MLX_FLAG = -lX11 -lXext

MLX_PATH = ./minilibx-linux/

MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX = $(MLX_LIB) $(MLX_FLAG)

FILES = main.c calcule.c checker.c checker2.c \
		utils.c render.c render_move.c print_map.c

SRC_DIR = ./src/

INC_DIR = ./include/

MY_SOURCE = $(addprefix $(SRC_DIR),$(FILES))

MY_OBJECTS = ${MY_SOURCE:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(LIB) $(MLX) $(MY_OBJECTS) $(NAME)

$(NAME): 
	$(CC) $(MY_OBJECTS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

$(LIB):
	@make -s -C $(LIBFT_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f ${NAME}
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY : all clean fclean re
