#include "cube.h"

int main(int ac, char** path)
{
	char **map;
    if (ac > 1)
    {
    	map = readmap(path[1]);
    	for (int i = 0; map[i]; i++)
    		printf("%s\n", map[i]);
        return (0);
    }
    return(1);
}


