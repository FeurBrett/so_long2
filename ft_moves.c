/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:08:56 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 17:36:05 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keycode(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_free(data->map->map);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W)
		ft_moves(data, keycode);
	else if (keycode == S)
		ft_moves(data, keycode);
	else if (keycode == D)
		ft_moves(data, keycode);
	else if (keycode == A)
		ft_moves(data, keycode);
	return (0);
}

void	ft_find_p(t_map *map, int i, int j)
{
	int	x;

	x = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->p[1] = i;
				map->p[0] = j;
				x = 1;
			}
			j++;
		}
		i++;
	}
	if (x == 0)
		ft_find_e(map, 0, 0);
}

void	ft_find_e(t_map *map, int i, int j)
{
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				map->p[1] = i;
				map->p[0] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_moves(t_data *data, int keycode)
{
	ft_find_p(data->map, 0, 0);
	if (keycode == W
		&& data->map->map[(data->map->p[1]) - 1][data->map->p[0]] != '1')
		move_up(data, data->map->p[0], data->map->p[1]);
	if (keycode == S
		&& data->map->map[(data->map->p[1]) + 1][data->map->p[0]] != '1')
		move_down(data, data->map->p[0], data->map->p[1]);
	if (keycode == D
		&& data->map->map[data->map->p[1]][data->map->p[0] + 1] != '1')
		move_right(data, data->map->p[0], data->map->p[1]);
	if (keycode == A
		&& data->map->map[data->map->p[1]][data->map->p[0] - 1] != '1')
		move_left(data, data->map->p[0], data->map->p[1]);
}
