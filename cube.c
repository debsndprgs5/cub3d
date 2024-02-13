#include "cube.h"

int main(int ac, char** path)
{
	char **map;
	t_game	game;


    if (ac > 1)
    {
    	map = readmap(path[1]);
    	for (int i = 0; map[i]; i++)
    		printf("%s\n", map[i]);
    	get_param(map, &game);
    	print_param(&game);
        return (0);
    }
    return(1);
}
