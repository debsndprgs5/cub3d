#include "cube.h"

/* on recoit la pos d'un wall, la pos du player , on trouve la taille du wall 

	y -> proche ou eloigner 
	x -> a droite ou gauche
	
	valeur abs entre x et y   player/wall

	player size = 1;
	wall size = 2; -> Hauteur d'un mur;
	tile size = 1; -> profondeur d'une case;



*/
#define GBL_HIGTH = 960
#define WALL_HIGTH = 2;
#define FOV = 80;
#define PROJ_DIST = (GBL_HIGTH/2)/tan(FOV/2);
#define FLOOR_START = GBL_HIGTH /2;

double get_wall_higth(t_pos wall, t_pos player)
{
	return ((WALL_HIGTH * PROJ_DIST) / abs(wall->y, player->y)); // *ratio unite/pixel ?
}



/*

pour avoir la position des pixels sur la colonne (Ou termine le sol ou commence le sol)
et donc ou commence et fini le mur. 

check =  Hauteur de l'ecran - Hauteur du mur 

si check > 0 -> Mur plus petit que l'ecran 
	check/2 = taille du sol et taille du sol

si check <= 0
	mur sur tout l'ecran 
*/

void print_wall(t_pos player, t_pos wall, t_game *game, t_frame frame)
{
	double check;
	double wall_len;

	set_good_wall(player, wall, game, frame);
	wall_len = get_wall_higth(wall, player);
	check = GBL_HIGTH - wall_len;
	if (check > 0)
	//check/2 = ground or sky len; 
	else
		//all screen is wall;
}