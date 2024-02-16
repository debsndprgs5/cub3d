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
	game->paths = malloc(sizeof(char*) * 4);
	if(!game->paths)
	{
		ft_printf("FATAL CANNOT ALLOCATE MEMORY\n");
		return (0);
	}
	return (1);
}

static void ft_init_mlx(t_game *game)
{
	game->mlx_session = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_session, 1920, 1080, "Cub3D");
}


int init_struct(t_game *game, char **config_file)
{
	// t_frames	frames;
	// int width;
	// int height;
	if (!init_first_game(game))
		return (0);
	if (!get_param(config_file, game))
		return (0);
	ft_init_mlx(game);
	// frames.w_no_img = mlx_xpm_file_to_image(game->mlx_session,
	// 	game->paths[0], &width, &height);
	// frames.w_so_img = mlx_xpm_file_to_image(game->mlx_session,
	// 	game->paths[1], &width, &height);
	// frames.w_ea_img = mlx_xpm_file_to_image(game->mlx_session,
	// 	game->paths[2], &width, &height);
	// frames.w_we_img = mlx_xpm_file_to_image(game->mlx_session,
	// 	game->paths[3], &width, &height);
	// game->frames = &frames;
	return(1);
}
