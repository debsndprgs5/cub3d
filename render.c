#include "cube.h"

int get_good_rgb(int *arr)
{
	int t;
	int r;
	int g;
	int b;

	t = 1;
	r = arr[0];
	g = arr[1];
	b = arr[3];
	return (t << 24 | r << 16 | g << 8 | b);
}

void	render_background(t_game *game)
{

	int x;
	int y;

	x = 0;
	y = 0;
	while(y <= WIDTH)//(MAx LEN)
	{
		x = 0;
		while(x <= LENGTH) //(max HIGTH)
		{
			if (x <= LENGTH/2)
				mlx_pixel_put(game->mlx_session, game->mlx_window, y, x, get_good_rgb(game->skycol));
			else
				mlx_pixel_put(game->mlx_session, game->mlx_window, y, x, get_good_rgb(game->groundcol));
			x++;
		}
		y++;
	}
	
	
}

// void render_walls(t_game *game)
// {
// 	//raycasting;
// }


int render_game(t_game *game)
{
	render_background(game);
	//render_walls(game);
	return(0);
}
