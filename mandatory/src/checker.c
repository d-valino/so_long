/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:02:13 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/28 18:34:42 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

int	check_wall(char **game)
{
	int		x;
	size_t	count;

	x = 0;
	count = ft_strlen(game[x]);
	while (game[x])
	{
		if (ft_strlen(game[x]) != count)
			return (ft_error("The map must be rectangular\n"));
		x++;
	}
	count = count - 2;
	x = 0;
	while (game[x])
	{
		if (game[x][count] != '1')
			return (ft_error
				("The map must be close/surrounded by walls\n"));
		x++;
	}
	return (1);
}

int	first_last(char **game)
{
	int	y;
	int	x;

	x = -1;
	while (game[++x])
	{
		if (game[x][0] != '1')
			return (ft_error("The map must be close/surrounded by walls\n"));
	}
	y = 0;
	while (game[0][y + 1])
	{
		if (game[0][y] != '1')
			return (ft_error("The map must be close/surrounded by walls\n"));
		y++;
	}
	x--;
	y = 0;
	while (game[x][y + 1])
	{
		if (game[x][y] != '1')
			return (ft_error("The map must be close/surrounded by walls\n"));
		y++;
	}
	return (1);
}

int	unknown_chr(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y + 1])
		{
			if (map[x][y] != '1' && map[x][y] != '0'
				&& map[x][y] != 'P' && map[x][y] != 'C'
				&& map[x][y] != 'E')
				return (ft_error("Unknown Character Found\n"));
			y++;
		}
		x++;
	}
	return (1);
}

int	check_pce(t_map content)
{
	if (content.player == 0)
		return (ft_error("No player's starting position found\n"));
	if (content.player > 1)
		return (ft_error("There is more than one player's starting position\n"));
	if (content.collec == 0)
		return (ft_error("No Collectibles Found\n"));
	if (content.exit == 0)
		return (ft_error("No Exit Found\n"));
	if (content.exit > 1)
		return (ft_error("There is more than one exit\n"));
	return (1);
}

int	checker(t_data data)
{
	char	**game;

	if (!check_pce(data.content))
		return (0);
	if (!first_last(data.map))
		return (0);
	if (!check_wall(data.map))
		return (0);
	if (!unknown_chr(data.map))
		return (0);
	game = ft_split(data.copy_map, '\n');
	valid_path(data.pos_y, data.pos_x, game, &data);
	free_only_map(game);
	if (data.content.collec_count != 0 || data.content.exit_count != 0)
		return (ft_error("No valid path to collects/exit\n"));
	return (1);
}
