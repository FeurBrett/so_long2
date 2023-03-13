/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirovan <apirovan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:26:32 by apirovan          #+#    #+#             */
/*   Updated: 2022/09/20 16:03:36 by apirovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *a, ...);
int		ft_check_conv(va_list args, const char a);
int		ft_pr_char(char *a);
int		ft_putchar(char a);
int		ft_pr_unsigned(unsigned int a);
int		ft_pr_int(int a);
char	*ft_itoa(long int n);
void	ft_is_point(unsigned long ptr);
int		ft_pr_point(unsigned long ptr);
int		ft_pr_hexa(const char x, unsigned int a);
int		ft_hexa_len(unsigned long nb);
void	ft_mk_hexa(const char x, unsigned int a);

#endif