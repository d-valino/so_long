/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:13:32 by dvalino-          #+#    #+#             */
/*   Updated: 2023/05/15 12:22:34 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "tripouille";
  char * pch;
  printf ("Looking for the ''t' + 256' character in \"%s\"...\n",str);
  pch = ft_strchr(str,'t');
  while (pch!=NULL)
  {
    printf ("found at %ld\n",pch-str+1);
    pch = ft_strchr(pch+1,'t');
  }
  return 0;
}
*/
