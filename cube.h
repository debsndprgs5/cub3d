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

# include "./Includes/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
#include <mlx.h>

// Walls/Ground raw images

typedef struct s_frames
{
	void **w_no_img;
	void **w_so_img;
	void **w_ea_img;
	void **w_we_img;
}	t_frames;

// Main struct
// Paths are N->0 S->1 E->2 W->3 in this order
typedef struct s_game
{
	t_frames	*frames;
	char		**paths;
	void		*mlx_session;
	void		*mlx_window;
	int			groundcol[4];
	int			skycol[4];
	double		ppos;
}	t_game;


// PARSING FUNCTIONS //

char	**readmap(char *pathtofile);
void	freetab(char **str);
void	get_param(char **config_file,  t_game game);
void	split_map(char** map, char*** part1, char*** part2);
void 	get_color(char **line, int *res);
int		check_split_col(char **split);
void	init_struct(t_game *game);

// RENDERING FUNCTIONS //

// ERROR CHECKING //
void	error_color_parsing(int ref);
void	error_parse_line(int ref);
// METH //

#endif
