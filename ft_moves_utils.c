/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:59 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/08 17:06:35 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map, t_img *img, int x, int y)
{
	map->moves++;
	write(1, "Player moves : ", 15);
	write(1, &map->moves, 4);
	write(1, "\n", 1);
	if (map->map[x][y] == 'C')
		map->coins += 1;
	
}

void	move_down(t_map *map, t_img *img, int x, int y)
{

}

void	move_left(t_map *map, t_img *img, int x, int y)
{

}

void	move_right(t_map *map, t_img *img, int x, int y)
{
	
}