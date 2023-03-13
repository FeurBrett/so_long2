/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:08:24 by apirovan          #+#    #+#             */
/*   Updated: 2023/03/13 18:36:55 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(long long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long int n)
{
	int				len;
	long long int	nb;
	char			*itoa;

	nb = n;
	len = ft_intlen(nb);
	itoa = malloc(sizeof(*itoa) * len + 1);
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		itoa[0] = '-';
	}
	if (nb == 0)
		itoa[0] = '0';
	while (nb > 0)
	{
		len--;
		itoa[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (itoa);
}

int	ft_pr_int(int a)
{
	char	*tmp;

	tmp = ft_itoa((long int) a);
	ft_pr_char(tmp);
	free(tmp);
	return (ft_intlen(a));
}

int	ft_pr_unsigned(unsigned int a)
{
	char	*tmp;

	if ((a < 0) || (a > 4294967295))
		return (-1);
	tmp = ft_itoa((long int) a);
	ft_pr_char(tmp);
	free(tmp);
	return (ft_intlen(a));
}
