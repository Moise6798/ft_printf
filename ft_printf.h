/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niotzenb <niotzenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:37:46 by niotzenb          #+#    #+#             */
/*   Updated: 2023/11/07 11:21:50 by niotzenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <aio.h>

int		ft_printf(const char *format, ...);
int		ft_after_percent(const char *format, va_list args, int j, int i);
int		ft_found_s(char *s, int i);
int		ft_found_c(char c, int i);
int		ft_putchar_fd(char c, int fd, int i);
int		ft_found_xupp(size_t X, int i);
int		ft_found_xlower(size_t x, int i);
int		ft_found_d(int d, int i);
int		ft_found_u(unsigned int u, int i);
int		ft_found_p(unsigned long long s, int i);
int		ft_p_len(unsigned long long s, int i);

void	ft_put_p(unsigned long long s, int i);

#endif