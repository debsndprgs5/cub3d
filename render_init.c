/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:18:23 by ysebban           #+#    #+#             */
/*   Updated: 2024/03/14 17:18:51 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->address + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

void	load_raycast_image(t_game *game)
{
	
	if(game->is_current == true)
	{
		mlx_put_image_to_window(game->mlx_session, game->mlx_window, game->next.mlx_img, 0, 0);
		game->is_current = false;
		mlx_destroy_image(game->mlx_session, game->current.mlx_img);
		game->current = create_background(game);
	}
	else
	{		
		mlx_put_image_to_window(game->mlx_session, game->mlx_window, game->current.mlx_img, 0, 0);
		game->is_current = true;
		mlx_destroy_image(game->mlx_session, game->next.mlx_img);
		game->next = create_background(game);
	}
}






t_image	create_background(t_game *game)
{
	int x;
	int y;
	t_image background;

	x = 0;
	y = 0;
	background.mlx_img = mlx_new_image(game->mlx_session, WIDTH, HEIGHT);
	background.address = mlx_get_data_addr(background.mlx_img,
		&background.bpp, &background.line_length, &background.endian);
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			if (y <= HEIGHT / 2)
				my_pixel_put(&background, x, y, get_good_rgb(game->skycol));
			else
			{
				my_pixel_put(&background, x, y, get_good_rgb(game->groundcol));
			}
			y++;
		}
		x++;
	}
	return (background);
}
