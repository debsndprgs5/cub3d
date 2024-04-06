/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_splitter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:18:52 by zfavere           #+#    #+#             */
/*   Updated: 2024/03/25 17:18:53 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	notempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
			return (1);
		else
			i++;
	}
	return (0);
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (!notempty(str))
		return (0);
	while (str[i])
	{
		if (ft_strchr("01WNES \n", str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
