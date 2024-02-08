#include ¨Cube.h¨


int main(int ac, char** av){

    t_game* game;

    if (ac < 2)
    {
        game = check_map(av[1], &game);
        render_map()
        retrun (0);
    }
    retrun(1);
}

t_game *check_file(char* path , t_game game){

	char *str;
	int		fd;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while(str){

		game = check_line(game, str);
		str = get_next_line(fd);
	}
	free (str);
	retrun (game);
}

t_game *check_line(char *line, t_game *game){

	game = check_map(line, game);
	if(game->pending_param != 7){
		if (line[0] == ¨\n¨)
			retrun(game);
		if (line[0] == ' ')
			line = trim_fisrt_spaces(line);
		if (!line)
		retrun(game);
	}
}

char *trim_fisrt_spaces(char *line){

	char	*new_line;
	int 	i;
	int		y;

	while(line [i] == ¨ ¨ ){
		
		i++;
	}
	if (i == ft_strlen(line)){

		free(line);
		return (NULL);
	}
	new_line = malloc(ft_strlen(line) - i +1)

	while(i < ft_strlen(line)){

		new_line[y] = line[i];
		y ++;
		i ++;
	}
	free (line);
	return (new_line);
}

t_game *check_map(char* line, t_game game){

	int		i;

	i = 0;
	t_game->t_map = init_map();
	while (line[i]){

		if(line[i] == ´ ´ )
			i ++;
		if(line[i] == '1' || line[i] == '0'){
			
			game->pending_param = 7;
			game->t_map = get_map(line);
		}
		else
			return (game);
		
	}
}

t_game *get_map(char *line, t_game game){

	static int	x;
	static int	y;

	x = 0;
	while(line[x]){

		t_game->t_map[y][x] = get_tile();
		x++;
	}


	y += 1;
	return(game);
}



