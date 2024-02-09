#include "cube.h"

//Needs to add color and game exit
void error_color_parsing(int ref)
{
	if (ref == 1)
		ft_printf("Error with RGB range, [0 ... 255]\n");

	if (ref == 2)
		ft_printf("Error with RGB arguments needs 3\n")
}

void error_parse_line(int ref)
{
	if (ref == 1)
		ft_printf("Error with arguments , undefined characters founds\n");
}
