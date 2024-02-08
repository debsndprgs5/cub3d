
#ifndef CUBE_H
#define CUBE_H



typedef struct s_map{
	int 	pos_x;
	int 	pos_y;
	tile	type;
}	t_map;

typedef enum tile{

	SKY
	FLOOR
	WALL
	VOID
};


typedef struct s_param{

	char*	id;
	char*	texture_path;
}	t_param;

typedef struct s_color{
	
	int *[3] range; 
}	t_color;

typedef struct s_game{
	t_param		north_param;
	t_param		south_param;
	t_param		east_param;
	t_param		west_parm;
	t_color		ground;
	t_color		sky;
	t_map**		list_map;
	int			pending_param;
}	t_game;

/* pending param : 
	1 NORTH 
	2 SOUTH 
	3 WEST 
	4 EAST
	5 GROUND
	6 SKY
	7 MAP
*/ 
#endif
