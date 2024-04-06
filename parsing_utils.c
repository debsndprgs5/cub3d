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

int	check_parse_line(char *str)
{
	if (str[0] == 'N' || str[0] == 'E' || str[0] == 'W' || str[0] == 'S')
	{
		if (str[2] != ' ' && str[2] != '\t')
			return (0);
		else
			return (1);
	}
	else if (str[0] == 'C' || str[0] == 'F')
	{
		if (str[1] != ' ' && str[0] != '\t')
			return (0);
		else
			return (1);
	}
	return (1);
}

int	param_loop(char *parse_line, int *i, t_game *game)
{
	if (!parse_line)
		i ++;
	else if (!is_good_char(parse_line) || !check_parse_line(parse_line))
	{
		free(parse_line);
		return (printerror(ARGS_UNDEFINED));
	}
	else if (!check_asset_one(parse_line, game))
		return (0);
	else if (!check_asset_two(parse_line, game))
		return (0);
	else if (!check_asset_three(parse_line, game))
		return (0);
	free(parse_line);
	return (1);
}
