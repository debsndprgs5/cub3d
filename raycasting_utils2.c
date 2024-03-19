/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:29:23 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/19 18:29:25 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

double	deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	fisheyefix(double dx, double dy)
{
	double	angle;

	angle = atan2(dy, dx);
	return (angle);
}

static void	handle_anormal_fov(t_game *game, double *angles)
{
	int		i;
	double	interval;
	double	radfov;

	radfov = deg_to_rad(FOV);
	angles[0] = deg_to_rad(game->lookingdir) - (radfov / 2);
	angles[WIDTH -1] = deg_to_rad(game->lookingdir) + (radfov / 2);
	interval = (angles[WIDTH - 1] - angles[0]) / WIDTH;
	i = 0;
	while (++i < WIDTH - 1)
		angles[i] = angles[i -1] + interval;
}

void	distribute_rays(t_game *game, double *angles)
{
	int		i;
	double	seg_len;
	double	radfov;

	radfov = deg_to_rad(FOV);
	if (radfov >= M_PI || radfov <= -M_PI)
	{
		handle_anormal_fov(game, angles);
		return ;
	}
	angles += WIDTH / 2;
	seg_len = tan(radfov / WIDTH);
	i = -WIDTH / 2;
	while (i < WIDTH / 2)
	{
		angles[i] = deg_to_rad(game->lookingdir) + atan(i * seg_len);
		i ++;
	}
}
