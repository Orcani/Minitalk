/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:12 by desambou          #+#    #+#             */
/*   Updated: 2024/11/23 10:41:41 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
