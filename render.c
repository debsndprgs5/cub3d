/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:29:35 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/19 18:29:37 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_good_rgb(int *arr)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = arr[0];
	g = arr[1];
	b = arr[2];
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_buffers(t_dbl_int *wall_buff, t_dbl_int *screen_buff, int wall_size)
{
	screen_buff->start = 0;
	screen_buff->end = HEIGHT;
	if (wall_size < HEIGHT)
	{
		screen_buff->start = (HEIGHT - wall_size) / 2;
		screen_buff->end = screen_buff->start + wall_size;
		wall_buff->start = 0;
		wall_buff->end = wall_size;
		return ;
	}
	wall_buff->start = (wall_size - HEIGHT) / 2;
	wall_buff->end = wall_buff->start + HEIGHT;
}

void	render_wall(double wall_x, double wall_y, int pixel_rows, t_game *game)
{
	t_render	render;

	set_good_wall(wall_x, wall_y, game, &render.current_wall);
	render.wall_size = round((double)HEIGHT / game->wall_dist);
	set_buffers(&render.wall_buff, &render.screen_buff, render.wall_size);
	if (game->is_current == false)
		render.to_fill = game->current;
	else
		render.to_fill = game->next;
	render.to_fill.address = mlx_get_data_addr(render.to_fill.mlx_img,
			&render.to_fill.bpp, &render.to_fill.line_length,
			&render.to_fill.endian);
	render.texture_row = get_texture_row(wall_x,
			wall_y, render.current_wall.width);
	while (render.screen_buff.start < render.screen_buff.end
		&& render.wall_buff.start < render.wall_buff.end)
	{
		my_pixel_put(&render.to_fill, pixel_rows, render.screen_buff.start,
			get_textures(render.current_wall.image,
				get_texture_line(render.wall_buff.start, render.wall_size,
					render.current_wall.height), render.texture_row));
		render.screen_buff.start++;
		render.wall_buff.start ++;
	}
}
