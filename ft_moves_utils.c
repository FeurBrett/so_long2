/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:59 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 18:47:57 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int x, int y)
{
	data->map->moves++;
	print_moves("moves : ", data->map->moves, data);
	if (data->map->map[y - 1][x] == 'C')
		data->map->collected += 1;
	if (data->map->map[y - 1][x] == 'E')
	{
		ft_check_win(data->map);
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->path, x * 30, y * 33);
	}
	else
		data->map->map[y - 1][x] = 'P';
	if (data->map->map[y][x] == 'E')
		data->map->map[y][x] = 'E';
	else
		data->map->map[y][x] = '0';
	data->map->p[0] = y;
	data->map->p[1] = x;
	ft_rep_img(data, data->img->up, x, y - 1);
}

void	move_down(t_data *data, int x, int y)
{
	data->map->moves++;
	print_moves("moves : ", data->map->moves, data);
	if (data->map->map[y + 1][x] == 'C')
		data->map->collected += 1;
	if (data->map->map[y + 1][x] == 'E')
	{
		ft_check_win(data->map);
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->path, x * 30, y * 33);
	}
	else
		data->map->map[y + 1][x] = 'P';
	if (data->map->map[y][x] == 'E')
		data->map->map[y][x] = 'E';
	else
		data->map->map[y][x] = '0';
	data->map->p[0] = y;
	data->map->p[1] = x;
	ft_rep_img(data, data->img->down, x, y + 1);
}

void	move_left(t_data *data, int x, int y)
{
	data->map->moves++;
	print_moves("moves : ", data->map->moves, data);
	if (data->map->map[y][x - 1] == 'C')
		data->map->collected += 1;
	if (data->map->map[y][x - 1] == 'E')
	{
		ft_check_win(data->map);
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->path, x * 30, y * 33);
	}
	else
		data->map->map[y][x - 1] = 'P';
	if (data->map->map[y][x] == 'E')
		data->map->map[y][x] = 'E';
	else
		data->map->map[y][x] = '0';
	data->map->p[0] = y;
	data->map->p[1] = x;
	ft_rep_img(data, data->img->left, x - 1, y);
}

void	move_right(t_data *data, int x, int y)
{
	data->map->moves++;
	print_moves("moves : ", data->map->moves, data);
	if (data->map->map[y][x + 1] == 'C')
		data->map->collected += 1;
	if (data->map->map[y][x + 1] == 'E')
	{
		ft_check_win(data->map);
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->path, x * 30, y * 33);
	}
	else
		data->map->map[y][x + 1] = 'P';
	if (data->map->map[y][x] == 'E')
		data->map->map[y][x] = 'E';
	else
		data->map->map[y][x] = '0';
	data->map->p[0] = y;
	data->map->p[1] = x;
	ft_rep_img(data, data->img->right, x + 1, y);
}

void	ft_rep_img(t_data *data, void *new_img, int x, int y)
{
	int	i;
	int	j;

	i = data->map->p[1] * 30;
	j = data->map->p[0] * 33;
	x = x * 30;
	y = y * 33;
	if (data->map->map[data->map->p[0]][data->map->p[1]] == 'E')
	{
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->path, i, j);
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->exit, i, j);
	}
	else
		mlx_put_image_to_window(data->img->mlx, data->img->mlx_win,
			data->img->path, i, j);
	mlx_put_image_to_window(data->img->mlx, data->img->mlx_win, new_img, x, y);
}
