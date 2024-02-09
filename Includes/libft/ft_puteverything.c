/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puteverything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:38:18 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/28 15:38:19 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long nb, const char *base, int *charcount)
{
	if (nb < 0)
	{
		ft_putchar('-', charcount);
		nb = -nb;
	}
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base (nb / ft_strlen(base), base, charcount);
		ft_putnbr_base (nb % ft_strlen(base), base, charcount);
	}
	if (nb < ft_strlen(base))
		ft_putchar(base[nb], charcount);
}

static void	ft_unputnbr_base(unsigned long long nb,
	const char *base, int *charcount)
{
	if (nb >= (unsigned long long) ft_strlen(base))
	{
		ft_unputnbr_base (nb / ft_strlen(base), base, charcount);
		ft_unputnbr_base (nb % ft_strlen(base), base, charcount);
	}
	if (nb < (unsigned long long) ft_strlen(base))
		ft_putchar(base[nb], charcount);
}

void	ft_putchar(int c, int *charcount)
{
	write (1, &c, 1);
	(*charcount)++;
}

int	ft_putstr(char *str, int *charcount)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", charcount);
		return (0);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], charcount);
		i++;
	}
	return (1);
}

void	ft_print_ptr(unsigned long long nb, int *charcount)
{
	write (1, "0x", 2);
	(*charcount)++;
	(*charcount)++;
	ft_unputnbr_base(nb, "0123456789abcdef", charcount);
}
