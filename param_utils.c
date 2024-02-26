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
	return (new_line);
}

int	get_next_print(char *str, int start)
{
	int	next_start;

	next_start = start;
	while(str[next_start])
	{
		if (ft_isprint(str[next_start]) && str[next_start] != ' ')
			return (next_start);
		next_start ++;
	}
	return(next_start);
}

int	get_last_print(char *str)
{
	int	end;

	end = ft_strlen(str);
	while(end >= 0)
	{
		if (ft_isprint(str[end]) && str[end] != ' ')
			return (end);
		end --;
	}
	return (end);
}

char	*clean_first_spaces(char *str, int i)
{
	char	*new_str;
	int		new_start;
	int		new_end;
	int		j;

	new_start = get_next_print(str, i);
	if(new_start >= ft_strlen(str))
		return (NULL);
	new_end = get_last_print(str);
	if (new_end <= 0)
		return (NULL);
	new_str = ft_calloc(sizeof(char), (size_t)(new_end - new_start + 1));
	j = 0;
	while( new_start <= new_end)
	{
		new_str[j] = str[new_start];
		j ++;
		new_start ++;
	}
	new_str[j] = '\0';
	return (new_str);
}


int	is_good_char(char *parse_line)
{
	if (parse_line == NULL)
		return (1);
	if (parse_line[0] != '\n' &&  parse_line[0] != '\0' && parse_line [0] != 'C'
		&& parse_line[0] != 'F' && ft_strncmp(parse_line, "WE", 2)
		&& ft_strncmp(parse_line, "EA", 2)
		&& ft_strncmp(parse_line, "SO", 2)
		&& ft_strncmp(parse_line, "NO", 2))
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
	if (!game->ground_check || !game->sky_check)
		return (0);
	return (1);
}
