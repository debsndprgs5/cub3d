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
		for (int i = 0; parsedmap[i]; i++)
			printf("%s", parsedmap[i]);
		freetab(map);
		if (!init_struct(&game, configfile))
		{
			ft_printf("- ERROR -\nInvalid Config\n");
			//free game
			return (1);
		}
		if (!enclosed_check(parsedmap))
			return (1);
		//renderft();
		freetab(configfile);
		freetab(parsedmap);
	}
	return(0);
}
