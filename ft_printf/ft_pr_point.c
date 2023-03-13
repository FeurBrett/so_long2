/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:14:33 by apirovan          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:13 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_point(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_is_point(ptr / 16);
		ft_is_point(ptr % 16);
	}
	if (ptr < 16)
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_pr_point(unsigned long ptr)
{
	int	i;

	i = 0;
	i += write (1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
		ft_is_point(ptr);
	return (ft_hexa_len(ptr) + 2);
}
