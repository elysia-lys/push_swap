/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 21:07:49 by zetan             #+#    #+#             */
/*   Updated: 2026/08/23 16:37:08 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex_address(unsigned long long address, char *base)
{
	if (address >= 16)
		put_hex_address(address / 16, base);
	write(1, &base[address % 16], 1);
}

static int	count_hex_len(unsigned long long address)
{
	int	count;

	count = 0;
	while (address >= 16)
	{
		count++;
		address /= 16;
	}
	count++;
	return (count);
}

int	print_address(void *ptr)
{
	unsigned long long	address;
	int					count;
	char				*base;

	base = "0123456789abcdef";
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)ptr;
	count = count_hex_len(address);
	write(1, "0x", 2);
	put_hex_address(address, base);
	return (count + 2);
}

int	print_hex(unsigned int n, char c)
{
	char	*base;
	int		count;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = count_hex_len(n);
	put_hex_address(n, base);
	return (count);
}
