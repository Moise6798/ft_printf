/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:16 by niotzenb          #+#    #+#             */
/*   Updated: 2023/10/31 11:29:30 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_c(char )
{
	if ()
}
int	ft_after_percent(const char *format, va_list args, int j, int i)
{
	if (format[i] == 'c')
		write(1, "c", 1);
	if (format[i] == 's')
		write(1, "s", 1);
	if (format[i] == 'p')
		write(1, "p", 1);
	if (format[i] == 'd')
		write(1, "d", 1);
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
			i++;
		}
		j++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("mon printf --> hello42, c: %c, s: %s, d: %d\n", "q", "toto", 42);
	printf("le vrai printf --> hello42, c: %s, s: %s, d: %d\n", "q", "toto", 42);
	return (0);
}
