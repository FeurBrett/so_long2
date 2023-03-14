/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:58:49 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/14 11:44:44 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_readmap(int fd)
{
	int		i;
	char	*map;
	char	buffer[2];

	i = 1;
	map = NULL;
	while (i != 0)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
			ft_error_map(6);
		buffer[i] = '\0';
		map = ft_strjoin(map, buffer);
		if (!map)
			ft_error_map(6);
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			ft_error_map(5);
		i++;
	}
	return (map);
}

void	ft_fill_map(t_map *map, char *txt)
{
	int	len;
	int	c;

	len = 0;
	c = 0;
	while (txt[len] != '\n' && txt[len])
		len++;
	map->w = 0;
	map->h = 0;
	map->x = 0;
	map->y = 0;
	map->l = len;
	map->map = ft_split(txt, '\n');
	map->p[0] = 0;
	map->p[1] = 0;
	map->moves = 0;
	map->coins = 0;
	map->collected = 0;
	while (map->map[c])
		c++;
	map->width = len * 30;
	map->height = (c) * 33;
}

void	ft_check_if_rect(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != j)
			ft_error_map(2);
		i++;
	}
}

void	check_characters(t_map *map, int e, int p)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'C')
				map->coins++;
			else if (map->map[j][i] == 'E')
				e++;
			else if (map->map[j][i] == 'P')
				p++;
			else if (map->map[j][i] != '0' && map->map[j][i] != '1'
				&& map->map[j][i] != 'X')
				ft_error_map(1);
			i++;
		}
		j++;
	}
	if (map->coins < 1 || p != 1 || e != 1)
		ft_error_map(3);
}

void	ft_parsemap(t_map *map)
{
	int		c;

	c = (map->height / 33);
	ft_check_if_rect(map);
	check_characters(map, 0, 0);
	ft_check_borders(map, c);
}
