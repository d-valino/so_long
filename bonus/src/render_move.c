/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:01:36 by dvalino-          #+#    #+#             */
/*   Updated: 2023/07/05 13:01:40 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

void	move_left(t_data *data, int x, int y)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = "./textures/player/Playerhero_left.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	pos_change(data, x, y);
}

void	move_right(t_data *data, int x, int y)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = "./textures/player/Playerhero_right.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	pos_change(data, x, y);
}

void	move_down(t_data *data, int x, int y)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = "./textures/player/Playerhero_down.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	pos_change(data, x, y);
}

void	move_up(t_data *data, int x, int y)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = "./textures/player/Playerhero_up.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	pos_change(data, x, y);
}
