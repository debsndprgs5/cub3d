/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:49:28 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/19 17:57:27 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(const char *sep, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && check_sep(set, s1[start]) == 1)
		start ++;
	end = ft_strlen((char *)s1);
	while (end > start && check_sep(set, s1[end -1]) == 1)
		end --;
	dest = (char *)malloc(sizeof(*s1) * (end - start +1));
	if (!dest)
		return (0);
	i = 0;
	while (start < end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}

static int	check_sep(const char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i ++;
	}
	return (0);
}
