/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:36 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/21 16:32:37 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		write (fd, "2147483648", 10);
		return ;
	}	
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}	
	if (nb > 9)
	{
		ft_putnbr_fd (nb / 10, fd);
		ft_putnbr_fd (nb % 10, fd);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + 48, fd);
}
