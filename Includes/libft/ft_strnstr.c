/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:38:30 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 16:39:58 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if ((!tofind || !str) && n == 0)
		return (0);
	if (ft_strlen((char *)tofind) == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		if (tofind[j] == str[i])
		{
			while (tofind[j] && (tofind[j] == str[j + i]) && (i + j < n))
			{
				j++;
			}
			if (tofind[j] == '\0')
				return ((char *)str + i);
		}
		i ++;
	}
	return (0);
}
