/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:11:09 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/18 16:11:13 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	get_biggest_line(char ***parsedmap)
{
	int	temp;
	int	temp2;
	int	i;

	i = 0;
	temp = 0;
	temp2 = 0;
	while ((*parsedmap)[i])
	{
		temp2 = ft_strlen((*parsedmap)[i]);
		if (temp2 > temp)
			temp = temp2;
		i++;
	}
	return (temp);
}

void	get_format(char ***parsedmap)
{
	int		format;
	char	*tempstr;
	int		temp;
	int		i;
	int		j;

	i = 0;
	format = get_biggest_line(parsedmap);
	while ((*parsedmap)[i])
	{
		temp = ft_strlen((*parsedmap)[i]);
		tempstr = ft_strdup((*parsedmap)[i]);
		free((*parsedmap)[i]);
		(*parsedmap)[i] = malloc(format + 1);
		ft_strcpy((*parsedmap)[i], tempstr);
		free(tempstr);
		j = temp;
		while (j < format)
		{
			(*parsedmap)[i][j] = ' ';
			j++;
		}
		(*parsedmap)[i][j] = '\0';
		i++;
	}
}

void	get_player_pos(int *x, int *y, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'W' ||
			game->map[i][j] == 'E' || game->map[i][j] == 'S' ||
			game->map[i][j] == 'N')
			{
				(*y) = i;
				(*x) = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
