/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:04:06 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/25 17:04:08 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
