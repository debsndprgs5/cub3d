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

int	linecount(char *pathtofile)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(pathtofile, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

static char	**allocdata(char *pathtofile)
{
	char	**map;
	int		line_count;

	line_count = linecount(pathtofile);
	if (line_count <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
	{
		printerror(MEM_FAIL);
		freetab(map);
		return (NULL);
	}
	return (map);
}

char	**readmap(char *pathtofile)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;

	map = allocdata(pathtofile);
	if (map == NULL)
		return (NULL);
	fd = open(pathtofile, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
