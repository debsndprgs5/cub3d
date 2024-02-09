/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:55:34 by ysebban           #+#    #+#             */
/*   Updated: 2022/12/08 19:12:34 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_putnbr_base(int nbr, char *base)
{
	int	i;
	int	len;

	i = ft_strlen(base);
	len = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr > i -1)
	{
		len += my_putnbr_base(nbr / i, base);
		len += my_putnbr_base(nbr % i, base);
	}
	else
		len += my_putchar(base[nbr]);
	return (len);
}

int	my_putnbr(int nb)
{	
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		my_putchar('-');
		write (1, "2147483648", 10);
		len = 11;
		return (len);
	}
	if (nb == 0)
		return (len += my_putchar('0'));
	if (nb < 0)
	{
		len += my_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		len += my_putnbr (nb / 10);
		len += my_putnbr (nb % 10);
	}
	if (nb <= 9)
		len += my_putchar(nb + 48);
	return (len);
}

int	my_unsigned_putnbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (len += my_putchar('0'));
	if (nb > 9)
	{
		len += my_unsigned_putnbr (nb / 10);
		len += my_unsigned_putnbr (nb % 10);
	}
	if (nb <= 9)
		len += my_putchar(nb + 48);
	return (len);
}

int	my_put_p(unsigned long long nbr, char *base)
{
	int					len;
	unsigned long long	i;

	len = 0;
	i = ft_strlen(base);
	if (nbr > i - 1)
	{
		len += my_put_p(nbr / i, base);
		len += my_put_p(nbr % i, base);
	}
	else
		len += my_putchar(base[nbr]);
	return (len);
}

int	useless(unsigned long long nbr)
{
	int	len;

	len = 0;
	len += my_putstr("0x");
	len += my_put_p(nbr, "0123456789abcdef");
	return (len);
}
