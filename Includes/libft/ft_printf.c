/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:38:26 by ysebban           #+#    #+#             */
/*   Updated: 2022/12/08 19:13:04 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	a_voir;
	int		index;
	int		total;

	index = 0;
	total = 0;
	va_start (a_voir, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			total += sort_type (a_voir, str[index + 1]);
			index ++;
		}
		else
			total += my_putchar(str[index]);
		index ++;
	}
	va_end(a_voir);
	return (total);
}

int	sort_type(va_list a_voir, char c)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += my_putchar(va_arg(a_voir, int));
	else if (c == 's')
		total += my_putstr(va_arg(a_voir, char *));
	else if (c == 'p')
		total += useless(va_arg(a_voir, unsigned long long));
	else if (c == 'd')
		total += my_putnbr(va_arg(a_voir, int));
	else if (c == 'i')
		total += my_putnbr(va_arg(a_voir, int));
	else if (c == 'u')
		total += my_unsigned_putnbr(va_arg(a_voir, unsigned int));
	else if (c == 'x')
		total += my_putnbr_base(va_arg(a_voir, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		total += my_putnbr_base(va_arg(a_voir, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		total += my_putchar('%');
	return (total);
}

int	my_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	my_putstr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	return (i);
}
