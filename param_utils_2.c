
#include "cube.h"

int	check_extention(char *path, char *ext, int len)
{
	int i;

	i = ft_strlen(path);
	i --;
	while(ext[len] && len >= 0)
	{
		if (path[i] != ext[len])
			return (0);
		len --;
		i --;
	}
	return (1);
}

char *parse_config_line(char *line)
{
	char	*new_line;
	char	*temp_line;

	new_line = removes_first_spaces(line, 0);
	temp_line = removes_last_stuff(new_line);
	//free(new_line);
	free (new_line);
	return (temp_line);
}