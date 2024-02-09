/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:33:15 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/09 14:33:17 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	if (!dest && !src)
		return (0);
	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	while (i < n)
	{
		if (cdest <= csrc)
		{
			cdest[i] = csrc[i];
			i++;
		}
		else if (cdest > csrc)
		{
			cdest[n - i - 1] = csrc[n - i - 1];
			i++;
		}
	}
	return (cdest);
}
