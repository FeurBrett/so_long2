/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:27:56 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/09 17:36:15 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	char	*txt;

	if (argc > 2)
		ft_error_map(8);
	fd = open(argv[1], O_RDONLY);
	ft_check_ber(argv[1]);
	txt = ft_readmap(fd);
	ft_init_map(&map);
	ft_fill_map(&map, txt);
	ft_parsemap(&map);
	so_long(&map);
	return (0);
}

void	so_long(t_map *map)
{
	t_img	img;
	t_data	data;

	ft_init_img(&img, map);
	ft_fill_img(&img);
	ft_loop_map(&img, map);
	ft_fill_data(&data, &img, map);
	mlx_hook(img.mlx_win, 17, 0, &red_cross, &img);
	mlx_hook(img.mlx_win, 2, 0, &ft_keycode, &data);
	mlx_loop(img.mlx);
}

void	ft_loop_map(t_img	*img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && map->map)
		{
			ft_put_img(img, map->map[i][j], map);
			if (map->map[i][j] == 'P')
			{
				map->x = j;
				map->y = i;
			}
			j++;
			map->w += 30;
		}
		i++;
		map->h += 33;
		map->w = 0;
	}
}

// faire les mouvements individuellement
// encoder les key values dans le .h
// parser le chemin voir s'il est faisable
