/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::   	  */
/*   map_splitter.c									 :+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: zfavere <marvin@42.fr>					 +#+  +:+	   +#+		      */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2024/02/08 19:18:50 by zfavere		   #+#	#+#			      */
/*   Updated: 2024/02/08 19:18:51 by zfavere		  ###   ########.fr	      */
/*																			  */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int notempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
			return (1);
		else
			i++;
	}
	return(0);
}

static int is_map(char *str)
{
	int	i;

	i = 0;
	if (!notempty(str))
		return(0);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'W' || str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == ' ' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}


static int findsplitpoint(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_map(map[i]))
			return (i);
		i++;
	}
	return (0);
}


void split_map(char **map, char ***part1, char ***part2)
{
	int lines_tot;
	int	splitline;
	int	i;
	int	j;

	lines_tot = 0;
	while (map[lines_tot])
		lines_tot++;
	printf("lines = %d\n", lines_tot);
	splitline = findsplitpoint(map);
	if (!splitline)
	{
		printf("ERROR - Invalid Map\n");
		return;
	}
	*part1 = malloc(sizeof(char *) * splitline + 1);
	*part2 = malloc(sizeof(char *) * lines_tot - splitline + 1);
	if (!*part1 || !*part2)
	{
		printf("ERROR - Memory allocation error\n");
		return;
	}
	i = -1;
	while (++i < splitline)
		(*part1)[i] = ft_strdup(map[i]);
    (*part1)[splitline] = NULL;
	j = 0;
	while (i < lines_tot)
	{
		(*part2)[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
    (*part2)[lines_tot - splitline] = NULL;
}

