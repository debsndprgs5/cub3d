# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zfavere <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 22:06:06 by zfavere           #+#    #+#              #
#    Updated: 2023/02/20 19:20:13 by zfavere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = cube.c \
	  main.c \
	  map_reader.c \
	  map_splitter.c \
	  parsing.c

OBJ = $(SRC:.c=.o)
NAME = cub3d

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd mlx_linux && make
	cd ./Includes/libft && make
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) Includes/libft/libft.a

clean:
	rm -f $(OBJ)
	cd Includes/libft && make clean
	cd mlx_linux && make clean

fclean: clean
	rm -f $(NAME)
	rm -f Includes/libft/libft.a
	rm -f mlx_linux/libmlx.a

re: fclean all

.PHONY: all clean fclean re
