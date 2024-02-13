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


void free_split(char **split)
{
	int	i;

	i = 0;
	while(split[i])
		free(split[i++]);
}


char *removes_spaces(char *spc_line)
{
	char	*new_line;
	int		spc_count;
	int		i;
	int		j;

	i = 0;
	spc_count = 0;
	while(spc_line[i])
	{
		if(spc_line[i] == ' ' || '	')
			spc_count ++;
		i ++;
	}
	new_line = malloc(sizeof(char)* (i - spc_count) +1);
	i = 0;
	j = 0;
	while(spc_line[i])
	{
		if (spc_line[i] != ' ' && spc_line[i] != '	')
			new_line[j++] = spc_line[i++];
		else
			i++;
	}
	return(new_line);
}

int get_til_next_coma(char *parse_line, int start)
{
	int	res;

	res = start;
	while (parse_line[res])
	{
		if (parse_line[res] == ',')
			return (res+1);
		res ++;
	}
	return (ft_strlen(parse_line));

}

char	*cut_till_next_coma(char *parse_line, int start)
{
	char	*new_str;
	int		next_stop;
	int		i;

	i = 0;
	next_stop = get_til_next_coma(parse_line, start);
	if (next_stop == 0 || next_stop == 1)
		return (NULL);
	new_str = malloc(sizeof(char)* (next_stop - start)+1);
	while(start <= next_stop)
	{
		new_str[i]= parse_line[start];
		i++;
		start ++;
	}
	return (new_str);
}

int	check_color_line(char *parse_line)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while(parse_line[i])
	{
		if((parse_line[i] < '0' || parse_line[i] > '9') 
			&& parse_line[i] != ',' && parse_line[i] != '\n')
					return (1);
		if(parse_line[i] == ',')
			check ++;
		i ++;
	}
	if (check != 2)
		return(1);
	return (0);
}

int	get_color(char *parse_line, int *stack)
{
	int i;
	int	j;
	char	*str_to_int;
	int		temp;
	
	i = 1;
	j = 0;
	if(check_color_line(parse_line))
	{
			error_color_parsing(2);
			return(0) ;
	}
	while(parse_line[i])
	{
		str_to_int = cut_till_next_coma(parse_line, i);
		i = get_til_next_coma(parse_line, i);
		temp = ft_atoi(str_to_int);
		
		if (str_to_int == NULL || temp < 0 || temp > 255)
		{
			free(str_to_int);
			error_color_parsing(2);
			return(0);
		}
		stack[j] = temp;
		printf(" TEMP : %d\n", stack[j]);
		free(str_to_int);
		j++;
	}
	return (1);
}


int get_param(char **config_file, t_game *game)
{
	int	i;
	char *parse_line;

	i = 0;
	while(config_file[i])
	{
		parse_line = removes_spaces(config_file[i]);
		//if (ft_strncmp(parse_line), "NO", 3)
		// (ft_strncmp(parse_line[0]), "SO", 3)
		// (ft_strncmp(parse_line[0]), "EA", 3)
	//	(ft_strncmp(parse_line[0]), "WE", 3)

		if (parse_line[0] == 'F')
		{
			if(!get_color(parse_line, game->groundcol))
			{
				free(parse_line);
				return(0);
			}
		}
		if (parse_line [0] == 'C')
		{
			if (!get_color(parse_line, game->skycol))
			{
				free(parse_line);
				return(0);
			}
		}
		//else 
		//	error_parse_line(1);
		free(parse_line);
		i++;
	}
	print_param(game);
	return (1);
}

void	print_param(t_game *game)
{
	int i;
	i = 0;
	while(i <= 2)
	{
		printf("SKY COL : %d\n", game->skycol[i]);
		i ++;
	}
	i = 0;
	while(i <= 2)
	{
		printf("GROUND COL : %d\n", game->groundcol[i]);
		i ++;
	}
	
}
