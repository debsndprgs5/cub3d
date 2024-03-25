/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:04:06 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/25 17:04:08 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ray_wall_hit_trigger(t_ray *ray, t_game *game,
	double *foundx, double *foundy)
{
	ray->hit = 1;
	if (ray->side == 0)
	{
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
		if (ray->perpwalldist >= SPEED + 0.1)
		{
			*foundx = game->ppos.x + SPEED * ray->dx;
			*foundy = game->ppos.y + SPEED * ray->dy;
		}
	}
	else
	{
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
		if (ray->perpwalldist >= SPEED + 0.1)
		{
			*foundx = game->ppos.x + SPEED * ray->dx;
			*foundy = game->ppos.y + SPEED * ray->dy;
		}
	}
}

static void	calc_ray_steps(t_game *game, t_ray *ray)
{
	if (ray->dx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->dx);
	if (ray->dy == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->dy);
	if (ray->dx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->ppos.x - (int)game->ppos.x) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = ((int)game->ppos.x
				+ 1.0 - game->ppos.x) * ray->deltadistx;
	}
}

static void	init_ray(t_ray *ray, int angle, t_game *game)
{
	ray->dx = cos(deg_to_rad(angle));
	ray->dy = sin(deg_to_rad(angle));
	ray->hit = 0;
	calc_ray_steps(game, ray);
	if (ray->dy < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->ppos.y - (int)game->ppos.y) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = ((int)game->ppos.y
				+ 1.0 - game->ppos.y) * ray->deltadisty;
	}
	ray->x0 = (int)game->ppos.x;
	ray->y0 = (int)game->ppos.y;
}

int	cast_ray_player(t_game *game, int angle, t_ppos *ray_end)
{
	t_ray	ray;

	if (angle > 360)
		angle -= 360;
	init_ray(&ray, angle, game);
	while (ray.hit == 0 && ray.x0 >= 0
		&& ray.x0 < WIDTH && ray.y0 >= 0 && ray.y0 < HEIGHT)
	{
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
		if (iswall(ray.x0, ray.y0, game->map))
			ray_wall_hit_trigger(&ray, game, &ray_end->x, &ray_end->y);
	}
	return (0);
}
