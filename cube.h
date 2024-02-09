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

// Main struct

typedef struct s_game
{
	t_frames *frames;
	int groundcol[4];
	int skycol[4];
	double float ppos;
}	t_game;

// Walls/Ground raw images

typedef struct s_frames
{
	void **w_no_img;
	void **w_so_img;
	void **w_ea_img;
	void **w_we_img;
}	t_frames;


// PARSING FUNCTIONS //

char	**readmap(char *pathtofile);
void	freetab(char **str);
int		get_param(char **config_file, t_game game);


// RENDERING FUNCTIONS //

// ERROR CHECKING //
void	error_color_parsing(int ref);
void	error_parse_line(int ref);
// METH //

#endif
