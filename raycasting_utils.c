/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:29:35 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/19 18:29:37 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	iswall(int x, int y, char **map)
{
	if (y == -1)
		y = 0;
	if (map[y][x] == '1')
		return (1);
	return (0);
}

void	init_calc_ray(t_ray *ray)
{
	if (ray->dx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->dx);
	if (ray->dy == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->dy);
}
