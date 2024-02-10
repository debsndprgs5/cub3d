#include "cube.h"

int main(int ac, char** path)
{
	char **map;
	char **configfile;
	char **parsedmap;
	t_game	game;

	if (ac > 1)
	{
		map = readmap(path[1]);
		split_map(map, &configfile, &parsedmap);
		if (!init_struct(&game, configfile))
		{
			ft_printf("- ERROR -\nInvalid Map\n");
			return (1);
		}
		//renderft();
		freetab(map);
		freetab(configfile);
		freetab(parsedmap);
	}
	return(0);
}


