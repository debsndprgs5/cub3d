/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:20:32 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 14:37:44 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	tofind;
	char	*str;

	i = 0;
	tofind = (char)c;
	str = (char *)s;
	while (i < n)
	{
		if (tofind == str[i])
			return (((char *)str) + i);
		i ++;
	}
	return (NULL);
}
