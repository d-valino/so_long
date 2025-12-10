/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:08:01 by dvalino-          #+#    #+#             */
/*   Updated: 2023/05/15 15:15:20 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_is_sep(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && c_is_sep((char *)set, s1[i]))
		i++;
	while (len > i && c_is_sep((char *)set, s1[len - 1]))
		len--;
	cpy = (char *)malloc(sizeof(*s1) * ((len - i) + 1));
	if (!(cpy))
		return (NULL);
	j = 0;
	while (i < len)
		cpy[j++] = s1[i++];
	cpy[j] = '\0';
	return (cpy);
}
