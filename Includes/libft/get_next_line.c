/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:42:59 by ysebban           #+#    #+#             */
/*   Updated: 2022/12/08 19:11:50 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*my_strjoin(char *all, char *line_read)
{
	char	*dest;
	int		i;
	int		j;

	if (!line_read && !all)
		return (0);
	if (!all)
		dest = ft_calloc(sizeof(char), ft_strlen(line_read) + 1);
	else
		dest = ft_calloc(sizeof(char),
				ft_strlen(all) + ft_strlen(line_read) + 1);
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (all && all[i])
		dest[j++] = all[i++];
	i = 0;
	while (line_read[i])
		dest[j++] = line_read[i++];
	dest[j] = '\0';
	free (all);
	return (dest);
}

char	*get_till_end(int fd, char *all)
{
	int		i;
	char	*line;

	i = 1;
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (0);
	while (!ft_strchr(line, '\n') && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (0);
		}
		line [i] = '\0';
		all = my_strjoin(all, line);
	}
	free(line);
	return (all);
}

char	*get_leftover(char *all)
{
	char	*leftover;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(all);
	while (all[start] && all[start] != '\n')
		start ++;
	if (all[start] == '\n')
		start ++;
	if (end - start == 0)
	{
		free(all);
		return (NULL);
	}
	leftover = ft_calloc(sizeof(char), end - start + 1);
	if (!leftover)
		return (0);
	i = 0;
	while (all[start])
		leftover[i++] = all[start++];
	leftover[i] = '\0';
	free(all);
	return (leftover);
}

char	*trim_line(char *all)
{
	int		end;
	int		start;
	char	*line;

	end = 0;
	if (!all[end])
		return (0);
	while (all[end] && all[end] != '\n')
		end ++;
	if (all[end] == '\n')
		end ++;
	line = ft_calloc(end + 1, sizeof(char));
	if (!line)
		return (0);
	start = 0;
	while (start < end)
	{
		line[start] = all[start];
		start ++;
	}
	line[start] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*line_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all = get_till_end(fd, all);
	if (!all)
		return (0);
	line_read = trim_line(all);
	all = get_leftover(all);
	return (line_read);
}
