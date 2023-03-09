/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:59 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/09 18:10:51 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map, t_img *img, int x, int y)
{
	map->moves++;
	// write(1, "Player moves : ", 15);
	// if (map->moves < 10)
	// 	write(1, &map->moves, 1);
	// else if (map->moves < 100)
	// 	write(1, &map->moves, 2);
	// else if (map->moves < 1000)
	// 	write(1, &map->moves, 3);
	// else
	// 	write(1, &map->moves, 4);
	// write(1, "\n", 1);
	if (map->map[x][y] == 'C')
		map->collected += 1;
	if (map->map[x][y] == 'E')
		ft_check_win(map, img);
	map->map[x][y] = 'P';
	map->map[x][y + 1] = '0';
	map->p[0] = x;
	map->p[1] = y;
	ft_rep_img(img, img->up, x, y);
}

void	move_down(t_map *map, t_img *img, int x, int y)
{
	map->moves++;
	// write(1, "Player moves : ", 15);
	// if (map->moves < 10)
	// 	write(1, &map->moves, 1);
	// else if (map->moves < 100)
	// 	write(1, &map->moves, 2);
	// else if (map->moves < 1000)
	// 	write(1, &map->moves, 3);
	// else
	// 	write(1, &map->moves, 4);
	// write(1, "\n", 1);
	if (map->map[x][y] == 'C')
		map->collected += 1;
	if (map->map[x][y] == 'E')
		ft_check_win(map, img);
	map->map[x][y] = 'P';
	map->map[x][y - 1] = '0';
	map->p[0] = x;
	map->p[1] = y;
	ft_rep_img(img, img->down, x, y);
}

void	move_left(t_map *map, t_img *img, int x, int y)
{
	map->moves++;
	// write(1, "Player moves : ", 15);
	// if (map->moves < 10)
	// 	write(1, &map->moves, 1);
	// else if (map->moves < 100)
	// 	write(1, &map->moves, 2);
	// else if (map->moves < 1000)
	// 	write(1, &map->moves, 3);
	// else
	// 	write(1, &map->moves, 4);
	// write(1, "\n", 1);
	if (map->map[x][y] == 'C')
		map->collected += 1;
	if (map->map[x][y] == 'E')
		ft_check_win(map, img);
	map->map[x][y] = 'P';
	map->map[x + 1][y] = '0';
	map->p[0] = x;
	map->p[1] = y;
	ft_rep_img(img, img->left, x, y);
}

void	move_right(t_map *map, t_img *img, int x, int y)
{
	map->moves++;
	// printf ("moves = %d\n", map->moves);
	// write(1, "Player moves : ", 15);
	// if (map->moves < 10)
	// 	write(1, &map->moves, 1);
	// else if (map->moves < 100)
	// 	write(1, &map->moves, 2);
	// else if (map->moves < 1000)
	// 	write(1, &map->moves, 3);
	// else
	// 	write(1, &map->moves, 4);
	// write(1, "\n", 1);
	if (map->map[x][y] == 'C')
		map->collected += 1;
	if (map->map[x][y] == 'E')
		ft_check_win(map, img);
	map->map[x][y] = 'P';
	map->map[x - 1][y] = '0';
	map->p[0] = x;
	map->p[1] = y;
	ft_rep_img(img, img->right, x, y);
}

void	ft_rep_img(t_img *img, void *new_img, int x, int y)
{
	x = x * 30;
	y = y * 33;
	if (img->e == 0)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->path, x, y);
	if (img->e == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->path, x, y);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, x, y);
	}
	img->e = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, new_img, x, y);
}
