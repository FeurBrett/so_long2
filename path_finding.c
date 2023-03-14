/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:19:31 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/14 11:10:52 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_cpy(t_map *data)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (data->height / 33 + 1));
	if (!map)
		return (NULL);
	while (i < data->height / 33)
	{
		map[i] = ft_strdup(data->map[i]);
		if (!map[i++])
		{
			ft_error_map(1);
		}
	}
	map[i] = NULL;
	return (map);
}

void	pre_path_finding(t_map *data)
{
	t_path	path;
	char	**map;
	int		i;
	int		j;
	int		res;

	map = map_cpy(data);
	i = data->y;
	j = data->x;
	path.collectable = data->coins;
	path.exit = 1;
	res = path_finding(map, i, j, &path);
	ft_free(map);
	if (res != 1)
		ft_error_map(1);
}

int	path_finding(char **map, int i, int j, t_path *path)
{
	if (map)
	{
		if (map[i][j] == '1' || map[i][j] == 'X')
			return (0);
		if (map[i][j] == 'C')
			path->collectable--;
		if (map[i][j] == 'E')
			path->exit--;
		map[i][j] = '1';
		(path_finding(map, i + 1, j, path)
			|| path_finding(map, i - 1, j, path)
			|| path_finding(map, i, j + 1, path)
			|| path_finding(map, i, j - 1, path));
		return (path->collectable == 0 && path->exit == 0);
	}
	return (0);
}
