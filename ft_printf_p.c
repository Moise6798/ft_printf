/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:27:06 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/07 11:21:18 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_len(unsigned long long s, int i)
{
	while (s)
	{
		i++;
		s = s / 16;
	}
	return (i);
}

void	ft_put_p(unsigned long long s, int i)
{
	if (s >= 16)
	{
		ft_put_p(s / 16, i);
		ft_put_p(s % 16, i);
	}
	else if (s < 10)
		ft_putchar_fd(s + '0', 1, i);
	else
		ft_putchar_fd(s + 'a' - 10, 1, i);
}

int	ft_found_p(unsigned long long s, int i)
{
	i += write(1, "0x", 2);
	if (s == 0)
		i += write(1, "0", 1);
	else
	{
		ft_put_p(s, i);
		i = ft_p_len(s, i);
	}
	return (i);
}
