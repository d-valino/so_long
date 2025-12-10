/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:16:59 by dvalino-          #+#    #+#             */
/*   Updated: 2023/05/15 15:17:11 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char const *src, int len)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len = len + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str = ft_strcat(str, s1, 0);
	str = ft_strcat(str, s2, (ft_strlen(s1)));
	str[len] = '\0';
	return (str);
}
// #include<stdio.h>

// int	main(void)
// {
// 	char	*strs[3];
// 	char	*new;

// 	strs[0] = "Hello";
// 	strs[1] = "Salut";
// 	strs[2] = "Holaa";

// 	new = ft_strjoin(strs[0], strs[1]);
// 	printf("%s\n", new);
// 	free(new);
// 	return (0);
// }
