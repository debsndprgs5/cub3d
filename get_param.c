/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zfavere <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/08 18:37:22 by zfavere		   #+#	#+#			 */
/*   Updated: 2024/02/08 18:37:27 by zfavere		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cube.h"

int	check_asset_one(char *parse_line, t_game *game)
{
	char	*unspace_line;

	if (!ft_strncmp(parse_line, "NO", 2))
	{
		unspace_line = removes_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths,0))
		{
			free (unspace_line);
			free (parse_line);
			return (0);
		}
		free(unspace_line);
	}
	if (!ft_strncmp(parse_line, "SO", 2))
	{
		unspace_line = removes_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths,1))
		{
			free (unspace_line);
			free (parse_line);
			return (0);
		}
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
		{
			free (unspace_line);
			free (parse_line);
			return (0);
		}
		free(unspace_line);
	}
	if (!ft_strncmp(parse_line, "WE", 2))
	{
		unspace_line = removes_first_spaces(parse_line, 2);
		if (!get_dir_path(unspace_line, game->paths, 3))
		{
			free (unspace_line);
			free (parse_line);
			return (0);
		}
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
		{
			free (unspace_line);
			free (parse_line);
			return(0);
		}
		free(unspace_line);
	}
	if (parse_line [0] == 'C')
	{
		unspace_line = removes_spaces(parse_line);
		if (!get_color(unspace_line, game->skycol))
		{
			free (unspace_line);
			free (parse_line);
			return(0);
		}
		free (unspace_line);
	}
	return (1);
}

int get_dir_path(char *path, char **stack, int index)
{
	
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printerror(index + 3));
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
		parse_line = removes_first_spaces(config_file[i], 0);
		parse_line = removes_last_stuff(parse_line);
		if(!check_asset_one(parse_line, game))
			return (0);
		else if(!check_asset_two(parse_line, game))
			return (0);
		else if (!check_asset_three(parse_line, game))
			return (0);
		else if (!is_good_char(parse_line))
		{
			free(parse_line);
			return (printerror(ARGS_UNDEFINED));
		}
		if (parse_line)
			free(parse_line);
		i++;
	}
	print_param(game);
	return (1);
}
