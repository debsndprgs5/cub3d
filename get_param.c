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

#include "cube.h"

int		get_param(char **config_file, t_game game)
{
	int	i;
	char **parse_line;

	i = 0;
	while(config_file[i])
	{
		parse_line =  ft_split(confilg_file[i], ' ');
		if (ft_strncmp(parse_line[0]), "NO", 3)
		if (ft_strncmp(parse_line[0]), "SO", 3)
		if (ft_strncmp(parse_line[0]), "EA", 3)
		if (ft_strncmp(parse_line[0]), "WE", 3)
		if (ft_strncmp(parse_line[0]), "F", 2)
			game->groundcol = get_color(parse_line);
		if (ft_strncmp(parse_line[0]), "C", 2)
			game->skycol = get_color(parse_line);
		else 
			error_parse_line(1);
		free(parse_line);
		i++;
	}
}

int *get_color(char **line)
{
	int i;
	int res[4];

	i = 1;
	if (check_split_col(line) != 0)
		error_color_parsing(check_split_col(line));
	while(line[i])
	{
		number = ft_atoi(line[i]);
		if (line[i][0] == ',' && (ft_strlen(line[i]) == 1))
			i ++;
		if (number >= 0 && number <= 255)
		{	
			res[i] = number;
			i++;
		}
		else
			error_color_parsing(1);
	}
	free (split);
	return (res);
	return (res);
}

int	check_split_col(char **split)
{
	int i;
	int check;

	i = 1;
	check = 0;
	while (split[i])
	{
		if (is_good_num(split[i]) == 0)
			check ++;
		else if(is_good_num(split[i] == 2))
			return (1);
		i ++;
	}
	if (check > 2)
		return (2);
	return (0)
}

int is_good_num(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == ',' && (ft_strlen(str) == 1))
			return (1);
		if(str[i] >= '0' && str[i] <= '9')
			i ++;
		else
			return(2);
	}
	if (i > 4)
		return (2);
	return (0);
}
