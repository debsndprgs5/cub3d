/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:39:24 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/16 15:39:26 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (ft_strlen((char *) s) < (int) start)
	{
		subs = malloc(sizeof(*s));
		if (!subs)
			return (0);
		subs[0] = 0;
		return (subs);
	}
	if ((start + len) > (unsigned long)ft_strlen((char *) s))
		len = ft_strlen((char *) s) - start;
	subs = malloc(sizeof(*s) * (len + 1));
	i = 0;
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}

/*if len < start return \0*/