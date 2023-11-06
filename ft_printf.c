/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:16 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:59 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd, int i)
{
	i = write(fd, &c, 1);
	return (i);
}

int	ft_found_c(char c, int i)
{
	i = write(1, &c, 1);
	return (i);
}

int	ft_found_s(char *s, int i)
{
	if (!s)
		i = ft_found_s("(null)", i);
	while (*s)
	{
		i = write(1, &(*s), 1);
		s++;
		i++;
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
		i = ft_found_p(va_arg(args, void *), i);
	if (format[j] == 'd')
		i = ft_found_d(va_arg(args, int), i);
	if (format[j] == 'i')
		write(1, "i", 1);
	if (format[j] == 'u')
		i = ft_found_u(va_arg(args, int), i);
	if (format[j] == 'x')
		i = ft_found_xlower(va_arg(args, size_t), i);
	if (format[j] == 'X')
		i = ft_found_xupp(va_arg(args, size_t), i);
	if (format[j] == '%')
		write(1, "%", 1);
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
		{
			write(1, &format[j], 1);
			i++;
		}
		j++;
	}
	va_end(args);
	return (i);
}

/*int	main(void)
{
	char	*str;
	int		i;

	i = ft_printf("mon printf --> hello42, x: %x\n", 42);
	printf("i: %d\n", i);
	i = printf("le vrai printf --> hello42, x: %x\n", 42);
	printf("i: %d\n", i);
	return (0);
}*/
