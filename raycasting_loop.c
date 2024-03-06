/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:33:16 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/28 19:33:17 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


#define PI 3.14159265358979323846


static double deg_to_rad(double degrees) 
{
	return (degrees * (PI / 180.0));
}

// Check if a map cell is a wall, int since walls are on a whole x, y (check for position problem)

static int iswall(int x, int y, char **map)
{
	if (map[y][x] == '1')
		return (1);
	return(0);
}

static void calc_ray_steps(t_game *game, t_ray *ray)
{
	// Ray's size from current point to the next x/y side
	if (ray->dx == 0)
	    ray->deltaDistX = 1e30;
	else
	    ray->deltaDistX = fabs(1 / ray->dx);
	if (ray->dy == 0)
	    ray->deltaDistY = 1e30;
	else
	    ray->deltaDistY = fabs(1 / ray->dy);
	// Ray's steps calculating
	if (ray->dx < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->ppos.x - (int)game->ppos.x) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = ((int)game->ppos.x + 1.0 - game->ppos.x) * ray->deltaDistX;
	}
	if (ray->dy < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->ppos.y - (int)game->ppos.y) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = ((int)game->ppos.y + 1.0 - game->ppos.y) * ray->deltaDistY;
	}
}

static void ray_wall_hit_trigger(t_ray *ray, t_game *game,
	double *foundx, double *foundy)
{
	ray->hit = 1;
// Déterminez la position précise du mur touché
	if (ray->side == 0)
	{
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
		*foundx = ray->x0;
		*foundy = game->ppos.y + ray->perpWallDist * ray->dy;
	}
	else
	{
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
		*foundx = game->ppos.x + ray->perpWallDist * ray->dx;
		*foundy = ray->y0;
	}
}

static void cast_ray(t_game *game, double angle, double *foundx, double *foundy)
{
	t_ray	ray;

	ray.dx = cos(angle);
	ray.dy = sin(angle);
	ray.hit = 0;
	calc_ray_steps(game, &ray);
	// Effectuez le lancer de rayon DDA
	ray.x0 = (int)game->ppos.x;
	ray.y0 = (int)game->ppos.y;
	while (ray.hit == 0 && ray.x0 >= 0 && ray.x0 < WIDTH && ray.y0 >= 0 && ray.y0 < LENGTH)
	{
		// Sautez au bloc suivant de la carte, en X ou en Y
		if (ray.sideDistX < ray.sideDistY)
		{
			ray.sideDistX += ray.deltaDistX;
			ray.x0 += ray.stepX;
			ray.side = 0;
		}
		else
		{
			ray.sideDistY += ray.deltaDistY;
			ray.y0 += ray.stepY;
			ray.side = 1;
		}
		// Vérifiez si le rayon a touché un mur
		if (iswall(ray.x0, ray.y0, game->map))
			ray_wall_hit_trigger(&ray, game, foundx, foundy);
	}
}


int raycasting_loop(t_game *game)
{
	double	i;
	double foundx;
	double foundy;
	double angle;
	double temp;

	foundx = 0;
	foundy = 0;
	i = 0;
	angle = (double) game->lookingdir;
	temp = (double) WIDTH / (double) FOV;
	temp = 1/temp;
	while (i <= WIDTH)
	{
		printf("angle = %f\n", angle);
		cast_ray(game, deg_to_rad(angle), &foundx, &foundy);
		i++;
		angle += temp;
		if (angle >= 360)
			angle -= 360;
		printf("x du mur trouve = %f\ny du mur trouve = %f\n", foundx, foundy);
	}
	return(0);
}


// 45 degrees = N
// 225 = S
// 315 = E
// 135 = W

int get_iniplayerdir(t_game *game)
{
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'N')
		return(45);
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'S')
		return(225);
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'E')
		return(315);
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'W')
		return(135);
	return(printerror(MATH_ERROR));
}