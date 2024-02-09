/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:12:46 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/20 19:20:40 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (res)
	{
		res -> content = content;
		res -> ar_moove = -1;
		res -> br_moove = -1;
		res -> all_r_moove = -1;
		res -> arr_moove = -1;
		res -> brr_moove = -1;
		res -> all_rr_moove = -1;
		res -> all_moove = -1;
		res->next = NULL;
	}
	return (res);
}
