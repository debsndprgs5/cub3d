#define CUBE_H
#ifndef CUBE_H

map{
	param[4]	params;
	color		ground;
	color		sky;
	char**		list_map;
};

param{

	char*	id;
	char*	texture_path;
};

color{
	int *[3] range; 
};

#endif
