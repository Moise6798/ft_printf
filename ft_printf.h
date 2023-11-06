/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:37:46 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/06 11:40:13 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_after_percent(const char *format, va_list args, int j, int i);
int	ft_found_s(char *s, int i);
int	ft_found_c(char c, int i);
int	ft_putchar_fd(char c, int fd, int i);
int	ft_found_xupp(size_t X, int i);
int	ft_found_xlower(size_t x, int i);
int	ft_found_d(int d, int i);
int	ft_found_p(void *s, int i);

#endif