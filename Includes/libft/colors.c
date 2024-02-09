/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:15:08 by ysebban           #+#    #+#             */
/*   Updated: 2022/12/21 18:16:23 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	red(void)
{
	ft_printf("\033[0;31m");
}

void	green(void)
{
	ft_printf("\033[0;32m");
}

void	yellow(void)
{
	ft_printf("\033[0;33m");
}

void	blue(void)
{
	ft_printf("\033[0;34m");
}

void	reset_col(void)
{
	ft_printf("\033[0m");
}
