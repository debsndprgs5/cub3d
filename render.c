#include "cube.h"

int get_good_rgb(int *arr)
{
	int t;
	int r;
	int g;
	int b;

	t = 0;
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

void render_wall(double wall_x, double wall_y, int pixel_rows, t_game *game)
{
	int wall_image;
	double wall_size;
	int start;
	int end;

	wall_image = set_good_wall(wall_x, wall_y, game);
	wall_size = get_wall_higth(wall_x, wall_y, game->ppos);
	// printf("HAUTEUR DU MUR %f\n", wall_size);
	start = 0;
	if (wall_size < LENGTH)
	{
		start = (LENGTH - wall_size)/2;
		end = wall_size;
	}
	else
		end = LENGTH;
	while(start <= end)
	{
		mlx_pixel_put(game->mlx_session, game->mlx_window, pixel_rows, start, wall_image);
		start++;
	}
	
}


int render_game(t_game *game)
{
	render_background(game);
	raycasting_loop(game);
	return(0);
}
