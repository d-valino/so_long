/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:05:56 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/16 10:45:16 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_gnl(const char *s);
char	*ft_strcat_gnl(char *dest, char const *src, int len);
char	*ft_strjoin_gnl(char *s1, char const *s2);
int		ft_check(char *str, char c);
char	*ft_strdup_gnl(const char *s);
char	*get_next_line(int fd, int buffer_size);

#endif
