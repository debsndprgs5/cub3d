#include "cube.h"

int main(int ac, char** path)
{
	char **map;
	char **part1;
	char **part2;

	if (ac > 1)
	{
		map = readmap(path[1]);
		printf("MAP AVANT DECOUPAGE --------------------\n");
		for (int i = 0; map[i]; i++)
			printf("%s", map[i]);
		printf("MAP APRES DECOUPAGE --------------------\n");
		split_map(map, &part1, &part2);
		printf("----- PART 1 -----\n");
		for (int i = 0; part1[i]; i++)
			printf("%s", part1[i]);
		printf("----- PART 2 -----\n");
		for (int i = 0; part2[i]; i++)
			printf("%s", part2[i]);
		return (0);
	}
	return(1);
}


