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
	double	rad;

	rad = degrees * (PI / 180.0);
	return (rad);
}

// Check if a map cell is a wall, int since walls are on a whole x, y (check for position problem)

static int iswall(int x, int y, char **map)
{
	if (map[y][x] == '1')
		return (1);
	return(0);
}

static void cast_ray(t_game *game, double angle, double *foundx, double *foundy)
{
	double y;
	double x;
	double dx;
	double dy;

	y = game->ppos.y;
	x = game->ppos.x;
	dx = cos(deg_to_rad(angle));
    dy = sin(deg_to_rad(angle));
	while (!iswall((int)x, (int)y, game->map))
	{
		x += dx * 0.001;
		y += dy * 0.001;
	}
	(*foundx) = x;
	(*foundy) = y;
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
	angle = 0;
	temp = WIDTH / FOV;
	temp = 1/temp;
	while (i <= WIDTH)
	{
		//printf("angle = %f\n", angle);
		cast_ray(game, angle, &foundx, &foundy);
		render_wall(foundx, foundy, i, game);
		i++;
		angle += temp;
		//printf("x du mur trouve = %f\ny du mur trouve = %f\n", foundx, foundy);
		
	}
	return(0);
}
