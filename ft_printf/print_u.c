/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:16:17 by desambou          #+#    #+#             */
/*   Updated: 2024/11/21 09:30:46 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n / 10)
		count += print_u(n / 10);
	digit = n % 10 + '0';
	print_c(digit);
	return (count + 1);
}
