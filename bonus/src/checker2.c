/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:57:11 by dvalino-          #+#    #+#             */
/*   Updated: 2023/07/03 10:57:12 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

int	check_sprites2(int *re)
{
	*re = open("./textures/exit_open_texture.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/player/Playerhero_up.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/player/Playerhero_left.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/player/Playerhero_right.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/player/Playerhero_stay_left.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/player/Playerhero_stay_right.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	return (close(*re), 1);
}

int	check_sprites(int *re)
{
	*re = open("./textures/collect_texture.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/exit_close_texture.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/floor_texture.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/player/Playerhero_down.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	close(*re);
	*re = open("./textures/wall_texture.xpm", O_RDONLY);
	if (*re == -1)
		return (close(*re), ft_error("Couldn't found an sprite file\n"));
	*re = close(*re);
	if (!check_sprites2(re))
		return (0);
	return (1);
}

void	found_player(char **game, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (game[x])
	{
		y = 0;
		while (game[x][y])
		{
			if (game[x][y] == 'P')
			{
				data->pos_x = x;
				data->pos_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	valid_path(int y, int x, char **map, t_data *data)
{
	if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'F')
	{
		if (map[x][y] == 'E')
			data->content.exit_count = 0;
		return ;
	}
	if (map[x][y] == 'C')
		data->content.collec_count--;
	map[x][y] = 'F';
	valid_path(y - 1, x, map, data);
	valid_path(y, x - 1, map, data);
	valid_path(y + 1, x, map, data);
	valid_path(y, x + 1, map, data);
}

int	count_lines(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			count++;
		i++;
	}
	if (line[i] == '\0')
		count++;
	return (count);
}
