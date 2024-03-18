/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:33:16 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/12 20:19:42 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


double deg_to_rad(double degrees) 
{
	return (degrees * (M_PI / 180.0));
}

double rad_to_deg(double radians)
{
    return (radians * (180.0 / M_PI));
}

// Check if a map cell is a wall, int since walls are on a whole x, y (check for position problem)

static int iswall(int x, int y, char **map)
{
	if (y == -1)
		y = 0;
	if (map[y][x] == '1')
		return (1);
	return(0);
}

static void calc_ray_steps(t_game *game, t_ray *ray)
{
// dprintf(2, "entering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
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



double fisheyefix(double dx, double dy)
{
    double angle;
    angle = atan2(dy, dx);
    return angle;
}

static void ray_wall_hit_trigger(t_ray *ray, t_game *game,
	double *foundx, double *foundy)
{
// dprintf(2, "entering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
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
	game->wall_dist = ray->perpWallDist;
	game->wall_dist *= fabs(cos(fisheyefix(ray->dx, ray->dy) - deg_to_rad(game->lookingdir)));
}

static void cast_ray(t_game *game, double angle, double *foundx, double *foundy)
{
// dprintf(2, "entering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
	t_ray	ray;

	ray.dx = cos(angle);
	ray.dy = sin(angle);
	ray.hit = 0;
	calc_ray_steps(game, &ray);
	// Effectuez le lancer de rayon DDA
	ray.x0 = (int)game->ppos.x;
	ray.y0 = (int)game->ppos.y;
	while (ray.hit == 0 && ray.x0 >= 0 && ray.x0 < WIDTH && ray.y0 >= 0 && ray.y0 < HEIGHT)
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
		// Vérifier si le rayon a touché un mur
		if (iswall(ray.x0, ray.y0, game->map))
			ray_wall_hit_trigger(&ray, game, foundx, foundy);
	}
}


static void	handle_anormal_fov(t_game *game, double *angles)
{
// dprintf(2, "/033[31mentering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
	int		i;
	double	interval;
	double	radFOV;

	radFOV = deg_to_rad(FOV);
	angles[0] = deg_to_rad(game->lookingdir) - (radFOV / 2);
	angles[WIDTH -1] = deg_to_rad(game->lookingdir) + (radFOV / 2);
	interval = (angles[WIDTH - 1] - angles[0]) / WIDTH;
	i = 0;
	while (++i < WIDTH - 1)
		angles[i] = angles[i -1] + interval;
}


void	distribute_rays(t_game *game, double *angles)
{
	// dprintf(2, "entering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
	int		i;
	double	seg_len;
	double	radFOV;

	radFOV = deg_to_rad(FOV);
//	dprintf(2, "FOV = %d, radFOV = %f\n", FOV, radFOV);//DEBUG
	if (radFOV >= M_PI || radFOV <= -M_PI)
	{
		handle_anormal_fov(game, angles);
		return ;
	}
	angles += WIDTH / 2;
	seg_len = tan(radFOV / WIDTH);
//	dprintf(2, "\033[33mtan(%f) = %f\033[0;1m\n", radFOV, tan(radFOV));//DEBUG
//	seg_len = 0.5;
	// dprintf(2, "seglen calculed : %f\n", seg_len);//DEBUG
	i = -WIDTH/ 2;
	while (i < WIDTH / 2)
	{
		// dprintf(2, "loop %d\n", i);//DEBUG
		angles[i] = deg_to_rad(game->lookingdir) + atan(i * seg_len);
		// dprintf(2, "angles[%d] = %f\n", i, angles[i]);//DEBUG
		i ++;
	}
}


int raycasting_loop(t_game *game)
{
// dprintf(2, "entering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
	int		i;
	double	foundx;
	double	foundy;
	double	tabangles[WIDTH];
	// double temp;

	foundx = 0;
	foundy = 0;
	i = 0;
	// printf("testestestset = %f\n\n\n\n\n", game->lookingdir);
	distribute_rays(game, tabangles);
	// printf("\033[33mentering raycasting_loop\033[0;1m\n");
	while (i < WIDTH)
	{
		// printf("angle deg = %f, angle rad = %f\n", rad_to_deg(tabangles[i]), tabangles[i]);
		cast_ray(game, tabangles[i], &foundx, &foundy);
		//printf("Pixel row %d\n", i);
		render_wall(foundx, foundy, i, game);
		// printf("x du mur trouve = %f\ny du mur trouve = %f\n", foundx, foundy);
		i ++;
		
	}
	//dprintf(2, "HEYEHYEHYEHEY\n\n");
	load_raycast_image(game);
	printf("\033[0;33mexiting raycasting_loop\033[0m\n");
	return(0);
}

// 45 degrees = N
// 225 = S
// 315 = E
// 135 = W

double get_iniplayerdir(t_game *game)
{
dprintf(2, "entering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
printf("%d %d\n", (int)game->ppos.y + 1, (int)game->ppos.x + 1 );
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'N')
		return(90);
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'S')
		return(270);
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'E')
		return(0);
	if (game->map[(int)game->ppos.y + 1][(int)game->ppos.x + 1] == 'W')
		return(180);
	return(printerror(MATH_ERROR));
}
