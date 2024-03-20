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

static void	calc_ray_steps(t_game *game, t_ray *ray)
{
	init_calc_ray(ray);
	if (ray->dx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->ppos.x - (int)game->ppos.x) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = ((int)game->ppos.x + 1.0 - game->ppos.x)
			* ray->deltadistx;
	}
	if (ray->dy < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->ppos.y - (int)game->ppos.y) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = ((int)game->ppos.y + 1.0 - game->ppos.y)
			* ray->deltadisty;
	}
}

static void	ray_wall_hit_trigger(t_ray *ray, t_game *game,
	double *foundx, double *foundy)
{
	ray->hit = 1;
	if (ray->side == 0)
	{
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
		*foundx = ray->x0;
		*foundy = game->ppos.y + ray->perpwalldist * ray->dy;
	}
	else
	{
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
		*foundx = game->ppos.x + ray->perpwalldist * ray->dx;
		*foundy = ray->y0;
	}
	game->wall_dist = ray->perpwalldist;
	game->wall_dist *= fabs(cos(fisheyefix(ray->dx, ray->dy)
				- deg_to_rad(game->lookingdir)));
}

static void	cast_ray(t_game *game, t_ray *ray, double *foundx, double *foundy)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->x0 += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->y0 += ray->stepy;
		ray->side = 1;
	}
	if (iswall(ray->x0, ray->y0, game->map))
		ray_wall_hit_trigger(ray, game, foundx, foundy);
}

static void	init_cast_ray(t_game *game, double angle,
	double *foundx, double *foundy)
{
	t_ray	ray;

	ray.dx = cos(angle);
	ray.dy = sin(angle);
	ray.hit = 0;
	calc_ray_steps(game, &ray);
	ray.x0 = (int)game->ppos.x;
	ray.y0 = (int)game->ppos.y;
	while (ray.hit == 0 && ray.x0 >= 0 && ray.x0 < WIDTH
		&& ray.y0 >= 0 && ray.y0 < HEIGHT)
		cast_ray(game, &ray, foundx, foundy);
}

int	raycasting_loop(t_game *game)
{
	int		i;
	double	foundx;
	double	foundy;
	double	tabangles[WIDTH];

	foundx = 0;
	foundy = 0;
	i = 0;
	distribute_rays(game, tabangles);
	while (i < WIDTH)
	{
		init_cast_ray(game, tabangles[i], &foundx, &foundy);
		render_wall(foundx, foundy, i, game);
		i ++;
	}
	load_raycast_image(game);
	return (0);
}
