#include "cube.h"


void	print_param(t_game *game)
{
	int i;

	i = 0;
	while (i <= 2)
	{
		printf("SKY COL : %d\n", game->skycol[i]);
		i ++;
	}
	i = 0;
	while (i <= 2)
	{
		printf("GROUND COL : %d\n", game->groundcol[i]);
		i ++;
	}
	i = 0;
	while (i <= 3)
	{
		if (i == 0)
		{
			printf("NORTH TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		if (i == 1)
		{
			printf("SOUTH TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		if (i == 2)
		{
			printf("EAST TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		if (i == 3)
		{
			printf("WEST TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		i ++;
	}

	
}
