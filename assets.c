#include "cube.h"

void init_asset(t_game *game)
{
	int i;

	i = 0;
	while(i < 4)
	{
		game->assets[i].image.mlx_img = mlx_xpm_file_to_image(game->mlx_session,
			game->paths[i], &game->assets[i].width, &game->assets[i].height);
		free(game->paths[i]);
		i++;
	}
	game->background = create_background(game);
	free(game->paths);
}