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

int	check_asset_one(char *parse_line, t_game *game)
{
	char	*unspace_line;

	if (!ft_strncmp(parse_line, "NO", 2))
	{
		unspace_line = removes_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 0))
			return (free_used_lines(unspace_line, parse_line));
		free(unspace_line);
	}
	if (!ft_strncmp(parse_line, "SO", 2))
	{
		unspace_line = removes_first_spaces(parse_line, 2);
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
		unspace_line = removes_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 2))
			return (free_used_lines(unspace_line, parse_line));
		free(unspace_line);
	}
	if (!ft_strncmp(parse_line, "WE", 2))
	{
		unspace_line = removes_first_spaces(parse_line, 2);
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
		game->ground_check += 1;
		free(unspace_line);
	}
	if (parse_line [0] == 'C')
	{
		unspace_line = removes_spaces(parse_line);
		if (!get_color(unspace_line, game->skycol))
			return (free_used_lines(unspace_line, parse_line));
		game->sky_check += 1;
		free (unspace_line);
	}
	return (1);
}

int	get_dir_path(char *path, char **stack, int index)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || path == NULL)
		return (0);
	if (!check_extention(path, ".xpm", 4))
	{
		printf("ERROR with texture path\n");
		return (0);
	}
	else if (stack[index] != NULL)
	{
		printf("ERROR DUPLICATES PATH\n");
		return (0);
	}
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
		parse_line = parse_config_line(config_file[i]);
		if (!check_asset_one(parse_line, game))
			return (0);
		else if (!check_asset_two(parse_line, game))
			return (0);
		else if (!check_asset_three(parse_line, game))
			return (0);
		else if (!is_good_char(parse_line))
			return (error_parse_line(1));
		free(parse_line);
		i ++;
	}
	if (!check_game(game))
	{
		printf("MISSING CONFIG ARG\n");
		return (0);
	}
	print_param(game);
	return (1);
}
