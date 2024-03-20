#include "cube.h"

/*returns y pos in texture image*/
int get_texture_row(double x, double y, int size)
{
	int fl_x;
	int fl_y;

	//printf("double x %f doule y %f\n", x , y);
	fl_x = floor(x);
	fl_y = floor(y);
	if(fl_x == x && fl_y == y)
		return (0);
	x -= fl_x;
	y -= fl_y;
	if (x > 0)
		return(x*size);
	return(y*size);
}

/* avoir la bonne ligne en fonction de la hauteur du mur */
int get_texture_line(int line, int wall_size, int size)
{
	//printf("line %d , wall_size %d\n", line , wall_size);
	double tmp;
	if(line == 0)
		return (0);
	tmp = (double)line/(double)wall_size;
	return(tmp * size);
}

/*returns textures for a given point in an image*/
int get_textures(t_image texture, int x, int y)
{
	int *color;

	//printf("TEXTURES X %d, Y %d, %s\n", x ,y, texture.address);
	texture.address = mlx_get_data_addr(texture.mlx_img, &texture.bpp, &texture.line_length, &texture.endian);
	//printf("TEXTURES2 X %d\n", y * texture.line_length + x * (texture.bpp / 8));
	//color = texture.address[x * (texture.line_length/4) + y];
	color = (int*)&texture.address [x * texture.line_length + y * (texture.bpp / 4)];
	return(*color);
}

