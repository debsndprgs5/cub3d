/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:46:02 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/08 13:46:06 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*dst;

	dst = (unsigned char *)s;
	while (len > 0)
	{
		*dst = (unsigned char) c;
		dst++;
		len--;
	}
	return (s);
}
