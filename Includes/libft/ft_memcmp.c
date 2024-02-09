/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:00 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 14:35:44 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while ((n > 0) && (i != n))
	{
		if (s[i] != d[i])
			return ((int)(s[i] - d[i]));
		i ++;
	}
	return (0);
}
