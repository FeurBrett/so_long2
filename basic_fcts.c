/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:22:46 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 18:50:07 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_free(char **map)
{
	int	e;

	e = -1;
	while (map[++e])
		free(map[e]);
	free(map);
}

void	*print_moves(char *a, int b, t_data *d)
{
	char	*newchar;
	char	*c;

	c = ft_strdup(a);
	newchar = ft_strjoin(c, ft_itoa(b));
	mlx_put_image_to_window(d->img->mlx, d->img->mlx_win,
		d->img->wall, 0, 0);
	mlx_put_image_to_window(d->img->mlx, d->img->mlx_win,
		d->img->wall, 30, 0);
	mlx_put_image_to_window(d->img->mlx, d->img->mlx_win,
		d->img->wall, 60, 0);
	mlx_string_put(d->img->mlx, d->img->mlx_win, 10, 10, 0xFFFFFF, newchar);
	return (newchar);
}
