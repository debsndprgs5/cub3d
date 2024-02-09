/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:54:05 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/18 17:54:06 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbchiff(int nb)
{
	int		len;

	len = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_revnb(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static void	ft_strrev(char *s)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(s);
	i = 0;
	while (i < length / 2)
	{
		tmp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	res = ft_calloc(nbchiff(n) + 1, sizeof(*res));
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
	}
	while (n != 0)
	{
		res[i++] = ft_revnb(n % 10) + '0';
		n = (n / 10);
	}
	if (neg == 1)
		res[i] = '-';
	ft_strrev (res);
	return (res);
}

/*int main()
{
	int n = -13345;
	int i;
	char *result;

	result = ft_itoa(n);
	i = 0;
	while (result[i])
	{
		printf("%d = %c\n", i, result[i]);
		i++;
	}
	return(0);
}*/
