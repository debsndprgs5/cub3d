/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:17:01 by ysebban           #+#    #+#             */
/*   Updated: 2024/02/21 15:17:11 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_extention(char *path, char *ext, int len)
{
	int	i;
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
		return (0);
	i = ft_strlen(path);
	i --;
	while (ext[len] && len >= 0)
	{
		if (path[i] != ext[len])
			return (0);
		len --;
		i --;
	}
	return (1);
}



int	free_used_lines(char *a, char *b)
{
	if (a)
		free(a);
	if(b)
		free(b);
	return (0);
}

void get_dflt_setting(t_game *game)
{
	int	i;

	i = 0;
	while(i <= 3)
	{
		if(game->paths[i] == NULL)
			game->paths[i] = "./Includes/default.xpm";
		i ++;
	}
	if (!game->sky_check)
	{	
		game->skycol[0] = 0;
		game->skycol[1] = 0;
		game->skycol[2] = 0;
	}
	if (!game->ground_check)
	{
		game->groundcol[0] = 255;
		game->groundcol[1] = 255;
		game->groundcol[2] = 255;
	}
	printerror(MISSING_ARGS);
}