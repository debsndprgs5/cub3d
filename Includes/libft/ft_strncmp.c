/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <zfavere@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:35:36 by zfavere           #+#    #+#             */
/*   Updated: 2022/09/22 04:21:03 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		i++;
	}
	return (0);
}
