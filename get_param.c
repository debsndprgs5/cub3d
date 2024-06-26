/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/08 18:37:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_asset_one(char *parse_line, t_game *game)
{
	char	*unspace_line;

	if (!ft_strncmp(parse_line, "NO", 2))
	{
		unspace_line = clean_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 0))
			return (free_used_lines(unspace_line, parse_line));
		free(unspace_line);
	}
	if (!ft_strncmp(parse_line, "SO", 2))
	{
		unspace_line = clean_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 1))
			return (free_used_lines(unspace_line, parse_line));
		free(unspace_line);
	}
	return (1);
}

int	check_asset_two(char *parse_line, t_game *game)
{
	char	*unspace_line;

	if (!ft_strncmp(parse_line, "EA", 2))
	{
		unspace_line = clean_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 2))
			return (free_used_lines(unspace_line, parse_line));
		free(unspace_line);
	}
	if (!ft_strncmp(parse_line, "WE", 2))
	{
		unspace_line = clean_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 3))
			return (free_used_lines(unspace_line, parse_line));
		free (unspace_line);
	}
	return (1);
}

int	check_asset_three(char *parse_line, t_game *game)
{
	char	*unspace_line;

	if (parse_line[0] == 'F')
	{
		unspace_line = removes_spaces(parse_line);
		if (!get_color(unspace_line, game->groundcol))
			return (free_used_lines(unspace_line, parse_line));
		game->ground_check = true;
		free(unspace_line);
	}
	if (parse_line [0] == 'C')
	{
		unspace_line = removes_spaces(parse_line);
		if (!get_color(unspace_line, game->skycol))
			return (free_used_lines(unspace_line, parse_line));
		game->sky_check = true;
		free (unspace_line);
	}
	return (1);
}

int	get_dir_path(char *path, char **stack, int index)
{
	int	fd;

	if (!path)
		return (printerror(MISSING_ARGS));
	if (!check_extention(path, ".xpm", 3))
		return (printerror(WRONG_EXTENT));
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (printerror(index + 3));
	}
	else if (stack[index] != NULL)
		return (printerror(DUP_ARGS));
	stack[index] = ft_strdup(path);
	close(fd);
	return (1);
}

int	get_param(char **config_file, t_game *game)
{
	int		i;
	char	*parse_line;

	i = 0;
	while (config_file[i])
	{
		parse_line = clean_first_spaces(config_file[i], 0);
		if (!param_loop(parse_line, &i, game))
			return (0);
		i++;
	}
	if (!check_game(game))
		return (printerror(MISSING_ARGS));
	return (1);
}
