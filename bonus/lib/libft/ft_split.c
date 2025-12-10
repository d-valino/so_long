/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:33:06 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/26 12:30:11 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*copystr(char const *origin, char *dest, int start, int end)
{
	int	k;
	int	i;
	int	diff;

	diff = end - start;
	dest = malloc(sizeof(char) * (diff + 2));
	if (!(dest))
		return (NULL);
	k = start;
	i = 0;
	while (k < end)
	{
		dest[i] = origin[k];
		i++;
		k++;
	}
	dest[i] = '\n';
	i++;
	dest[i] = '\0';
	return (dest);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (s[i])
			count++;
		while (!(c == s[i]) && s[i])
			i++;
	}
	return (count);
}

static	int	ft_ini(char const *s, char c, int *i, int *index)
{
	*index = -1;
	*i = 0;
	return (count_words((char *)s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		index;
	int		start;
	int		words;

	if (!s)
		return (NULL);
	words = ft_ini(s, c, &i, &index);
	split = malloc(sizeof(char *) * (words + 1));
	if (!(split))
		return (NULL);
	while (s[i] && ++index < words)
	{
		while ((c == s[i]) && s[i])
			i++;
		start = i;
		while ((!(c == s[i])) && s[i])
			i++;
		split[index] = copystr(s, split[index], start, i);
		if (!(split[index]))
			return (free_all(split));
	}
	split[words] = 0;
	return (split);
}
/*
#include <stdio.h>

int	main()
{
	char	**split;
	int	i;

	i = 0;
	split = ft_split("Hello\nmon\nami\n", '\n');
	while (i < 3)
	{
		printf("%s", split[i]);
		i++;
	}
	split = free_all(split);
	return (0);
}
*/
