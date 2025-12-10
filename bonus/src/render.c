/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:42:06 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/30 11:42:09 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

void	ft_collect(t_data *data)
{
	data->content.collec--;
	ft_putstr_fd("Collectible +1\n", 1);
	ft_putstr_fd("--------------------------\n", 1);
	ft_putnbr_fd(data->content.collec, 1);
	ft_putstr_fd(" collectibles left\n", 1);
	ft_putchar_fd('\n', 1);
	if (data->content.collec == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		data->img.exit = "./textures/exit_open_texture.xpm";
		data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.exit, &(data->img.width), &(data->img.height));
	}
}

void	pos_change(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'E' && data->content.collec != 0)
		return ;
	else if (data->map[x][y] == 'C')
		ft_collect(data);
	if (data->map[x][y] == 'X')
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	if (data->map[x][y] == 'E' && data->content.collec == 0)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	data->map[x][y] = 'P';
	data->map[data->pos_x][data->pos_y] = '0';
	data->pos_x = x;
	data->pos_y = y;
	data->count++;
}

int	handle_keypress(int keysym, t_data *data)
{
	data->enemy.enemy_move = 1;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	else if (keysym == XK_a || keysym == XK_Left)
		move_left(data, data->pos_x, data->pos_y - 1);
	else if (keysym == XK_w || keysym == XK_Up)
		move_up(data, data->pos_x - 1, data->pos_y);
	else if (keysym == XK_s || keysym == XK_Down)
		move_down(data, data->pos_x + 1, data->pos_y);
	else if (keysym == XK_d || keysym == XK_Right)
		move_right(data, data->pos_x, data->pos_y + 1);
	return (0);
}

void	render_game(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		img, data->img.width * x, data->img.height * y);
}
