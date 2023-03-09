/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:08:56 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/09 18:24:33 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keycode(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
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

// int	ft_collected(t_map *map)
// {
	
// }

void	ft_find_p(t_map *map, int i, int j)
{
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->p[0] = j;
				map->p[1] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_moves(t_data *data, int keycode)
{
	// t_map	*map;
	// t_img	*img

	// map = data->map;
	// img = data->img;
	//printf("map->p[0] = %d, map->p[1] = %d\n", map->p[0], map->p[1]);
	ft_find_p(data->map, 0, 0);
	if (keycode == W && data->map->map[(data->map->p[0]) - 1][data->map->p[1]] != '1')
		move_up(data->map, data->img, data->map->p[0], data->map->p[1]);
	if (keycode == S && data->map->map[(data->map->p[0]) + 1][data->map->p[1]] != '1')
		move_down(data->map, data->img, data->map->p[0], data->map->p[1]);
	if (keycode == D && data->map->map[data->map->p[0]][data->map->p[1] + 1] != '1')
		move_right(data->map, data->img, data->map->p[0], data->map->p[1]);
	if (keycode == A && data->map->map[data->map->p[0]][data->map->p[1] - 1] != '1')
		move_left(data->map, data->img, data->map->p[0], data->map->p[1]);
	// if (ft_collected(map) == 1 && map->map[map->p[0]][map->p[1]] == 'E')
	// 	ft_win(map, img);
}

