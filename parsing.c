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


int init_first_game(t_game *game)
{
	int i;

	i = 0;
	game->paths = malloc(sizeof(char*) * 4);
	if(!game->paths)
		return (printerror(MEM_FAIL));
	while (i < 4)
	{
		game->paths[i] = NULL;
		i ++;
	}
	game->is_current = false;
	return (1);
}

static void ft_init_mlx(t_game *game)
{
	game->mlx_session = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_session, 960, 540, "Cub3D");
	game->current.mlx_img = mlx_new_image(game->mlx_session, WIDTH, LENGTH);
	game->next.mlx_img  = mlx_new_image(game->mlx_session, WIDTH, LENGTH);
}

void get_player_pos(int *x, int *y, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'W' ||
			game->map[i][j] == 'E' || game->map[i][j] == 'S' ||
			game->map[i][j] == 'N')
			{
				(*y) = i;
				(*x) = j;
				break;
			}
			j++;
		}
		i++;
	}
}

int init_struct(t_game *game, char **config_file)
{
	t_frames	frames;
	t_ppos		ppos;
	int width;
	int height;
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!init_first_game(game))
		return (0);
	if (!get_param(config_file, game))
		return (0);
	get_player_pos(&x, &y, game);
	game->ppos = ppos;
	game->ppos.x = (double) x - 0.5;
	game->ppos.y = (double) y - 0.5;
	game->ymax = 0;
	game->xmax = ft_strlen(game->map[0]);
	while (game->map[game->ymax])
		game->ymax++;
	game->ymax -= 1;
	// printf("-------------\nxm = %d\nym = %d\n-------------", game->xmax, game->ymax);
	ft_init_mlx(game);
	frames.w_no_img = mlx_xpm_file_to_image(game->mlx_session,
		game->paths[0], &width, &height);
	frames.w_so_img = mlx_xpm_file_to_image(game->mlx_session,
		game->paths[1], &width, &height);
	frames.w_ea_img = mlx_xpm_file_to_image(game->mlx_session,
		game->paths[2], &width, &height);
	frames.w_we_img = mlx_xpm_file_to_image(game->mlx_session,
		game->paths[3], &width, &height);
	game->frames = &frames;
	game->lookingdir = get_iniplayerdir(game);
	// printf("lookingdir = %d\n", game->lookingdir);
	return(1);
}
