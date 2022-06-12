# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alambert <alambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 11:54:36 by alambert          #+#    #+#              #
#    Updated: 2022/06/12 17:02:09 by alambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lr
MLX = ./mlx/libmlx.a
L42 = ./lib42/lib42.a
CC = clang

SRC =	lr.c \
		./src/data_utils.c \
		./src/display_utils0.c \
		./src/display_utils1.c \
		./src/regression_utils.c \
		./src/display.c \
		./src/user_utils.c \

SEC = 20
OBJ = $(SRC:.c=.o)
CFLAGS = -D SECONDS=$(SEC)
FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11 -L/usr/lib/aarch64 -Imlx mlx/libmlx.a

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ./mlx
	make re -C ./lib42
	$(CC) $(CFLAGS) $(FL_MLX) $(OBJ) -Llib42 $(L42) -o $(NAME) $(MLX)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./lib42
	$(RM) $(OBJ)

fclean: clean
	make clean -C ./mlx
	make fclean -C ./lib42
	$(RM) $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

re: fclean all

.PHONY: all clean fclean re
