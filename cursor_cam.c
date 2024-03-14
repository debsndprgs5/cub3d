/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:24 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/14 17:15:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


// void	toogle_mouse(t_game *game)
// {
// 	if (game->mouse_active)
// 	{
// 		// mlx_mouse_show(game->mlx_session, game->mlx_window);
// 	printf("check cursor case 1----------------------------------------------------\n");
// 		game->mouse_active = 0;
// 	}
// 	else
// 	{
// 	printf("check cursor case 2----------------------------------------------------\n");
// 		// mlx_mouse_hide(game->mlx_session, game->mlx_window);
// 		game->mouse_active = 1;
// 	}
// }



void put_cursor_middle(t_game *game)
{
	mlx_mouse_move(game->mlx_session, game->mlx_window, WIDTH/2, HEIGHT/2);
}

int check_cursor(int x, int y, t_game *game)
{
	printf("check cursor ----------------------------------------------------\n");
	(void)y;
	if (x != WIDTH/2)
	{
		game->lookingdir += (x-WIDTH/2)*0.1;
		put_cursor_middle(game);
		render_game(game);
	}
	return(0);
}