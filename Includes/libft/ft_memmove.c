/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:57:42 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 10:35:47 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
		i = 0;
	if (!src && !dest)
		return (0);
	if (n == 0)
		return (dest);
	if (dest > src)
	{
		while (i < n)
		{
			d [n - 1] = s [n - 1];
			n--;
		}
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
