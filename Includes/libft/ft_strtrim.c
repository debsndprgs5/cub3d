/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:05 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/16 16:46:07 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkflag(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && checkflag(s1[start], set) == 1)
		start++;
	end = ft_strlen((char *) s1);
	while (end > start && checkflag(s1[end - 1], set))
		end--;
	res = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}

/*int main()
{
	char *s1 = "abcdba";
	char *set = "abc";
	char *res = ft_strtrim(s1, set);
	printf("%s --> %s", s1, res);
}*/
