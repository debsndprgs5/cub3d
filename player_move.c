#include "cube.h"

int set_dir(int key, int angle)
{
	int res;

	res = angle;
	
	if (key == UP_KEY)
		res += 0;
	if (key == DOWN_KEY)
		res += 180;
	if (key == LEFT_KEY)
		res -= 90; 
	if (key == RIGHT_KEY)
		res += 90;
	if(angle > 360)
		res -= 360;
	return (res);
}

void player_move(int key, t_game *game)
{
	int ray_angle;
	t_ppos ray_end;

	ray_angle = set_dir(key, game->lookingdir);
	ray_end = game->ppos;
	if (!cast_ray_player(game, ray_angle , &ray_end))
	{
		game->ppos = ray_end;
		raycasting_loop(game);
	}

}

void player_look(int key, t_game *game)
{
	if(key == LOOK_LEFT)
		game->lookingdir -= LOOK_SPEED;
	if (key == LOOK_RIGHT)
		game->lookingdir += LOOK_SPEED;
	raycasting_loop(game);
}

int get_key(int key, t_game *game)
{
	if (key == MOUSE_TGLE)
	 	toggle_mouse(game);
	if (key == 65307)
		exit_game(game);
	if (key == UP_KEY)
		game->keypress.key_forward = TRUE;
	if (key == DOWN_KEY)
		game->keypress.key_back = TRUE;
	if (key == LEFT_KEY)
		game->keypress.key_left = TRUE;
	if (key == RIGHT_KEY)
		game->keypress.key_right = TRUE;
	if (key == LOOK_LEFT)
		game->keypress.look_left = TRUE;
	if (key == LOOK_RIGHT)
		game->keypress.look_right = TRUE;
	return (0);
}

int release_key(int key, t_game *game)
{
	if (key == UP_KEY)
		game->keypress.key_forward = FALSE;
	if (key == DOWN_KEY)
		game->keypress.key_back = FALSE;
	if (key == LEFT_KEY)
		game->keypress.key_left = FALSE;
	if (key == RIGHT_KEY)
		game->keypress.key_right = FALSE;
	if (key == LOOK_LEFT)
		game->keypress.look_left = FALSE;
	if (key == LOOK_RIGHT)
		game->keypress.look_right = FALSE;
	return (0);
}