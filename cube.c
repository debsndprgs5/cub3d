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
#include <signal.h>

void	init_game(t_game *game)
{
	mlx_mouse_hide(game->mlx_session, game->mlx_window);
	mlx_hook(game->mlx_window, 6, 1L << 6, check_cursor, game);
	toggle_mouse(game);
	lhookylhook(game);
	exit_game(game);
}

int	maincheck(char **path, t_game *game, char ***configfile, char ***parsedmap)
{
	char	**map;

	map = readmap(path[1]);
	if (map == NULL)
		return (printerror(FILE_NOT_EXIST));
	if (!split_map(map, configfile, parsedmap))
	{
		freetab(map);
		return (0);
	}
	freetab(map);
	get_format(parsedmap);
	game->map = *parsedmap;
	if (!(map_check(*parsedmap)))
	{
		freetab(game->map);
		freetab(*configfile);
		return (0);
	}
	if (!init_struct(game, *configfile))
		return (0);
	return (1);
}

int	main(int ac, char **path)
{
	char	**configfile;
	char	**parsedmap;
	t_game	game;

	if (ac == 2 && check_extention(path[1], ".cub", 3))
	{
		if (!maincheck(path, &game, &configfile, &parsedmap))
			return (1);
		init_game(&game);
	}
	else
		printerror(FILE_NOT_EXIST);
	return (0);
}

int	exit_game(t_game *game)
{
	freetab(game->map);
	if (game->is_current == false)
		mlx_destroy_image(game->mlx_session, game->current.mlx_img);
	else
		mlx_destroy_image(game->mlx_session, game->next.mlx_img);
	mlx_destroy_window(game->mlx_session, game->mlx_window);
	exit(0);
}

void	lhookylhook(t_game *game)
{
	raycasting_loop(game);
	mlx_hook(game->mlx_window, 2, (1L << 0), get_key, game);
	mlx_hook(game->mlx_window, 3, (1L << 1), release_key, game);
	mlx_hook(game->mlx_window, 17, 0L, exit_game, game);
	mlx_loop_hook(game->mlx_session, &loopframe, game);
	mlx_loop(game->mlx_session);
}
