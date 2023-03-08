/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:30:01 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/08 17:07:00 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

// def keys

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// structures

typedef struct s_map
{
	char	**map;
	int		h;
	int		w;
	int		width;
	int		height;
	int		l;
	int		x;
	int		y;
	int		p[2];
	int		moves;
	int		coins;
}	t_map;

typedef struct s_img
{
	void	*left;
	void	*right;
	void	*up;
	void	*down;
	void	*exit;
	void	*collect;
	void	*path;
	void	*wall;
	void	*mlx;
	void	*mlx_win;
}	t_img;

typedef struct s_data
{
	t_map	*map;
	t_img	*img;
}	t_data;

// Map functions

void	ft_check_ber(char *n);
char	*ft_readmap(int fd);
void	ft_init_map(t_map *map);
void	ft_fill_map(t_map *map, char *txt);
void	ft_parsemap(t_map *map);
void	check_characters(t_map *map, int e, int p);
void	ft_check_if_rect(t_map *map);
void	ft_checkwalls(char *a);
void	ft_check_borders(t_map *map, int c);

// Img functions

void	ft_fill_img(t_img *img);
void	ft_init_img(t_img *img, t_map *map);
void	ft_put_img(t_img *i, char a, t_map *m);
void	ft_destroy_img(t_img *img);

// Basic functions

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	ft_error_map(int a);

// moves

void	ft_moves(t_map *map, t_img *img, int keycode);
void	ft_find_p(t_map *map, int i, int j);
void	move_up(t_map *map, t_img *img, int x, int y);
void	move_right(t_map *map, t_img *img, int x, int y);
void	move_left(t_map *map, t_img *img, int x, int y);
void	move_down(t_map *map, t_img *img, int x, int y);

// Actual program

void	ft_loop_map(t_img	*img, t_map *map);
void	so_long(t_map *map);
void	ft_win(t_map *map, t_img *img);

#endif