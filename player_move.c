#include "cube.h"

static int iswall_look(int x, int y, char **map)
{
	if (y == -1)
		y = 0;
	if (map[y][x] == '1')
		return (1);
	return(0);
}

static void ray_wall_hit_trigger(t_ray *ray, t_game *game,
	double *foundx, double *foundy)
{
	ray->hit = 1;
// Déterminez la position précise du mur touché
	if (ray->side == 0)
	{
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
		if(ray->perpwalldist >= SPEED)
		{
			*foundx = game->ppos.x + SPEED * ray->dx;
			*foundy = game->ppos.y + SPEED * ray->dy;
		}
	}
	else
	{
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
		if(ray->perpwalldist >= SPEED)
		{
			*foundx = game->ppos.x + SPEED * ray->dx;
			*foundy = game->ppos.y + SPEED * ray->dy;
		}
	}
}

static void calc_ray_steps(t_game *game, t_ray *ray)
{
	// Ray's size from current point to the next x/y side
	if (ray->dx == 0)
	    ray->deltadistx = 1e30;
	else
	    ray->deltadistx = fabs(1 / ray->dx);
	if (ray->dy == 0)
	    ray->deltadisty = 1e30;
	else
	    ray->deltadisty = fabs(1 / ray->dy);
	// Ray's steps calculating
	if (ray->dx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->ppos.x - (int)game->ppos.x) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = ((int)game->ppos.x + 1.0 - game->ppos.x) * ray->deltadistx;
	}
	if (ray->dy < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->ppos.y - (int)game->ppos.y) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = ((int)game->ppos.y + 1.0 - game->ppos.y) * ray->deltadisty;
	}
}

/*on a un point une direction */

static int cast_ray(t_game *game, int angle, t_ppos *ray_end)
{
	t_ray	ray;

	if(angle > 360)
		angle -= 360;
	ray.dx = cos(deg_to_rad(angle));
	ray.dy = sin(deg_to_rad(angle));
	ray.hit = 0;
	calc_ray_steps(game, &ray);
	// Effectuez le lancer de rayon DDA
	ray.x0 = (int)game->ppos.x;
	ray.y0 = (int)game->ppos.y;
	while (ray.hit == 0 && ray.x0 >= 0 && ray.x0 < WIDTH && ray.y0 >= 0 && ray.y0 < HEIGHT)
	{
		// Sautez au bloc suivant de la carte, en X ou en Y
		if (ray.sidedistx < ray.sidedisty)
		{
			ray.sidedistx += ray.deltadistx;
			ray.x0 += ray.stepx;
			ray.side = 0;
		}
		else
		{
			ray.sidedisty += ray.deltadisty;
			ray.y0 += ray.stepy;
			ray.side = 1;
		}
		// Vérifier si le rayon a touché un mur
		if (iswall_look(ray.x0, ray.y0, game->map))
			ray_wall_hit_trigger(&ray, game, &ray_end->x, &ray_end->y);
	}
	return(0);
}




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
	//printf("WESH %d\n",cast_ray(game, ray_angle , &ray_end) );
	if (!cast_ray(game, ray_angle , &ray_end))
	{
		// printf("Ray end x %f, y %f\n",ray_end.x, ray_end.y);
		game->ppos = ray_end;
		render_game(game);
	}

}

void player_look(int key, t_game *game)
{
	if(key == LOOK_LEFT)
		game->lookingdir -= LOOK_SPEED;
	if (key == LOOK_RIGHT)
		game->lookingdir += LOOK_SPEED;
	render_game(game);
}

int get_key(int key, t_game *game)
{
	if (key == MOUSE_TGLE)
	 	toggle_mouse(game);
	if (key == 65307)
		exit_game(game);
	// if(key == UP_KEY ||key == DOWN_KEY ||key == LEFT_KEY ||key == RIGHT_KEY)
	// {
	// 	if (game->kpress == 0)
	// 		game->kpress = 1;
	// 	player_move(key, game);
	// }
	// if(key == LOOK_LEFT || key == LOOK_RIGHT)
	// 	player_look(key, game);
	//printf("KEYCODE %d", key);
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