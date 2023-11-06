/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:16 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/06 12:12:51 by niotzenb         ###   ########.fr       */
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
	if (s == NULL)
		return (i);
	while (*s)
	{
		i = write(1, &(*s), 1);
		s++;
		i++;
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
		j = ft_found_p(va_arg(args, void *), i);
	if (format[i] == 'd')
		j = ft_found_d(va_arg(args, int), i);
	if (format[i] == 'i')
		write(1, "i", 1);
	if (format[i] == 'u')
		j = ft_found_u(va_arg(args, int), i);
	if (format[i] == 'x')
		j = ft_found_xlower(va_arg(args, size_t), i);
	if (format[i] == 'X')
		j = ft_found_xupp(va_arg(args, size_t), i);
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

/*int	main(void)
{
	char *str;
	
	ft_printf("mon printf --> hello42, x: %x, X: %X, p: %p\n", 42, 42, str);
	printf("le vrai printf --> hello42, x: %x, X: %X, p: %p\n", 42, 42, str);
	return (0);
}*/
