/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:09:46 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 17:00:04 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(int i, t_map *map)
{
	i = -1;
	write(1, "Congratulations ! You won\n", 26);
	ft_free(map->map);
	exit(EXIT_SUCCESS);
}

void	ft_check_win(t_map *map)
{
	printf("coins = %d collected = %d\n", map->coins, map->collected);
	if (map->coins == map->collected)
		ft_win(0, map);
}
