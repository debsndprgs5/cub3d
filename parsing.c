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

int	init_first_game(t_game *game)
{
	int	i;

	i = 0;
	game->paths = malloc(sizeof(char *) * 4);
	if (!game->paths)
		return (printerror(MEM_FAIL));
	while (i < 4)
	{
		game->paths[i] = NULL;
		i ++;
	}
	game->is_current = false;
	game->ground_check = false;
	game->sky_check = false;
	return (1);
}

static void	ft_init_mlx(t_game *game)
{
	game->mlx_session = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_session,
			WIDTH, HEIGHT, "Cub3D");
	game->next.mlx_img = mlx_new_image(game->mlx_session, WIDTH, HEIGHT);
}

void	init_struct_utils(t_game *game, int x, int y, t_ppos *ppos)
{
	game->ppos = *ppos;
	game->ppos.x = x + 0.5;
	game->ppos.y = y + 0.5;
	game->ymax = 0;
	game->xmax = ft_strlen(game->map[0]);
	while (game->map[game->ymax])
		game->ymax++;
	game->ymax -= 1;
	game->lookingdir = get_iniplayerdir(game);
}

int	init_struct(t_game *game, char **config_file)
{
	int			x;
	int			y;
	t_ppos		ppos;

	x = 0;
	y = 0;
	if (!init_first_game(game))
		return (0);
	if (!get_param(config_file, game))
	{
		free_paths(game->paths);
		freetab(game->map);
		freetab(config_file);
		return (0);
	}
	get_player_pos(&x, &y, game);
	init_struct_utils(game, x, y, &ppos);
	ft_init_mlx(game);
	if (!init_asset(game))
	{
		exit_game(game);
		return (0);
	}
	return (1);
}

double	get_iniplayerdir(t_game *game)
{
	if (game->map[(int) floor(game->ppos.y)][(int) floor(game->ppos.x)] == 'W')
		return (180);
	if (game->map[(int) floor(game->ppos.y)][(int) floor(game->ppos.x)] == 'E')
		return (0);
	if (game->map[(int) floor(game->ppos.y)][(int) floor(game->ppos.x)] == 'S')
		return (90);
	if (game->map[(int) floor(game->ppos.y)][(int) floor(game->ppos.x)] == 'N')
		return (270);
	return (printerror(MATH_ERROR));
}
