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
	new_line = malloc(sizeof (char) * (i - spc_count) + 1);
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

char	*removes_first_spaces(char *str, int i)
{
	char	*new_str;
	int		j;

	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != ' ')
			break ;
		i ++;
	}
	if (i >= ft_strlen(str))
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	while (i <= ft_strlen(str))
		new_str[j ++] = str[i ++];
	if (new_str[j - 1] == '\n')
		new_str[j - 1] = '\0';
	else
		new_str[j] = '\0';
	return (new_str);
}

char	*removes_last_stuff(char *old_str)
{
	char	*new_str;
	int		new_size;
	int		i;

	new_size = ft_strlen(old_str);
	if (new_size <= 1)
	{
		new_str = ft_strdup(old_str);
		return (new_str);
	}
	while (new_size >= 0)
	{
		if (old_str[new_size] != ' ' && ft_isprint(old_str[new_size]))
			break ;
		new_size --;
	}
	new_size ++;
	new_str = malloc(sizeof(char) * new_size +1);
	i = -1;
	while (++i!= new_size)
		new_str[i] = old_str[i];
	new_str[i] = '\0';
	return (new_str);
}

int	is_good_char(char* parse_line)
{
	if(parse_line[0] != '\n' && 
	parse_line [0] != 'C'&&
	parse_line[0] != 'F' &&
	ft_strncmp(parse_line, "WE", 2)
	&& ft_strncmp(parse_line, "EA", 2)
	&& ft_strncmp(parse_line, "SO", 2)
	&& ft_strncmp(parse_line, "NO", 2))
		return(0);
	return (1);
}
