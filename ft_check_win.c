/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:09:46 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 12:30:57 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_map *map, t_img *img)
{
	map->h = map->h;
	img->e = 0;
	write(1, "Congratulations ! You won\n", 26);
	exit(EXIT_SUCCESS);
}

void	ft_check_win(t_map *map, t_img *img)
{
	img->e = 1;
	printf("coins = %d collected = %d\n", map->coins, map->collected);
	if (map->coins == map->collected)
		ft_win(map, img);
}
