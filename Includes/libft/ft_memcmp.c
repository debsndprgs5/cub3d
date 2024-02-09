/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:36:51 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/15 14:36:53 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
			i++;
		else
		{
			res = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
			return (res);
		}
	}
	return (0);
}

/*	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		i++;
	}
*/