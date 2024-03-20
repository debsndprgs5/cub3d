/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:37:22 by zfavere           #+#    #+#             */
/*   Updated: 2024/02/08 18:37:27 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	error_path(int ref)
{
	ref += 3;
	printerror(ref);
	return (0);
}

/*
1 = More than one W,S,E,N characters at once !
2 = Map is not enclosed by walls
3 = Can't open the North asset file
4 = Can't open the South asset file
5 = Can't open the East asset file
6 = Can't open the West asset file
7 = Error with args, undefined chars
8 = Error RGB range
9 = invalid Rgb args
10 = Invalid map format
11 = Memory alloc failed
12 = File may not exist
13 = Map contains forbidden characters
14 = Map missing 
15 = wrong extention(.cub || .xpm)
16 = Duplicate configs arguments
17 = Missing Arguments
18 = Position error - check the code
19 = Math error, please stop meth
*/

static const char	*errormsg[] = {
	"",
	"More/Less than one W,S,E,N characters at once !",
	"Map is not enclosed by walls",
	"Can't open the North asset file",
	"Can't open the South asset file",
	"Can't open the East asset file",
	"Can't open the West asset file",
	"Error with arguments, undefined characters founds",
	"Error with RGB range, [0 ... 255]",
	"Error with RGB arguments",
	"Invalid config format, loading default config...",
	"Memory alloc failed",
	"File may not exist",
	"Map contains forbidden characters",
	"Map missing",
	"Wrong extention name",
	"Duplicates arguments",
	"Missings arguments",
	"Position error, check the code",
	"Math error, please stop meth"
};

int	printerror(t_ErrorCode err)
{
	t_ErrorCode	code;

	code = err;
	if (code > 0 && code < sizeof(errormsg) / sizeof(errormsg[0]))
		printf("\e[1;31mError: \033[0m\e[1;36m%s\033[0m\n", errormsg[code]);
	else
		printf("Unknown error code.\n");
	return (0);
}
