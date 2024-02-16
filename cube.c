/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/08 18:37:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **path)
{
	char	**map;
	char	**configfile;
	char	**parsedmap;
	int		err;
	t_game	game;

	if (ac > 1)
	{
		map = readmap(path[1]);
		split_map(map, &configfile, &parsedmap);
		freetab(map);
		get_format(&parsedmap);
		game.map = parsedmap;
		err = map_check(parsedmap);
		if (err != 0)
		{
			printerror();
			return (1);
		}
		if (!init_struct(&game, configfile))
		{
			ft_printf("- ERROR -\nInvalid Config\n");
			//free game
			return (1);
		}
		// for (int i = 0; parsedmap[i]; i++)
		// 	printf("sz = %d  | %s", ft_strlen(parsedmap[i]), parsedmap[i]);
		//renderft();
		freetab(configfile);
		freetab(parsedmap);
	}
	return(0);
}




// To clean / move out


static int get_biggest_line(char ***parsedmap)
{
	int	temp;
	int	temp2;
	int	i;

	i = 0;
	temp = 0;
	temp2 = 0;
	while ((*parsedmap)[i])
	{
		temp2 = ft_strlen((*parsedmap)[i]);
		if (temp2 > temp)
			temp = temp2;
		i++;
	}
	return(temp);
}

void get_format(char ***parsedmap)
{
	int		format;
	char	*tempstr;
	int		temp;
	int		i;
	int		j;

	i = 0;
	format = get_biggest_line(parsedmap);
	while ((*parsedmap)[i])
	{
		temp = ft_strlen((*parsedmap)[i]);
		tempstr = ft_strdup((*parsedmap)[i]);
		free((*parsedmap)[i]);
		(*parsedmap)[i] = malloc(format + 1);
		ft_strcpy((*parsedmap)[i], tempstr);
		j = temp;
		while (j < format)
		{
			(*parsedmap)[i][j] = ' ';
			j++;
		}
		(*parsedmap)[i][j] = '\0';
		i++;
	}
}