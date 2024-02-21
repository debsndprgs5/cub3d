/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::   	  */
/*   map_splitter.c									 :+:	  :+:	:+:	   */
/*													+:+ +:+		 +:+		  */
/*   By: zfavere <marvin@42.fr>					 +#+  +:+	   +#+			  */
/*												+#+#+#+#+#+   +#+			  */
/*   Created: 2024/02/08 19:18:50 by zfavere		   #+#	#+#				  */
/*   Updated: 2024/02/08 19:18:51 by zfavere		  ###   ########.fr		  */
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
		if (ft_strchr("01WNES \n", str[i]))
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
			break;
		i++;
	}
	return (i);
}

static int tabemptycheck(char ***tab)
{
	int	i;
	int	j;
	int	charcount;
	if (!(*tab) || !(*tab)[0])
		return (1);
	i = 0;
	charcount = 0;
	while ((*tab)[i])
	{
		j = 0;
		while ((*tab)[i][j])
		{
			if (!ft_strchr("\t\n ", (*tab)[i][j]))
				charcount++;
			j++;
		}
		i++;
	}
	if (!charcount)
		return (1);
	return (0);
}


const char *defaultconfig[] = 
{
	"NO ./Includes/default.xpm", //0
	"SO ./Includes/default.xpm", //1
	"WE ./Includes/default.xpm", //2
	"EA ./Includes/default.xpm", //3
	"F 220,100,0", //4
	"C 225,30,0" //5
};

int split_map(char **map, char ***part1, char ***part2)
{
	int lines_tot;
	int	splitline;
	int	i;
	int	j;

	i = 0;
	j = 0;
	lines_tot = 0;
	while (map[lines_tot])
		lines_tot++;
	splitline = findsplitpoint(map);
	printf("splitline = %d\n lines_tot = %d\n", splitline, lines_tot);
	if (!splitline)
	{
		printerror(INVALID_CONFIG);
		*part1 = (char **) defaultconfig;
		*part2 = malloc(sizeof(char *) * lines_tot + 1);
		while (i < lines_tot)
		{
			(*part2)[j] = ft_strdup(map[i]);
			i++;
			j++;
		}
		(*part2)[lines_tot - splitline] = NULL;
	}
	else if (splitline == lines_tot)
	{
		printerror(MAP_NOT_EXIST);
		return(0);
	}
	else
	{
		*part1 = malloc(sizeof(char *) * splitline + 1);
		*part2 = malloc(sizeof(char *) * lines_tot - splitline + 1);
		if (!*part1 || !*part2)
		{
			printerror(MEM_FAIL);
			return (0);
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
		if (tabemptycheck(part1))
		{
			*part1 = (char **) defaultconfig;
			printerror(INVALID_CONFIG);
		}
	}
	return (1);
}

