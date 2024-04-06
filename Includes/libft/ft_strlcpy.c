/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:05:17 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/11 16:37:39 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	i;

	s = (char*)src;
	i = ft_strlen(s);
	if (n == 0)
		return (i);
	if (!dest && !src)
		return (0);
	if (n < i)
		return (n);
	return (ft_strlen(ft_memmove(dest, src, n)));
}
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen((char *)src);
	if (slen + 1 < n)
	{
		while (i < slen +1)
		{
			dest[i] = src[i];
			i ++;
		}
	}
	else if (n > 0)
	{
		while (i < n -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (slen);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
