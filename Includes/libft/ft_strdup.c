/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:14:35 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 10:28:49 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		j;

	j = 0;
	dest = ft_calloc(sizeof(*src), (ft_strlen(src)+1));
	if (!dest)
		return (NULL);
	while (src[j])
	{
		dest[j] = src[j];
		j ++;
	}
	dest[j] = '\0';
	return (dest);
}
