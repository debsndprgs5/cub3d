#include "cube.h"

void free_tab(char **path)
{
	int i;

	i = 0;
	while(i < 4)
		free(path[i++]);
	free(path);
}

int init_asset(t_game *game)
{
	int i;

	i = 0;
	while(i < 4)
	{
		game->assets[i].image.mlx_img = mlx_xpm_file_to_image(game->mlx_session,
			game->paths[i], &game->assets[i].width, &game->assets[i].height);
		if (game->assets[i].image.mlx_img == (void*)0)
		{
			exit_game(game);
			return (printerror(EMPTY_XPM));
		}
		i++;
	}
	free_tab(game->paths);
	return (1);
}