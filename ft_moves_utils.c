/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:59 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 10:19:33 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map, t_img *img, int x, int y)
{
	printf("move up\n");
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
	if (map->map[y][x] == 'C')
		map->collected += 1;
	if (map->map[y][x] == 'E')
		ft_check_win(map, img);
	map->map[y - 1][x] = 'P';
	map->map[y][x] = '0';
	map->p[0] = y;
	map->p[1] = x;
	ft_rep_img(img, img->up, x, y);
}

void	move_down(t_map *map, t_img *img, int x, int y)
{
	printf("move down\n");
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
	if (map->map[y][x] == 'C')
		map->collected += 1;
	if (map->map[y][x] == 'E')
		ft_check_win(map, img);
	map->map[y + 1][x] = 'P';
	map->map[y][x] = '0';
	map->p[0] = y;
	map->p[1] = x;
	ft_rep_img(img, img->down, x, y + 1);
}

void	move_left(t_map *map, t_img *img, int x, int y)
{
		printf("move left\n");
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
	if (map->map[y][x] == 'C')
		map->collected += 1;
	if (map->map[y][x] == 'E')
		ft_check_win(map, img);
	map->map[y][x - 1] = 'P';
	map->map[y][x] = '0';
	map->p[0] = y;
	map->p[1] = x;
	ft_rep_img(img, img->left, x, y);
}

void	move_right(t_map *map, t_img *img, int x, int y)
{
	printf("move right\n");
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
	if (map->map[y][x] == 'C')
		map->collected += 1;
	if (map->map[y][x] == 'E')
		ft_check_win(map, img);
	map->map[y][x + 1] = 'P';
	map->map[y][x] = '0';
	map->p[0] = y;
	map->p[1] = x;
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
