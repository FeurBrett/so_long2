/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:26:24 by apirovan          #+#    #+#             */
/*   Updated: 2022/11/10 15:37:19 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conv(va_list args, const char a)
{
	int	i;

	i = 0;
	if (a == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (a == 's')
		i += ft_pr_char(va_arg(args, char *));
	else if (a == 'p')
		i += ft_pr_point(va_arg(args, unsigned long));
	else if ((a == 'd'))
		i += ft_pr_int(va_arg(args, long int));
	else if ((a == 'i'))
		i += ft_pr_int(va_arg(args, int));
	else if ((a == 'u'))
		i += ft_pr_unsigned(va_arg(args, unsigned int));
	else if ((a == 'x') || (a == 'X'))
		i += ft_pr_hexa(a, va_arg(args, unsigned int));
	else if (a == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *a, ...)
{
	int		len;
	int		i;
	va_list	args;

	va_start(args, a);
	len = 0;
	i = 0;
	while (a[i])
	{
		if (a[i] == '%')
		{
			len += ft_check_conv(args, a[i + 1]);
			i++;
		}
		else
			len += ft_putchar(a[i]);
		i++;
	}
	va_end (args);
	return (len);
}

// #include <stdio.h>

// int	main()
// {
// 	printf("%i\n",ft_printf("%", "youppiiiiiiii"));
// 	//printf("%i",printf("%s%"));
// 	return (0);
// }