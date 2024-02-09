/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfavere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:38:01 by zfavere           #+#    #+#             */
/*   Updated: 2022/11/18 14:38:03 by zfavere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlen(const char *s, char charset)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != charset)
		i++;
	return (i);
}

static int	wordcount(const char *s, char charset)
{
	int	i;
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == charset)
			s++;
		i = wordlen(s, charset);
		s += i;
		if (i != 0)
			count++;
	}
	return (count);
}

static char	*wordcpy(const char *src, int n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	**ft_split(const char *s, char charset)
{
	char	**result;
	int		size;
	int		i;
	int		n;

	size = wordcount(s, charset);
	result = malloc((size + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s && *s == charset)
			s++;
		n = wordlen(s, charset);
		result[i] = wordcpy(s, n);
		if (!(result[i]))
			return (NULL);
		s += n;
		i++;
	}
	result[size] = 0;
	return (result);
}

/*#include <stdio.h>

int main()
{
	int i;
	i = 0;
	char 	*s = "Hello your computer has a virus";
	char 	c = 32;
	char	**result;

	printf("Before : %s\n", s);
	result = ft_split(s, c);
	printf("After : ");
	i = 0;
	while (result[i])
	{
		printf(" %d = %s |", i, result[i]);
		i++;
	}
	return(0);
}*/
