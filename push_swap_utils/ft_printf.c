/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:19:08 by zetan             #+#    #+#             */
/*   Updated: 2026/08/23 16:35:04 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specifier(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(*args, int));
	if (c == 's')
		count += print_string(va_arg(*args, char *));
	if (c == 'p')
		count += print_address(va_arg(*args, void *));
	if (c == 'd')
		count += print_num(va_arg(*args, int));
	if (c == 'i')
		count += print_num(va_arg(*args, int));
	if (c == 'u')
		count += print_unsigned_num(va_arg(*args, unsigned int));
	if (c == 'x')
		count += print_hex(va_arg(*args, unsigned int), 'x');
	if (c == 'X')
		count += print_hex(va_arg(*args, unsigned int), 'X');
	if (c == '%')
	{
		count++;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += check_specifier(s[i + 1], &args);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
