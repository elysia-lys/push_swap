/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:54:02 by zetan             #+#    #+#             */
/*   Updated: 2026/08/23 16:43:41 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(long long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	count++;
	return (count);
}

static void	ft_putunsigned(unsigned int num)
{
	if (num >= 10)
		ft_putunsigned(num / 10);
	write(1, &(char){'0' + (num % 10)}, 1);
}

int	print_num(int n)
{
	int		count;
	long	num;

	num = n;
	count = num_len(num);
	ft_putnbr_fd(n, 1);
	return (count);
}

int	print_unsigned_num(unsigned int n)
{
	int		count;

	count = num_len(n);
	ft_putunsigned(n);
	return (count);
}
