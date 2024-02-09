/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:44:26 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/09 14:05:10 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned int	i;
	char			*chardestination;
	char			*charsource;

	i = 0;
	chardestination = (char *)destination;
	charsource = (char *)source;
	if (!destination && !source)
		return (0);
	while (i < size)
	{
		chardestination[i] = charsource[i];
		i++;
	}
	return (chardestination);
}

/*int main()
{
	char charsource[] = "HELLO";
	char chardestination[10];
	size_t size = 0;
	ft_memcpy(chardestination, charsource, size);
	printf("Destination string : %s", chardestination);
}*/
