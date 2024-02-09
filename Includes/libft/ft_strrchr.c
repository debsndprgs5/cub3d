/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:10:40 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/14 13:18:40 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	tofind;

	n = ft_strlen((char *)s);
	tofind = (char)c;
	while (n > 0)
	{
		if (tofind == s[n])
			return (((char *)s + n));
		n --;
	}
	if (tofind == s[n])
		return (((char *)s + n));
	return (NULL);
}
