#include "cube.h"

//Needs to add color and game exit
int error_color_parsing(int ref)
{
	if (ref == 1)
		ft_printf("Error with RGB range, [0 ... 255]\n");

	if (ref == 2)
		ft_printf("Error with RGB arguments\n");
	return (0);
}

int error_parse_line(int ref)
{
	if (ref == 1)
		ft_printf("Error with arguments , undefined characters founds\n");
	return (0);
}

int error_path(int ref)
{
	if (ref == 0)
		ft_printf(" | FATAL | Can't open path for North textures");
	if (ref == 1)
		ft_printf(" | FATAL | Can't open path for South textures");
	if (ref == 2)
		ft_printf(" | FATAL | Can't open path for East textures");
	if (ref == 3)
		ft_printf(" | FATAL | Can't open path for West textures");
	return (0);
}