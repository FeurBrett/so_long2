/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:27:51 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/01 14:59:47 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkwalls(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != '1')
			ft_error_map(4);
		i++;
	}
}

void	ft_check_borders(t_map *map, int c)
{
	int	i;

	i = 1;
	ft_checkwalls(map->map[0]);
	while (i < (c - 1))
	{
		if (map->map[i][0] != '1')
			ft_error_map(4);
		if (map->map[i][(map->l) - 1] != '1')
			ft_error_map(4);
		i++;
	}
	ft_checkwalls(map->map[c - 1]);
}

void	ft_check_ber(char *n)
{
	int	l;

	l = ft_strlen(n) - 4;
	if (n[l] != '.' || n[l + 1] != 'b' || n[l + 2] != 'e' || n[l + 3] != 'r')
		ft_error_map(0);
}

void	ft_init_map(t_map *map)
{
	map->h = 0;
	map->w = 0;
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->l = 0;
}
