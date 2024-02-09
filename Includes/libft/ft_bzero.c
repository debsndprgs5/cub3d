/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:10:30 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/09 16:44:13 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
	return (str);
}
/*
#include <strings.h>
#include <stdio.h>
int	main(void)
{
	char s[] = "123456789";
	void *str = s;
	size_t n = sizeof(char) * 5;
	printf("%s\n", ft_bzero(str, n));
	printf("%s\n", bzero(str, n));
	return (0);
}
*/
