/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:03:28 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/16 10:42:09 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_gnl(char *str)
{
	char	*resu;
	int		i;
	int		j;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	resu = (char *)malloc(sizeof(char) * (i + 2));
	if (!resu)
		return (NULL);
	j = 0;
	while (j <= i && str[j])
	{
		resu[j] = str[j];
		j++;
	}
	resu[j] = '\0';
	return (resu);
}

char	*next_line(char	*buff)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * ((ft_strlen_gnl(buff) - i) + 1));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (buff[j + i])
	{
		tmp[j] = buff[j + i];
		j++;
	}
	tmp[j] = '\0';
	free(buff);
	return (tmp);
}

char	*read_line(int fd, char *buffer, int buffer_size)
{
	char	*res;
	int		r;

	r = 1;
	res = (char *)malloc(sizeof(char) * buffer_size + 1);
	if (!res)
		return (NULL);
	while (r != 0)
	{
		r = read(fd, res, buffer_size);
		if (r < 0)
		{
			free(res);
			return (NULL);
		}
		res[r] = '\0';
		buffer = ft_strjoin_gnl(buffer, res);
		if (ft_check(buffer, '\n'))
			break ;
	}
	free(res);
	return (buffer);
}

char	*get_next_line(int fd, int buffer_size)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || buffer_size <= 0)
		return (NULL);
	buffer = read_line(fd, buffer, buffer_size);
	if (!buffer)
		return (NULL);
	line = ft_strcpy_gnl(buffer);
	buffer = next_line(buffer);
	return (line);
}
