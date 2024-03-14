#include "cube.h"


#define WALL_HIGTH (double) 1.5

int is_full(double num)
{
	if(floor(fabs(num)) == fabs(num))
		return(1);
	return(0);
}	


/* East = 1 Weast  = 2 North = 10 South = 20 */

int	find_dir_wall(double wall_x, double wall_y,  t_ppos player)
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

/* check wether it's a front or side wall : corner = 0 / side wall = 1 / front wall = 2*/

int get_dir_wall(double wall_x, double wall_y)
{
	if(is_full(wall_x) && is_full(wall_y))
		return (0);
	if(is_full(wall_x))
		return (1);
	if(is_full(wall_y))
		return (2);
	return (0);
}


/* for each wall pos choose wich textures add on */

int set_good_wall(double wall_x, double wall_y, t_game *game)
{
	int	face;
	int dir;
	int north[3] = {67, 171, 107}; //green
	int south[3] = {67, 171, 107}; //red
	int east[3] = {158, 63, 65}; //blue
	int weast[3] = {158, 63, 65}; //yellow

	face = get_dir_wall(wall_x, wall_y);
	dir = find_dir_wall(wall_x, wall_y, game->ppos);
	if (face == 1 || face == 0) //SIDE
	{
		if (dir == 11 || dir == 21 || dir == 31)
			return (get_good_rgb(east));//EAST
		else
			return (get_good_rgb(weast)); //WEST
	}
	if (face == 2) // FRONT
	{
		if((dir > 10 && dir < 20) || dir > 30)
			return (get_good_rgb(north));//NORTH 
		else
			return (get_good_rgb(south));//SOUTH 
	}
	return (-1);
}

