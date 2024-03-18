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
	t_image 	wall_image;
	int 		wall_size;
	t_dbl_int	screen_buff;
	t_dbl_int	wall_buff;
	t_image 	to_fill;

	if(wall_y == -1)
		wall_y +=1;
	set_good_wall(wall_x, wall_y, game, &wall_image);
	wall_size = (int)(HEIGHT/game->wall_dist);
	screen_buff.start = 0;
	screen_buff.end = HEIGHT;
	if(game->is_current == false)
		to_fill = game->current;
	else
		to_fill = game->next;
	to_fill.address = mlx_get_data_addr(to_fill.mlx_img, &to_fill.bpp, &to_fill.line_length, &to_fill.endian);
	if (wall_size < HEIGHT)
	{
		screen_buff.start = (HEIGHT - wall_size) / 2;
		screen_buff.end = screen_buff.start + wall_size;
		wall_buff.start = 0;
		wall_buff.end = wall_size;
	}
	else
	{
		wall_buff.start = wall_size - HEIGHT; 
		wall_buff.end = wall_size;
	}
	while(screen_buff.start <= screen_buff.end)
	{
		my_pixel_put(&to_fill, pixel_rows, screen_buff.start, get_textures(wall_image, get_texture_line(wall_buff.start, wall_size) , get_texture_row(wall_x, wall_y)));
		screen_buff.start++;
		wall_buff.start ++;
	}
	mlx_destroy_image(game->mlx_session, wall_image.mlx_img);
	
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

void render_all(t_game *game)
{	
	render_game(game);	
	mlx_key_hook(game->mlx_window, get_key, game);
	mlx_loop(game->mlx_session);
}
