/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:03 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/02 05:19:56 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if ((c == '\t' )
		|| (c == '\n' )
		|| (c == '\r' )
		|| (c == ' ' )
		|| (c == '\v' )
		|| (c == '\f' ))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if(str[i] == '0')
		return (0);
	while (ft_is_space(str[i]) == 1)
		i ++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i ++;
	}
	if (sign == -1)
		return (-nb);
	return (nb);
}
