/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/08 18:37:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "./Includes/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

#define WIDTH 960

#define LENGTH 540

#define FOV 80

// Walls/Ground raw images

typedef struct s_frames
{
	void **w_no_img;
	void **w_so_img;
	void **w_ea_img;
	void **w_we_img;
}	t_frames;

typedef struct s_ppos
{
	double x;
	double y;
}	t_ppos;

// Main struct
// Paths are N->0 S->1 E->2 W->3 in this order
typedef struct s_game
{
	t_frames	*frames;
	// int			ymin;
	int			ymax;
	// int			xmin;
	int			xmax;
	char		**paths;
	char		**map;
	void		*mlx_session;
	void		*mlx_window;
	int			groundcol[4];
	bool 		ground_check;
	int			skycol[4];
	bool		sky_check;
	t_ppos		ppos;
}	t_game;

typedef enum ErrorCode {
    MORE_THAN_ONE_DIRECTION = 1,
    MAP_NOT_ENCLOSED_BY_WALLS,
    CANNOT_OPEN_NORTH_ASSET,
    CANNOT_OPEN_SOUTH_ASSET,
    CANNOT_OPEN_EAST_ASSET,
    CANNOT_OPEN_WEST_ASSET,
    ARGS_UNDEFINED,
    RGB_RANGE,
    RGB_ARGS,
    INVALID_CONFIG,
    MEM_FAIL,
    FILE_NOT_EXIST,
    INVALID_MAP,
    MAP_NOT_EXIST,
	WRONG_EXTENT,
	DUP_ARGS , 
	MISSING_ARGS,
	POS_ERROR
} ErrorCode;


// PARSING FUNCTIONS //

int		raycasting_loop(t_game *game);
char	**readmap(char *pathtofile);
void	freetab(char **str);
int		get_param(char **config_file,  t_game *game);
int		split_map(char** map, char*** part1, char*** part2);
int 	get_color(char *parse_line, int *stack);
int		check_split_col(char **split);
int		init_struct(t_game *game, char **config_file);
char	*clean_first_spaces(char *str, int i);
char	*removes_spaces(char *spc_line);
char 	*parse_config_line(char *line);
int 	get_dir_path(char *path, char **stack, int index);
int		free_game(t_game *game);
int		map_check(char **map);
void	get_format(char ***parsedmap);
int		printerror(ErrorCode err);

// RENDERING FUNCTIONS //

// ERROR CHECKING //
void	print_param(t_game *game);
int		is_good_char(char* parse_line);
int		check_extention(char *path, char *ext, int len);
int		check_game(t_game *game);
int		free_used_lines(char *a, char *b);

// METH //

#endif
