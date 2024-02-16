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
			ft_printf("NORTH TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		if (i == 1)
		{
			ft_printf("SOUTH TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		if (i == 2)
		{
			ft_printf("EAST TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		if (i == 3)
		{
			ft_printf("WEST TEXTURE IN GAME DATA : %s\n", game->paths[i]);
		}
		i ++;
	}

	
}
