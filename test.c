#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int key_hook(int keycode, void *param)
{
    printf("Key pressed: %d\n", keycode);
    (void)param;
    return (0);
}

/*returns textures for a given point in an image*/
int get_textures(t_image texture, int x, int y)
{
	int color;

	//printf("TEXTURES X %d, Y %d, %s\n", x ,y, texture.address);
	texture.address = mlx_get_data_addr(texture.mlx_img, &texture.bpp, &texture.line_length, &texture.endian);
	//printf("TEXTURES2 X %d\n", y * texture.line_length + x * (texture.bpp / 8));
	//color = texture.address[x * (texture.line_length/4) + y];
	color = texture.address [x * texture.line_length + y * (texture.bpp / 4)];
	return(color);
}

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
	void	*mlx_image;
	void	*mlx_new_image;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Key Press Event");
    if (win_ptr == NULL)
    {
        free(mlx_ptr);
        return (1);
    }
    mlx_
    mlx_loop(mlx_ptr);
    return (0);
}



a = 97
s = 115
w = 119
d = 100
esc = 65307