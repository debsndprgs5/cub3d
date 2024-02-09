/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:41:14 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/19 14:34:50 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t len)
{
	void	*alloc;

	if (n > 4294967295 || len > 4294967295)
		return (0);
	alloc = malloc(len * n);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, len * n);
	return (alloc);
}
