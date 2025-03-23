/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:10 by desambou          #+#    #+#             */
/*   Updated: 2024/11/21 10:20:07 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
