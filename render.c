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
	b = arr[2];
	return (t << 24 | r << 16 | g << 8 | b);
}



void render_wall(double wall_x, double wall_y, int pixel_rows, t_game *game)
{
	int wall_image;
	int wall_size;
	int start;
	int end;
	t_image to_fill;

	wall_image = set_good_wall(wall_x, wall_y, game);
	wall_size = (int)(HEIGHT/game->wall_dist);
	start = 0;
	if(game->is_current == false)
		to_fill = game->current;
	else
		to_fill = game->next;
	//to_fill.mlx_img = game->background.mlx_img;
	to_fill.address = mlx_get_data_addr(to_fill.mlx_img, &to_fill.bpp, &to_fill.line_length, &to_fill.endian);
	if (wall_size < HEIGHT)
	{
		start = (HEIGHT - wall_size) / 2;
		end = start + wall_size;
	}
	else
		end = HEIGHT;
	while(start <= end)
	{
		my_pixel_put(&to_fill, pixel_rows, start, wall_image);
		start++;
	}
	
}


int render_game(t_game *game)
{
	if(game->is_current == true)
		create_background(game, &game->next);
	else
		create_background(game, &game->current);
	raycasting_loop(game);
	return(0);
}

