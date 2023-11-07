/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:16 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/07 11:32:22 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd, int i)
{
	i++;
	write(fd, &c, 1);
	return (i);
}

int	ft_found_c(char c, int i)
{
	i = ft_putchar_fd(c, 1, i);
	return (i);
}

int	ft_found_s(char *s, int i)
{
	if (!s)
		i = ft_found_s("(null)", i);
	else
	{	
		while (*s)
		{
			i = ft_putchar_fd(*s, 1, i);
			s++;
		}
	}
	return (i);
}

int	ft_after_percent(const char *format, va_list args, int i, int j)
{
	if (format[j] == 'c')
		i = ft_found_c(va_arg(args, int), i);
	if (format[j] == 's')
		i = ft_found_s(va_arg(args, char *), i);
	if (format[j] == 'p')
		i = ft_found_p(va_arg(args, unsigned long long), i);
	if (format[j] == 'd' || format[j] == 'i')
		i = ft_found_d(va_arg(args, int), i);
	if (format[j] == 'u')
		i = ft_found_u(va_arg(args, unsigned int), i);
	if (format[j] == 'x')
		i = ft_found_xlower(va_arg(args, size_t), i);
	if (format[j] == 'X')
		i = ft_found_xupp(va_arg(args, size_t), i);
	if (format[j] == '%')
	{
		write(1, "%", 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(args);
			return (i);
		}
		if (format[j] == '%')
			i = ft_after_percent(format, args, i, ++j);
		else
			i = ft_putchar_fd(format[j], 1, i);
		j++;
	}
	va_end(args);
	return (i);
}
