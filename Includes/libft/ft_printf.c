/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:24:50 by zfavere           #+#    #+#             */
/*   Updated: 2022/12/02 15:53:06 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	formatflag(va_list arglist, const char format, int *charcount)
{
	if (format == 'c')
		ft_putchar(va_arg(arglist, int), charcount);
	if (format == 's')
		ft_putstr(va_arg(arglist, char *), charcount);
	if (format == 'p')
		ft_print_ptr(va_arg(arglist, unsigned long long), charcount);
	if (format == 'd' || format == 'i')
		ft_putnbr_base(va_arg(arglist, int), "0123456789", charcount);
	if (format == 'u')
		ft_putnbr_base(va_arg(arglist, unsigned int), "0123456789", charcount);
	if (format == 'x')
		ft_putnbr_base(va_arg(arglist, unsigned int),
			"0123456789abcdef", charcount);
	if (format == 'X')
		ft_putnbr_base(va_arg(arglist, unsigned int),
			"0123456789ABCDEF", charcount);
	if (format == '%')
		ft_putchar('%', charcount);
}

int	ft_printf(const char *arg0, ...)
{
	va_list	arglist;
	int		*charcount;
	int		a;
	int		i;

	a = 0;
	charcount = &a;
	i = 0;
	if (!arg0)
		return (0);
	va_start(arglist, arg0);
	while (arg0[i] != '\0')
	{
		if (arg0[i] == '%')
		{
			formatflag(arglist, arg0[i + 1], charcount);
			i++;
		}
		else
			ft_putchar(arg0[i], charcount);
		i++;
	}
	va_end(arglist);
	return (*charcount);
}

/*# include <stdio.h>
int main()
{
	int expected = 0;
	int res = 0;
	int diff = 0;

	expected = printf();
	res = ft_printf();
	printf("\n");
	printf("expected return value : %d\n", expected);
	printf("returned value : %d\n", res);
	diff = expected - res;
	printf("Diff = %d\n", diff);
	return (0);
}*/
