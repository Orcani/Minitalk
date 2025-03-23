/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:56:33 by desambou          #+#    #+#             */
/*   Updated: 2024/11/23 10:40:49 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	main(void)
// {
// 	printf("Character: %c\n", 'A');
// 	printf("String: %s\n", "Hello, World!");
// 	printf("Pointer: %p\n", (void *)0x12345678);
// 	printf("Pointer: %p\n", (void *)0x0);
// 	printf("Integer: %d\n", 42);
// 	printf("Unsigned: %ld\n", 4294967295);
// 	printf("Hexadecimal (lowercase): %x\n", 255);
// 	printf("Hexadecimal (uppercase): %X\n", 255);
// 	printf("Percent sign: %%\n");
// 	printf("====================================\n");
// 	ft_printf("Character: %c\n", 'A');
// 	ft_printf("String: %s\n", "Hello, World!");
// 	ft_printf("Pointer: %p\n", (void *)0x12345678);
// 	ft_printf("Pointer: %p\n", (void *)0x0);
// 	ft_printf("Integer: %d\n", 42);
// 	ft_printf("Unsigned: %u\n", 4294967295);
// 	ft_printf("Hexadecimal (lowercase): %x\n", 255);
// 	ft_printf("Hexadecimal (uppercase): %X\n", 255);
// 	ft_printf("Percent sign: %%\n");
// 	return (0);
// }

int	format_specifier(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += print_c(va_arg(args, int));
	else if (*format == 's')
		count += print_str(va_arg(args, char *));
	else if (*format == 'p')
		count += print_p(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		count += print_nbr(va_arg(args, int));
	else if (*format == 'u')
		count += print_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else if (*format == '%')
	{
		write(1, "%", 1);
		count++;
	}
	format++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += format_specifier(format + i, args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
