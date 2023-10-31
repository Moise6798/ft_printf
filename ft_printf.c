/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:16 by niotzenb          #+#    #+#             */
/*   Updated: 2023/10/31 14:24:58 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd, int i)
{
	write(fd, &c, 1);
	return (i);
}

int	ft_found_c(char c, int i)
{
	write(1, &c, 1);
	return (i);
}

int	ft_found_s(char *s, int i)
{
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
		i++;
	}
	return (i);
}

int	ft_found_d(int d, int i)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
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

int	ft_after_percent(const char *format, va_list args, int j, int i)
{
	if (format[i] == 'c')
		j = ft_found_c(va_arg(args, int), i);
	if (format[i] == 's')
		j = ft_found_s(va_arg(args, char *), i);
	if (format[i] == 'p')
		write(1, "p", 1);
	if (format[i] == 'd')
		j = ft_found_d(va_arg(args, int), i);
	if (format[i] == 'i')
		write(1, "i", 1);
	if (format[i] == 'u')
		write(1, "u", 1);
	if (format[i] == 'x')
		write(1, "x", 1);
	if (format[i] == 'X')
		write(1, "X", 1);
	if (format[i] == '%')
		write(1, "%", 1);
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			j = ft_after_percent(format, args, j, ++i);
		else
		{
			write(1, &format[i], 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("mon printf --> hello42, c: %c, s: %s, d: %d\n", 'q', "toto", 42);
	printf("le vrai printf --> hello42, c: %c, s: %s, d: %d\n", 'q', "toto", 42);
	return (0);
}
