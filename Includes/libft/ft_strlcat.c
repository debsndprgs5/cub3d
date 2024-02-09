/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:38:00 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 12:14:50 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	xlen;
	size_t	i;
	size_t	dlen;

	if (n == 0)
		return (ft_strlen((char *) src));
	i = 0;
	xlen = ft_strlen(dest);
	dlen = ft_strlen(dest);
	if (dlen >= n)
		return (ft_strlen((char *) src) + n);
	while (src[i] && xlen + 1 < n)
	{
		dest[xlen] = src[i];
		xlen++;
		i++;
	}
	dest[xlen] = '\0';
	return (dlen + ft_strlen((char *) src));
}
