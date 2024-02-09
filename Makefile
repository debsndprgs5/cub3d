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

SRC =	check_map.c \
		cube.c \
		main.c \
		map_reader.c \
		map_splitter.c \
		parsing.c \


OBJ = $(SRC:.c=.o)

NAME = cub3d

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(NAME): $(OBJ) $(LIB) Makefile
	cd Includes/libft ; make
	$(CC) $(CFLAGS) $(OBJ) libft.a Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm -f $(OBJ) $(OBJ)
	cd Includes/libft ; make clean
fclean: clean
	rm -f $(NAME)
	rm -f Includes/libft/libft.a
re: fclean all
PHONY: all bonus clean fclean re
