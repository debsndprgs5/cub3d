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


int	get_spaces_count(char *spc_line)
{
	int		i;
	int		spc_count;

	i = 0;
	spc_count = 0;
	if(! spc_line)
		return (spc_count);
	while (spc_line[i])
	{
		if (spc_line[i] == ' ')
			spc_count ++;
		i ++;
	}
	return (spc_count);
}


char	*removes_spaces(char *spc_line)
{
	char	*new_line;
	int		spc_count;
	int		i;
	int		j;

	spc_count  = get_spaces_count(spc_line);
	new_line = ft_calloc(sizeof(char), 
		(ft_strlen(spc_line) - spc_count +2));
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

	if (!str)
		return (NULL);
	new_start = get_next_print(str, i);
	if(new_start >= ft_strlen(str))
		return (NULL);
	new_end = get_last_print(str);
	new_str = ft_calloc(sizeof(char), (size_t)(new_end - new_start+2));
	if (!new_str)
		return(NULL);
	j = 0;
	while( new_start <= new_end)
		new_str[j++] = str[new_start++];
	new_str[j] = '\0';
	return (new_str);
}
