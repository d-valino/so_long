/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:36:19 by dvalino-          #+#    #+#             */
/*   Updated: 2023/07/02 15:36:21 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

void	print_img(t_data *data, char c, int x, int y)
{
	if (c == '1')
		render_game(data, data->img.img_wall, x, y);
	else if (c == '0')
		render_game(data, data->img.img_floor, x, y);
	else if (c == 'C')
		render_game(data, data->img.img_collect, x, y);
	else if (c == 'E')
		render_game(data, data->img.img_exit, x, y);
	else if (c == 'P')
		render_game(data, data->img.img_player, x, y);
}

int	render_map(t_data *data)
{
	int	x;
	int	y;

	if (!data->mlx_win)
		return (1);
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			print_img(data, data->map[x][y], y, x);
			y++;
		}
		x++;
	}
	return (0);
}
