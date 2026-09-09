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

void	custom_algo(t_stack **a, t_operation *moves)
{
	double	disorder;

	if (is_sorted(*a))
		return ;
	disorder = calculate_disorder(*a);
	if (disorder < 0.2)
	{
		selection_sort(a, moves);
		ft_printf("SIMPLE SORT\n");
	}
	else if (disorder < 0.5)
	{
		medium_sort(a, moves);
		ft_printf("MEDIUM SORT\n");
	}
	else
	{
		radix_sort(a, moves);
		ft_printf("COMPLEX SORT\n");
	}
}
