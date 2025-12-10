/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:09:20 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/16 10:45:50 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat_gnl(char *dest, char const *src, int len)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		len;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_gnl(s1);
	len = len + ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str = ft_strcat_gnl(str, s1, 0);
	str = ft_strcat_gnl(str, s2, (ft_strlen_gnl(s1)));
	str[len] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dest;
	size_t	len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen_gnl(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}
