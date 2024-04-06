/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_good_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/08 18:37:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_full(double num)
{
	if (floor(fabs(num)) == fabs(num))
		return (1);
	return (0);
}

/* East = 1 Weast  = 2 North = 10 South = 20 */

int	find_dir_wall(double wall_x, double wall_y, t_ppos player)
{
	int	dir;

	dir = 0;
	if (player.x > wall_x)
		dir += 2;
	else if (player.x < wall_x)
		dir += 1;
	else if (player.x == wall_x)
		dir += 3;
	if (player.y > wall_y)
		dir += 20;
	else if (player.y < wall_y)
		dir += 10;
	else if (player.y == wall_y)
		dir += 30;
	return (dir);
}

/* check wether it's a front or side wall :
corner = 0 / side wall = 1 / front wall = 2*/

int	get_dir_wall(double wall_x, double wall_y)
{
	if (is_full(wall_x) && is_full(wall_y))
		return (0);
	if (is_full(wall_x))
		return (1);
	if (is_full(wall_y))
		return (2);
	return (0);
}

/* for each wall pos choose wich textures add on */

void	set_good_wall(double wall_x, double wall_y,
		t_game *game, t_asset *current_wall)
{
	int	face;
	int	dir;

	face = get_dir_wall(wall_x, wall_y);
	dir = find_dir_wall(wall_x, wall_y, game->ppos);
	if (face == 1 || face == 0)
	{
		if (dir == 11 || dir == 21 || dir == 31)
			*current_wall = game->assets[2];
		else
			*current_wall = game->assets[3];
	}
	if (face == 2)
	{
		if ((dir > 10 && dir < 20) || dir > 30)
			*current_wall = game->assets[0];
		else
			*current_wall = game->assets[1];
	}
}

/*Sorry here for norm Issues*/

int	color_loop(char *parse_line, t_dbl_int index, int *stack)
{
	int		check;
	int		temp;
	char	*str_to_int;

	while (parse_line[index.start])
	{
		check = 0;
		str_to_int = cut_till_next_coma(parse_line, index.start);
		index.start = get_til_next_coma(parse_line, index.start);
		temp = ft_cube_atoi(str_to_int, &check);
		if (!is_good_rgb(str_to_int, temp) || check == 1)
			return (printerror(RGB_RANGE));
		stack[index.end] = temp;
		free(str_to_int);
		index.end ++;
	}
	return (1);
}
