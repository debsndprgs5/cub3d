/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:48:06 by ysebban           #+#    #+#             */
/*   Updated: 2022/09/22 15:35:06 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			i ++;
		else
			return (1);
	}	
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%d", ft_str_is_numeric("/:"));
	return (0);
}
*/
