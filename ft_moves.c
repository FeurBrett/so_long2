/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:08:56 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/08 17:05:32 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_p(t_map *map, int i, int j)
{
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->p[0] = i;
				map->p[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_moves(t_map *map, t_img *img, int keycode)
{
	if (keycode == W && map->map[(map->p[0]) - 1][map->p[1]] != '1')
		move_up(map, img, map->p[0], map->p[1]);
	if (keycode == S && map->map[(map->p[0]) + 1][map->p[1]] != '1')
		move_down(map, img, map->p[0], map->p[1]);
	if (keycode == D && map->map[map->p[0]][map->p[1] + 1] != '1')
		move_right(map, img, map->p[0], map->p[1]);
	if (keycode == A && map->map[map->p[0]][map->p[1] - 1] != '1')
		move_left(map, img, map->p[0], map->p[1]);
	if (ft_collected(map) == 1 && map->map[map->p[0]][map->p[1]] == 'E')
		ft_win(map, img);
}
