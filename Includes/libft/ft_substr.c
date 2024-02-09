/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:03:06 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/19 17:49:12 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if ((int)start > ft_strlen(s))
		dest = malloc(sizeof(char));
	else if ((int)len > ft_strlen(s))
		dest = malloc((ft_strlen(s) - start) * sizeof(char));
	else
		dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while ((int)i <= ft_strlen(s))
	{
		if (i >= (size_t)start && j < len)
			dest[j++] = s[i++];
		else
			i++;
	}
	dest[j] = '\0';
	return (dest);
}		
