/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:04:17 by desambou          #+#    #+#             */
/*   Updated: 2024/11/23 10:21:23 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	format_specifier(const char *format, va_list args);
int	print_c(char c);
int	print_hex(uintptr_t n, int uppercase);
int	print_nbr(int n);
int	print_p(void *p);
int	print_str(char *s);
int	print_u(unsigned int n);

#endif