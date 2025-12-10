/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:55:48 by dvalino-          #+#    #+#             */
/*   Updated: 2023/07/06 16:55:52 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

void	found_enemy(char **game, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (game[x])
	{
		y = 0;
		while (game[x][y])
		{
			if (game[x][y] == 'X')
			{
				data->enemy.pos_x = x;
				data->enemy.pos_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	pos_change_enemy(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'E')
		return ;
	else if (data->map[x][y] == 'C')
		return ;
	if (data->map[x][y] == 'P')
	{
		data->map[x][y] = 'X';
		data->map[data->enemy.pos_x][data->enemy.pos_y] = '0';
		data->enemy.pos_x = x;
		data->enemy.pos_y = y;
		render_map(data);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	data->map[x][y] = 'X';
	data->map[data->enemy.pos_x][data->enemy.pos_y] = '0';
	data->enemy.pos_x = x;
	data->enemy.pos_y = y;
}

void	ft_enemy(t_data *data)
{
	found_enemy(data->map, data);
	if (((data->count % 3) == 0 && (data->count % 5) == 0)
		|| (data->count % 7) == 0)
	{
		pos_change_enemy(data, data->enemy.pos_x - 1, data->enemy.pos_y);
		return ;
	}
	if ((data->count % 3) == 0)
	{
		pos_change_enemy(data, data->enemy.pos_x + 1, data->enemy.pos_y);
		return ;
	}
	if ((data->count % 5) == 0 || (data->count % 2) == 0)
	{
		pos_change_enemy(data, data->enemy.pos_x, data->enemy.pos_y - 1);
		return ;
	}
	if ((data->count % 2) != 0)
	{
		pos_change_enemy(data, data->enemy.pos_x, data->enemy.pos_y + 1);
		return ;
	}
}
