/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:40:22 by dvalino-          #+#    #+#             */
/*   Updated: 2023/06/26 15:38:06 by dvalino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../lib/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define MLX_ERROR 1

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*floor;
	char	*player;
	char	*exit;
	char	*wall;
	char	*collect;
}				t_img;

typedef struct map_s
{
	int	player;
	int	collec;
	int	exit;

	int	collec_count;
	int	exit_count;
}				t_map;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	char	*copy_map;
	t_map	content;
	t_img	img;
	int		pos_x;
	int		pos_y;
	int		count;

}				t_data;

void	free_map(t_data *data);
void	free_only_map(char **map);
int		end(t_data *data);
int		check_sprites(int *re);
int		checker(t_data data);
void	valid_path(int y, int x, char **map, t_data *data);
void	ft_set(t_data *data);
void	setcont(t_map *content);
void	setimg(t_data *data);
void	calcule_map(t_data *game, int fd);
int		count_lines(char *line);
void	found_player(char **game, t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	render_game(t_data *data, void *img, int x, int y);
int		render_map(t_data *data);
void	pos_change(t_data *data, int x, int y);
void	move_left(t_data *data, int x, int y);
void	move_right(t_data *data, int x, int y);
void	move_down(t_data *data, int x, int y);
void	move_up(t_data *data, int x, int y);
int		close_window(t_data *data);
int		ft_error(char *str);

#endif
