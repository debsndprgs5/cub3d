/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:29:05 by ysebban           #+#    #+#             */
/*   Updated: 2024/02/15 17:36:03 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*removes_spaces(char *spc_line)
{
	char	*new_line;
	int		spc_count;
	int		i;
	int		j;

	i = 0;
	spc_count = 0;
	while (spc_line[i])
	{
		if (spc_line[i] == ' ' || '	')
			spc_count ++;
		i ++;
	}
	new_line = ft_calloc(sizeof (char) , (size_t)(i - spc_count+1));
	i = 0;
	j = 0;
	while (spc_line[i])
	{
		if (spc_line[i] != ' ' && spc_line[i] != '	')
			new_line[j ++] = spc_line[i ++];
		else
			i ++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*removes_first_spaces(char *str, int i)
{
	char	*new_str;
	int		j;

	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	if (i >= ft_strlen(str))
		return (NULL);
	new_str = ft_calloc(sizeof(char) , (size_t)(ft_strlen(str) - i));
	while (i <= ft_strlen(str))
		new_str[j ++] = str[i ++];
	if (new_str[j - 1] == '\n')
		new_str[j - 1] = '\0';
	else
		new_str[j--] = '\0';
	return (new_str);
}

char	*removes_last_stuff(char *old_str)
{
	char	*new_str;
	int		new_size;
	int		i;

	new_size = ft_strlen(old_str);
	if (new_size <= 1)
		return (ft_strdup(old_str));
	while (new_size >= 0)
	{
		if (ft_isprint(old_str[new_size]) && old_str[new_size] != '\n')
			break ;
		new_size --;
	}
	new_str = ft_calloc(sizeof(char) , (size_t)(new_size));
	new_size ++;
	i = 0;
	while (i <= new_size)
	{
		new_str[i] = old_str[i];
		i ++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	is_good_char(char *parse_line)
{
	if (parse_line[0] != '\n' && parse_line [0] != 'C'
		&& parse_line[0] != 'F' && ft_strncmp(parse_line, "WE", 2)
		&& ft_strncmp(parse_line, "EA", 2)
		&& ft_strncmp(parse_line, "SO", 2)
		&& ft_strncmp(parse_line, "NO", 2)
		&& ft_isprint(parse_line[0]))
	{
		free(parse_line);
		return (0);
	}
	return (1);
}

int	check_game(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (game->paths[i] == NULL)
			return (0);
		i ++;
	}
	if (game->ground_check == false || !game->sky_check == false)
		return (0);
	return (1);
}
