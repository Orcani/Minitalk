/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:55 by desambou          #+#    #+#             */
/*   Updated: 2024/11/23 10:21:15 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uppercase(unsigned int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	print_hex(uintptr_t n, int uppercase)
{
	int		count;
	char	digit;
	char	*hex_lower;
	char	*hex_upper;

	count = 0;
	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (n >= 16)
		count += print_hex(n / 16, uppercase);
	if (uppercase)
		digit = hex_upper[n % 16];
	else
		digit = hex_lower[n % 16];
	write(1, &digit, 1);
	count++;
	return (count);
}
