/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:07:37 by dvalino-          #+#    #+#             */
/*   Updated: 2023/05/12 14:17:21 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_makenbr(int neg, char *num, long nbr, int len)
{
	int	i;

	i = 0;
	num[len] = '\0';
	ft_memset(num, 1, len);
	len--;
	if (neg < 0)
	{
		num[0] = '-';
		nbr = -nbr;
		i++;
		len++;
	}
	while (num[i] != '\0')
	{
		num[len - i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		neg;
	int		len;
	long	nbr;

	neg = 1;
	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		neg = -neg;
		len++;
	}
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	num = malloc(sizeof(char) * len + 1);
	if (!(num))
		return (NULL);
	return (ft_makenbr(neg, num, n, len));
}
