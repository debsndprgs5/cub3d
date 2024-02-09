/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:04:16 by zfavere           #+#    #+#             */
/*   Updated: 2022/09/18 18:04:32 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	nbchar;

	nbchar = 0;
	while (str[nbchar])
	{		
		nbchar++;
	}
	return (nbchar);
}

/*int	main(void)
{
	char	*str = "hello";
	printf("%d", ft_strlen(str));
}
*/