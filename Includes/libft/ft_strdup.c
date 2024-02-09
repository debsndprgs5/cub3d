/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:06:01 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/15 16:06:03 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len_s;
	int		i;

	len_s = ft_strlen((char *)src);
	dest = (char *) malloc(sizeof(char) * (len_s + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len_s)
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
