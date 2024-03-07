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
	t_game	game;

	if (ac == 2 && check_extention(path[1], ".cub", 3))
	{
		map = readmap(path[1]);
		if (map == NULL)
		{
			printerror(FILE_NOT_EXIST);
			return(1);
		}
		if (!split_map(map, &configfile, &parsedmap))
			return (1);
		freetab(map);
		get_format(&parsedmap);
		game.map = parsedmap;
		if (!init_struct(&game, configfile))
		{
			//free_game(&game);
			return (1);
		}
		//free_game(&game);
		if (!(map_check(parsedmap)))
			return (1);
		render_game(&game);
		mlx_loop(game.mlx_session);
		// for (int i = 0; parsedmap[i]; i++)
		// 	printf("sz = %d  | %s", ft_strlen(parsedmap[i]), parsedmap[i]);
		//renderft();
		// freetab(configfile);
		// terminate(configfile, parsedmap);
	}
	else
		printerror(FILE_NOT_EXIST);
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