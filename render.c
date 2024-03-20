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
	t_asset 	current_wall;
	int 		wall_size;
	t_dbl_int	screen_buff;
	t_dbl_int	wall_buff;
	t_image 	to_fill;
	int 		texture_row;

	set_good_wall(wall_x, wall_y, game, &current_wall);
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
		wall_buff.end = wall_size-(0.75/game->wall_dist);
	}
	else
	{
		wall_buff.start = wall_size - HEIGHT; 
		wall_buff.end = wall_size;
	}
	texture_row = get_texture_row(wall_x, wall_y, current_wall.width);
	while(screen_buff.start <= screen_buff.end)
	{
		my_pixel_put(&to_fill, pixel_rows, screen_buff.start,
			get_textures(current_wall.image,get_texture_line(wall_buff.start, wall_size, current_wall.height),texture_row));
		screen_buff.start++;
		wall_buff.start ++;
	}
	//mlx_destroy_image(game->mlx_session, current_wall.image.mlx_img);
	
}

t_image cpy_image(t_image *ref, t_game *game)
{
	t_image new;
	new.mlx_img = mlx_new_image(game->mlx_session,WIDTH,HEIGHT);
	new.mlx_img = ref->mlx_img;
	return(new);
}


int render_game(t_game *game)
{
	// if(game->is_current == true)
	// 	game->next = game->background;
	// else
	// 	game->current = game->background;
	raycasting_loop(game);
	return(0);
}

