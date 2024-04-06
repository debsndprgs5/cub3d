/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:36:10 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/19 22:37:05 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_abs(double val)
{
	if (val < 0)
		val = -val;
	return (val);
}

double	ft_val_abs(double ref, double val)
{
	if (ref > val)
		return (ref - val);
	return (val - ref);
}
