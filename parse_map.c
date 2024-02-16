/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:18:51 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/13 18:18:52 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int mini_check(char c)
{
	if (ft_strchr("SNEW01", c))
		return (1);
	else
		return (0);
}


static int multi_check(int x, int y, char **map)
{
	int	maxcol;
	int	maxrow;

	maxcol = 0;
	maxrow = ft_strlen(map[y]);
	while (map[maxcol])
		maxcol++;
	maxcol -= 2;
	if (y >= maxcol || y == 0 || x >= maxrow || x == 0)
	{
		printf("ERROR on map cell %d;%d\n", x, y);
		return  (0);
	}
	if ((!mini_check(map[y][x+1])) ||
		(!mini_check(map[y][x-1])) ||
		(!mini_check(map[y+1][x])) ||
		(!mini_check(map[y-1][x])) ||
		(map[y][x+1] == ' ' || map[y][x-1] == ' ' ||
			map[y+1][x] == ' ' || map[y-1][x] == ' '))
	{
		printf("ERROR on map cell %d;%d\n", x, y);
		return (0);
	}
	return (1);
}

static int enclosed_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'W' ||
				map[i][j] == 'E' || map[i][j] == 'S' ||
				map[i][j] == 'N')
			{
				if (!multi_check(j, i, map))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int letter_check(char **map)
{
	int	i;
	int	j;
	int	lettercount;

	i = 0;
	lettercount = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E' ||
				map[i][j] == 'S' || map[i][j] == 'N')
				lettercount++;
			j++;
		}
		i++;
	}
	if (lettercount != 1)
		return (0);
	return (1);
}

int map_check(char **map)
{
	if (!(letter_check(map)))
		return (1);
	if (!(enclosed_check(map)))
		return (2);
	return(0);
}