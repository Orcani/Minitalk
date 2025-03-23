/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:58:53 by desambou          #+#    #+#             */
/*   Updated: 2024/12/23 14:55:48 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	return (write(1, &c, 1));
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

int	print_p(void *p)
{
	int			count;
	uintptr_t	num;

	num = (uintptr_t)p;
	count = 0;
	if (num == 0)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	else
	{
		count += print_str("0x");
		count += print_hex(num, 0);
	}
	return (count);
}
int	print_nbr(int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n == -2147483648)
	{
		return (print_str("-2147483648"));
	}
	if (n < 0)
	{
		print_c('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += print_nbr(n / 10);
	digit = (n % 10) + '0';
	print_c(digit);
	count++;
	return (count);
}