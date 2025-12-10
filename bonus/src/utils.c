/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:49:48 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/27 18:50:02 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	return (0);
}

int	end(t_data *data)
{
	if (data != 0)
	{
		if (data->enemy.img_monster != 0)
			mlx_destroy_image(data->mlx_ptr, data->enemy.img_monster);
		if (data->img.img_collect != 0)
			mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		if (data->img.img_exit != 0)
			mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		if (data->img.img_floor != 0)
			mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		if (data->img.img_player != 0)
			mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		if (data->img.img_wall != 0)
			mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		if (data->mlx_ptr != 0)
			mlx_destroy_display(data->mlx_ptr);
		if (data->copy_map != 0)
			free(data->copy_map);
		if (data->map != 0)
			free_map(data);
		free (data->mlx_ptr);
	}
	return (0);
}

void	free_map(t_data *data)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (data->map[i])
		i++;
	while (x < i)
	{
		free(data->map[x]);
		x++;
	}
	free(data->map);
	data->map = NULL;
	return ;
}

void	free_only_map(char **map)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (map[i])
		i++;
	while (x < i)
	{
		free(map[x]);
		x++;
	}
	free(map);
	map = NULL;
	return ;
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	data->mlx_win = NULL;
	end(data);
	return (exit(0), 0);
}
