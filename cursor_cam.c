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

void	toogle_mouse(t_game *game)
{
	static bool	is_mouse_active = TRUE;

	if (is_mouse_active)
	{
		is_mouse_active = FALSE;
		mlx_mouse_show(game->mlx_session, game->mlx_window);
		mlx_hook(game->mlx_window, 6, 1L << 6, NULL, game);
	}
	else
	{
		is_mouse_active = TRUE;
		mlx_mouse_hide(game->mlx_session, game->mlx_window);
		mlx_hook(game->mlx_window, 6, 1L << 6, check_cursor, game);
	}
}

void	put_cursor_middle(t_game *game)
{
	mlx_mouse_move(game->mlx_session, game->mlx_window,
		WIDTH / 2, HEIGHT / 2);
}

int	check_cursor(int x, int y, t_game *game)
{
	(void)y;
	if (x != WIDTH / 2)
	{
		game->lookingdir += (x - WIDTH / 2) * 0.1;
		put_cursor_middle(game);
		render_game(game);
	}
	return (0);
}
