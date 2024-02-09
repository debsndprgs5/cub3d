/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:00:20 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/19 14:55:13 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long n);

static char	*get_num(long long n, int len)
{
	char	*dest;
	int		fed_up;

	dest = ft_calloc(get_len(n) + 2, sizeof(*dest));
	if (!dest)
		return (NULL);
	fed_up = -1;
	if (n < 0)
	{
		n *= -1;
		dest[0] = '-';
		fed_up = 0;
	}
	while (len > fed_up)
	{
		dest[len] = '0' + (n % 10);
		n /= 10;
		len --;
	}
	return (dest);
}

static int	get_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (len);
	if (n < 0)
	{
		n *= -1;
		len ++;
	}
	while (n > 9)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*dest;
	long long	nbr;

	nbr = (long long )n;
	len = get_len(nbr);
	dest = get_num(nbr, len);
	return (dest);
}
