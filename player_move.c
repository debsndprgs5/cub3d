#include "cube.h"

static int iswall(int x, int y, char **map)
{
	if (y == -1)
		y = 0;
	if (map[y][x] == '1')
		return (1);
	return(0);
}

// static void calc_ray_steps(t_game *game, t_ray *ray)
// {
// 	// Ray's size from current point to the next x/y side
// 	if (ray->dx == 0)
// 	    ray->deltaDistX = 1e30;
// 	else
// 	    ray->deltaDistX = fabs(1 / ray->dx);
// 	if (ray->dy == 0)
// 	    ray->deltaDistY = 1e30;
// 	else
// 	    ray->deltaDistY = fabs(1 / ray->dy);
// 	// Ray's steps calculating
// 	if (ray->dx < 0)
// 	{
// 		ray->stepX = -1;
// 		ray->sideDistX = (game->ppos.x - (int)game->ppos.x) * ray->deltaDistX;
// 	}
// 	else
// 	{
// 		ray->stepX = 1;
// 		ray->sideDistX = ((int)game->ppos.x + 1 - game->ppos.x) * ray->deltaDistX;
// 	}
// 	if (ray->dy < 0)
// 	{
// 		ray->stepY = -1;
// 		ray->sideDistY = (game->ppos.y - (int)game->ppos.y) * ray->deltaDistY;
// 	}
// 	else
// 	{
// 		ray->stepY = 1;
// 		ray->sideDistY = ((int)game->ppos.y + 1 - game->ppos.y) * ray->deltaDistY;
// 	}
// }

/*on a un point une direction */

static int cast_ray(t_game *game, int angle, t_ppos *ray_end)
{
	t_ray	ray;
//	double tan_an;

	if(angle > 360)
		angle -= 360;
	ray.dx = cos(angle);
	ray.dy = sin(angle);
//	tan_an = atan2(ray.dy, ray.dx);
	ray.hit = 0;
	//calc_ray_steps(game, &ray);
	// Effectuez le lancer de rayon DDA
	ray.x0 = (int)game->ppos.x;
	ray.y0 = (int)game->ppos.y;
	ray_end->x = ray.x0 + (SPEED * cos(ray.dx));
	ray_end->y = ray.y0 + (SPEED * sin(ray.dy));
	// while ()
	// {
	// 	// Sautez au bloc suivant de la carte, en X ou en Y
	// 	if (ray.sideDistX < ray.sideDistY)
	// 	{
	// 		ray.sideDistX += ray.deltaDistX;
	// 		ray.x0 += ray.stepX;
	// 		ray.side = 0;
	// 	}
	// 	else
	// 	{
	// 		ray.sideDistY += ray.deltaDistY;
	// 		ray.y0 += ray.stepY;
	// 		ray.side = 1;
	// 	}
		// Vérifier si le rayon a touché un mur
		if (iswall((int)ray_end->x, (int)ray_end->y, game->map))
		{
			ray_end->x = game->ppos.x;
			ray_end->y = game->ppos.y; 
			printf("HELLO\n");
			return (1);
		}
	//ray_end->x += 0.1;
	//ray_end->y += 0.1;
	
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
	if (key == RIGTH_KEY)
		res += 90;
	if(angle > 360)
		res -= 360;
	return (res);
}

void player_moove(int key, t_game *game)
{
	int ray_angle;
	t_ppos ray_end;

	ray_angle = set_dir(key, game->lookingdir);
	//printf("WESH %d\n",cast_ray(game, ray_angle , &ray_end) );
	if (!cast_ray(game, ray_angle , &ray_end))
	{
		printf("Ray end x %f, y %f\n",ray_end.x, ray_end.y);
		game->ppos = ray_end;
		render_game(game);
	}

}

void player_look(int key, t_game *game)
{
	if(key == LOOK_LEFT)
		game->lookingdir -= LOOK_SPEED;

	if (key == LOOK_RIGTH)
		game->lookingdir += LOOK_SPEED;
	render_game(game);
}

int get_key(int key, t_game *game)
{

	if(key == UP_KEY ||key == DOWN_KEY ||key == LEFT_KEY ||key == RIGTH_KEY)
		player_moove(key, game);
	if(key == LOOK_LEFT || key == LOOK_RIGTH)
		player_look(key, game);
	//printf("KEYCODE %d", key);
	return (0);
}