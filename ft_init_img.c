/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:28:57 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 15:00:27 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_img *img, t_map *map)
{
	img->left = NULL;
	img->right = NULL;
	img->up = NULL;
	img->down = NULL;
	img->exit = NULL;
	img->collect = NULL;
	img->path = NULL;
	img->wall = NULL;
	img->mlx = NULL;
	img->mlx_win = NULL;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, map->width, map->height, "So Long");
}

void	ft_fill_img(t_img *img)
{
	int	a;
	int	b;

	img->left = mlx_xpm_file_to_image(img->mlx, "./salam4.xpm", &a, &b);
	img->right = mlx_xpm_file_to_image(img->mlx, "./salam3.xpm", &a, &b);
	img->up = mlx_xpm_file_to_image(img->mlx, "./salam2.xpm", &a, &b);
	img->down = mlx_xpm_file_to_image(img->mlx, "./salam1.xpm", &a, &b);
	img->collect = mlx_xpm_file_to_image(img->mlx, "./pika.xpm", &a, &b);
	img->exit = mlx_xpm_file_to_image(img->mlx, "./exit.xpm", &a, &b);
	img->path = mlx_xpm_file_to_image(img->mlx, "./path.xpm", &a, &b);
	img->wall = mlx_xpm_file_to_image(img->mlx, "./wall.xpm", &a, &b);
	if (!img->wall || !img->left || !img->right || !img->exit || !img->collect
		|| !img->path || !img->up || !img->down)
	{
		ft_destroy_img(img);
		ft_error_map(9);
	}
}

void	ft_put_img(t_img *i, char a, t_map *m)
{
	if (a == '1')
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->wall, m->w, m->h);
	if (a == '0' || a == 'P' || a == 'E' || a == 'C')
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->path, m->w, m->h);
	if (a == 'P')
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->down, m->w, m->h);
	if (a == 'E')
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->exit, m->w, m->h);
	if (a == 'C')
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->collect, m->w, m->h);
}

void	ft_destroy_img(t_img *img)
{
	if (img->collect)
		mlx_destroy_image(img->mlx, img->collect);
	if (img->left)
		mlx_destroy_image(img->mlx, img->left);
	if (img->path)
		mlx_destroy_image(img->mlx, img->path);
	if (img->right)
		mlx_destroy_image(img->mlx, img->right);
	if (img->wall)
		mlx_destroy_image(img->mlx, img->wall);
	if (img->up)
		mlx_destroy_image(img->mlx, img->up);
	if (img->down)
		mlx_destroy_image(img->mlx, img->down);
	if (img->exit)
		mlx_destroy_image(img->mlx, img->collect);
}
