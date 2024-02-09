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

int	ft_abs(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

int	ft_val_abs(int ref, int val)
{
	int	abs_val;
	int	abs_ref;

	abs_ref = ref;
	abs_val = val;
	return (abs_ref - abs_val);
}
