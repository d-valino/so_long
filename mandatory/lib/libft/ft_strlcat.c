/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:39:17 by dvalino-          #+#    #+#             */
/*   Updated: 2023/05/15 12:23:55 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;
	size_t	lsrc;

	if (!dst && size == 0)
		return (ft_strlen(src));
	ldest = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size <= ldest)
		return (lsrc + size);
	i = 0;
	while (i + ldest < size - 1 && src[i])
	{
		dst[ldest + i] = src[i];
		i++;
	}
	dst[ldest + i] = '\0';
	return (ldest + lsrc);
}

// #include <bsd/string.h>
// #include<stdio.h>

// int	main()
// {
// 	char	dst[] = "Dan";
// 	char	src[] = "456";

// 	unsigned int	n;

// 	printf("src : %s\n", src);
// 	printf("dst : %s\n", dst);

// 	n = strlcat(dst, src, 3);

// 	printf("n : %d\n", n);
// 	printf("dst : %s\n", dst);
// }
