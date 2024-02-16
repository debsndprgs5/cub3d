/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:17:54 by ysebban           #+#    #+#             */
/*   Updated: 2024/02/15 17:17:59 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_til_next_coma(char *parse_line, int start)
{
	int	res;

	res = start;
	while (parse_line[res])
	{
		if (parse_line[res] == ',')
			return (res + 1);
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
	new_str = malloc(sizeof (char) * (next_stop - start) + 1);
	while (start <= next_stop)
		new_str[i++] = parse_line[start++];
	return (new_str);
}


int	check_color_line(char *parse_line)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (parse_line[i])
	{
		if ((parse_line[i] < '0' || parse_line[i] > '9')
			&& parse_line[i] != ',' && parse_line[i] != '\n')
			return (1);
		if (parse_line[i] == ',')
			check ++;
		i ++;
	}
	if (check != 2)
		return (1);
	return (0);
}


int	get_color(char *parse_line, int *stack)
{
	int		i;
	int		j;
	char	*str_to_int;
	int		temp;

	i = 1;
	j = 0;
	if (check_color_line(parse_line))
		return (printerror(RGB_ARGS));
	while (parse_line[i])
	{
		str_to_int = cut_till_next_coma(parse_line, i);
		i = get_til_next_coma(parse_line, i);
		temp = ft_atoi(str_to_int);
		if (str_to_int == NULL || temp < 0 || temp > 255)
		{
			free(str_to_int);
			return (printerror(RGB_RANGE));
		}
		stack[j] = temp;
		free(str_to_int);
		j++;
	}
	return (1);
}
