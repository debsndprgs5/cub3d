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
# include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>

// Walls/Ground raw images

typedef struct s_frames
{
	void **w_no_img;
	void **w_so_img;
	void **w_ea_img;
	void **w_we_img;
}	t_frames;

// Main struct

typedef struct s_game
{
	t_frames *frames;
	int groundcol[4];
	int skycol[4];
	double ppos;
}	t_game;


// PARSING FUNCTIONS //

char	**readmap(char *pathtofile);
void	freetab(char **str);
void	split_map(char** map, char*** part1, char*** part2);

// RENDERING FUNCTIONS //

// ERROR CHECKING //

// METH //

#endif
