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
		mlx_mouse_hide(game.mlx_session, game.mlx_window);
		mlx_hook(game.mlx_window, 6, 1L<<6, check_cursor, &game);
		toggle_mouse(&game);
		lhookylhook(&game);
		exit_game(&game);
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

int	exit_game(t_game *game)
{
	freetab(game->map);
	mlx_destroy_window(game->mlx_session, game->mlx_window);
	exit(0);
}

int	loopframe(t_game *game)
{
	if (game->keypress.key_forward == TRUE)
		player_move(UP_KEY, game);
	if (game->keypress.key_back == TRUE)
		player_move(DOWN_KEY, game);
	if (game->keypress.key_left == TRUE)
		player_move(LEFT_KEY, game);
	if (game->keypress.key_right == TRUE)
		player_move(RIGHT_KEY, game);
	if (game->keypress.look_left == TRUE)
		player_look(LOOK_LEFT, game);
	if (game->keypress.look_right == TRUE)
		player_look(LOOK_RIGHT, game);
	return (0);
}

void	lhookylhook(t_game *game)
{
	render_game(game);
	mlx_hook(game->mlx_window, 2, (1L << 0), get_key, game);
	mlx_hook(game->mlx_window, 3, (1L << 1), release_key, game);
	mlx_hook(game->mlx_window, 17, 0L, exit_game, game);
	mlx_loop_hook(game->mlx_session, &loopframe, game);
	mlx_loop(game->mlx_session);
}
