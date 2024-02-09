/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:04:13 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/15 17:04:18 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbel, size_t size)
{
	char	*tab;

	if (nbel >= 4294967295 || size >= 4294967295)
		return (NULL);
	tab = malloc(size * nbel);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (size * nbel));
	return (tab);
}
