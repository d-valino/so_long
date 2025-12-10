/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:47:24 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/26 16:04:19 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

void	setcont(t_map *content)
{
	content->player = 0;
	content->collec = 0;
	content->exit = 0;
}

void	setimg(t_data *data)
{
	data->count = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->enemy.enemy_count = 0;
	data->enemy.enemy_move = 0;
	data->img.height = 80;
	data->img.width = 80;
	data->enemy.monster = "./textures/monster_texture.xpm";
	data->img.collect = "./textures/collect_texture.xpm";
	data->img.exit = "./textures/exit_close_texture.xpm";
	data->img.floor = "./textures/floor_texture.xpm";
	data->img.player = "./textures/player/Playerhero_stay_right.xpm";
	data->img.wall = "./textures/wall_texture.xpm";
	data->enemy.img_monster = mlx_xpm_file_to_image(data->mlx_ptr,
			data->enemy.monster, &(data->img.width), &(data->img.height));
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}

void	calcule_map(t_data *data, int fd)
{
	char	*buff;
	char	*tmp;

	buff = NULL;
	while (1)
	{
		tmp = get_next_line(fd, 10);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		buff = ft_strjoin_gnl(buff, tmp);
		free(tmp);
	}
	if (!buff)
	{
		ft_error("Map empty\n");
		exit (0);
	}
	data->copy_map = ft_strdup(buff);
	free(buff);
	data->map = ft_split(data->copy_map, '\n');
}

void	read_map(char **game, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (game[x])
	{
		y = 0;
		while (game[x][y])
		{
			if (game[x][y] == 'C')
				data->content.collec++;
			if (game[x][y] == 'P')
				data->content.player++;
			if (game[x][y] == 'E')
				data->content.exit++;
			if (game[x][y] == 'X')
				data->enemy.enemy_count++;
			y++;
		}
		x++;
	}
	data->content.collec_count = data->content.collec;
	data->content.exit_count = data->content.exit;
	data->height = x;
}

void	ft_set(t_data *data)
{
	setimg(data);
	setcont(&(data->content));
	read_map(data->map, data);
	data->width = ft_strlen(data->map[0]) - 1;
}
