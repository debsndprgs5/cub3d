/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:44:20 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/17 17:25:04 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tofind;

	i = 0;
	tofind = (char)c;
	while (s[i])
	{
		if (tofind == s[i])
			return (((char *)s + i));
		i ++;
	}
	if (tofind == s[i])
		return (((char *)s + i));
	return (NULL);
}
