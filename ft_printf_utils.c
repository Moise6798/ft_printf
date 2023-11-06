/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:31:19 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/06 12:04:33 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_p(void *s, int i)
{
	unsigned long int	h;

	h = (unsigned long int)s;
	i = write(1, "0x", 2);
	if (h == 0)
		i = ft_putchar_fd('0', 1, i);
	else if (h >= 16)
	{
		i = ft_found_xlower(h / 16, i);
		i = ft_found_xlower(h % 16, i);
	}
	else if (h < 10)
		i = ft_putchar_fd(h + '0', 1, i);
	else
		i = ft_putchar_fd(h + 'a' - 10, 1, i);
	return (i);
}

int	ft_found_d(int d, int i)
{
	if (d == -2147483648)
	{
		i = write(1, "-2147483648", 11);
		i = i + 11;
	}
	else if (d < 0)
	{
		i = ft_putchar_fd('-', 1, i);
		i = ft_found_d(-d, i);
	}
	else if (d >= 0 && d < 10)
		i = ft_putchar_fd(d + 48, 1, i);
	else
	{
		i = ft_found_d(d / 10, i);
		i = ft_putchar_fd((d % 10) + 48, 1, i);
	}
	return (i);
}

int	ft_found_xlower(size_t x, int i)
{
	unsigned int	h;

	h = (unsigned int)x;
	if (h == 0)
		i = ft_putchar_fd('0', 1, i);
	else if (h >= 16)
	{
		i = ft_found_xlower(h / 16, i);
		i = ft_found_xlower(h % 16, i);
	}
	else if (h < 10)
		i = ft_putchar_fd(h + '0', 1, i);
	else
		i = ft_putchar_fd(h + 'a' - 10, 1, i);
	return (i);
}

int	ft_found_xupp(size_t X, int i)
{
	unsigned int	h;

	h = (unsigned int)X;
	if (h == 0)
		i = ft_putchar_fd('0', 1, i);
	else if (h >= 16)
	{
		i = ft_found_xupp(h / 16, i);
		i = ft_found_xupp(h % 16, i);
	}
	else if (h < 10)
		i = ft_putchar_fd(h + '0', 1, i);
	else
		i = ft_putchar_fd(h + 'A' - 10, 1, i);
	return (i);
}

int	ft_found_u(unsigned int u, int i)
{
	if (u >= 10)
		i = ft_found_u(u / 10, i);
	i = ft_putchar_fd(u % 10 + '0', 1, i);
	return (i);
}
