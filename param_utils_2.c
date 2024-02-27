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
	// int fd;

	// fd = open(path, O_DIRECTORY);
	// if (fd > 0)
	// {
	// 	close(fd);
	// 	return (0);
	// }
	// close(fd);
	i = ft_strlen(path);
	i --;
	while (ext[len] && len >= 0)
	{
		if (path[i] != ext[len])
		{
			return (0);
		}
		len --;
		i --;
	}
	return (1);
}



int	free_used_lines(char *a, char *b)
{
	free (a);
	free (b);
	return (0);
}

int	free_game(t_game *game)
{
	int i;

	i = 0;
	while(i <= 3)
		free(game->paths[i++]);
	free(game->paths);
	return (0);
}