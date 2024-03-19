# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zfavere <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 22:06:06 by zfavere           #+#    #+#              #
#    Updated: 2024/03/13 17:00:47 by zfavere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = cube.c \
	  main.c \
	  map_reader.c \
	  map_splitter.c \
	  parsing.c \
	  get_param.c \
	  error_parsing.c \
	  get_dir_path.c \
	  param_utils.c \
	  param_utils_2.c \
	  parse_map.c \
	  rgb_param.c \
	  render.c \
	  raycasting_loop.c \
	  get_good_wall.c \
	  player_move.c \
	  render_init.c \
	  cursor_cam.c \
	  parsing_utils.c \
	  raycasting_utils.c \
	  raycasting_utils2.c \


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

conf:
	rm $(OBJ) $(NAME)
	make all

.PHONY: all clean fclean re
