/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/08 18:37:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*returns y pos in texture image*/
int	get_texture_row(double x, double y, int size)
{
	int	fl_x;
	int	fl_y;

	fl_x = floor(x);
	fl_y = floor(y);
	if (fl_x == x && fl_y == y)
		return (0);
	x -= fl_x;
	y -= fl_y;
	if (x > 0)
		return ((x * size));
	return ((y * size));
}

/* avoir la bonne ligne en fonction de la hauteur du mur */
int	get_texture_line(int line, int wall_size, int size)
{
	double	tmp;

	tmp = (double) line / (double) wall_size;
	return ((tmp * size));
}

/*returns textures for a given point in an image*/
int	get_textures(t_image texture, int x, int y)
{
	int	*color;

	texture.address = mlx_get_data_addr(texture.mlx_img, &texture.bpp,
			&texture.line_length, &texture.endian);
	color = (int *)&texture.address[x * texture.line_length
		+ y * (texture.bpp / 8)];
	return (*color);
}
