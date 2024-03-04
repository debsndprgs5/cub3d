#include "cube.h"

/* on recoit la pos du mur en x et y et la pos du joueur en x et y 
	t_pos {
	double x;
	double y;
	}
	y
	y
	y
	y
	 xxxxxxx

	si player->x > wall->x ==> wall a gauche
	si player->y > wall->y ==> wall en bas
	
*/

int is_full(double num)
{
	int	tmp;

	tmp = (int)num;
	if (num == tmp)
		return (0);
	return (1);
}

/* East = 1 Weast  = 2 North = 10 South = 20 */

int	find_dir_wall(t_pos wall, t_pos player)
{

	int	dir;

	dir = 0;
	if (player->x > wall->x)
		dir += 2;
	else if (player->x < wall->x)
		dir += 1;
	else if (player->x == wall->x)
		dir += 3;
	if (player->y > wall->y)
		dir += 20;
	else if (player->y < wall->y)
		dir += 10;
	else if (player->y == wall->y)
		dir += 30;
	return (dir);
}

/* check wether it's a front or side wall : corner = 0 / side wall = 1 / front wall = 2*/

int get_dir_wall(t_pos wall)
{
	if(is_full(wall->x) && is_full(wall->y))
		return (0)
	if(is_full(wall->x))
		return (1);
	if(is_full(wall->y))
		return (2);
}


/* for each wall pos choose wich textures add on */

void set_good_wall(t_pos player, t_pos wall, t_game *game, t_frame frame)
{
	int wall_asset;
	int	face;
	int dir;

	wall_asset = 0;
	face = get_dir_wall(wall);
	dir = find_dir_wall(wall, player);
	if (face == 0) // CORNER ?
	{
	}
	if (face == 1) //SIDE
	{
		if (dir == 11 || 21 || 31)
			frame->image = game->t_frame->w_ea_img;	//EAST
		else
			frame->image = game->t_frame->w_we_img; //WEST
	}
	if (face == 2) // FRONT
	{
		if(dir > 10 && dir < 20 || dir > 30)
			frame->image = game->t_frame->w_no_img;//NORTH 
		else 
			frame->image = game->t_frame->W_so_img;//SOUTH 
	}
}