/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:00:30 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/26 15:16:03 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init.h"

void	init(t_data *data, int *fd)
{
	calcule_map(data, *fd);
	data->mlx_ptr = mlx_init();
	ft_set(data);
	found_player(data->map, data);
	*fd = close(*fd);
}

int	check_arg(int argc, char **argv, int *fd)
{
	if (argc != 2)
		return (ft_error(""));
	if (!(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))))
		return (ft_error("Bad format map\n"));
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		return (ft_error("Problem opening the map or bad format map\n"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	int		re;

	if (!(check_arg(argc, argv, &fd)) || !check_sprites(&re))
		return (0);
	init(&data, &fd);
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	if (checker(data))
	{
		data.mlx_win = mlx_new_window(data.mlx_ptr,
				(data.width * data.img.width),
				(data.height * data.img.height), "so_long");
		if (data.mlx_win == NULL)
		{
			free(data.mlx_win);
			return (MLX_ERROR);
		}
		mlx_loop_hook(data.mlx_ptr, &render_map, &data);
		mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.mlx_win, DestroyNotify, 0, &close_window, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (end(&data));
}
