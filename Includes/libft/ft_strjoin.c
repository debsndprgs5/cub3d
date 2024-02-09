/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:04:23 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/17 17:15:35 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc(char const *s1, char const *s2)
{
	int	a;
	int	b;

	a = ft_strlen((char *)s1);
	b = ft_strlen ((char *)s2);
	return (a + b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(const char) * (ft_malloc(s1, s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i ++;
		j ++;
	}
	dest[j] = '\0';
	return (dest);
}
