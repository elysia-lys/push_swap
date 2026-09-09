/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 16:10:50 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/09 17:17:20 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	calculate_disorder(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*compare;
	int		count;
	int		n;
	int		max;

	count = 0;
	n = ps_lstsize(stack);
	tmp = stack;
	while (tmp)
	{
		compare = tmp->next;
		while (compare)
		{
			if (tmp->index > compare->index)
				count++;
			compare = compare->next;
		}
		tmp = tmp->next;
	}
	max = n * (n - 1) / 2;
	return ((double)count / max);
}

static void	put_decimal(long decimal)
{
	if (decimal < 100000000)
		ft_putchar_fd('0', 1);
	if (decimal < 10000000)
		ft_putchar_fd('0', 1);
	if (decimal < 1000000)
		ft_putchar_fd('0', 1);
	if (decimal < 100000)
		ft_putchar_fd('0', 1);
	if (decimal < 10000)
		ft_putchar_fd('0', 1);
	if (decimal < 1000)
		ft_putchar_fd('0', 1);
	if (decimal < 100)
		ft_putchar_fd('0', 1);
	if (decimal < 10)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(decimal, 1);
}

void	ft_putdouble(double n)
{
	int		whole;
	long	decimal;

	whole = (int)n;
	decimal = (long)((n - whole) * 1000000000 + 0.5);
	ft_putnbr_fd(whole, 1);
	ft_putchar_fd('.', 1);
	put_decimal(decimal);
}

void	custom_algo(t_stack **a, t_operation *moves)
{
	double	disorder;

	if (is_sorted(*a))
		return ;
	disorder = calculate_disorder(*a);
	if (disorder < 0.2)
		selection_sort(a, moves);
	else if (disorder < 0.5)
		medium_sort(a, moves);
	else
		radix_sort(a, moves);
}
