/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:38:17 by apirovan          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:09 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_pr_char(char *a)
{
	int	i;

	i = 0;
	if (a == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (a[i] != '\0')
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char a)
{
	write (1, &a, 1);
	return (1);
}

void	ft_mk_hexa(const char x, unsigned int a)
{
	if (a >= 16)
	{
		ft_mk_hexa(x, a / 16);
		ft_mk_hexa(x, a % 16);
	}
	else
	{
		if (a < 10)
		{
			ft_putchar(a + '0');
		}
		else
		{
			if (x == 'x')
				ft_putchar(a - 10 + 'a');
			if (x == 'X')
				ft_putchar(a - 10 + 'A');
		}
	}
}

int	ft_pr_hexa(const char x, unsigned int a)
{
	if (a == 0)
		write(1, "0", 1);
	else
		ft_mk_hexa(x, a);
	return (ft_hexa_len(a));
}
