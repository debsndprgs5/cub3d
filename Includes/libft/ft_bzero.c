/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:56:44 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/09 11:56:47 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		((char *) s)[pos] = 0;
		pos++;
	}
}

/*int main()
{
	int i[10]   = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
	size_t pos = 4;

	ft_bzero(i, (pos * sizeof(int)));

	for(; pos < 10; pos++)
	{
		printf("%lu: %d\n", (pos + 1), i[pos]);
	}
	return (0);
}*/