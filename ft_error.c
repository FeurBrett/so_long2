/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:14:47 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 18:21:36 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_map(int a)
{
	write (1, "Error\n", 6);
	if (a == 0)
		write(1, "File must be .ber\n", 18);
	if (a == 1)
		write(1, "Non-playable map. Make sure it is correct\n", 42);
	if (a == 2)
		write(1, "Non-rectangular map.\n", 21);
	if (a == 3)
		write(1, "Only 1 player, 1 exit and at least 1 collectible.\n", 50);
	if (a == 4)
		write(1, "All borders must be walls.\n", 27);
	if (a == 5)
		write(1, "No retours à la ligne allowed before the map.\n", 47);
	if (a == 6)
		write(1, "Map not read successfully.\n", 27);
	if (a == 7)
		write(1, "malloc not successfull\n", 23);
	if (a == 8)
		write(1, "Only 1 argument accepted.\n", 26);
	if (a == 9)
		write(1, "Couldn't load images\n", 21);
	exit(EXIT_FAILURE);
}

int	red_cross(int i)
{
	i = 0;
	exit(EXIT_SUCCESS);
	return (0);
}
