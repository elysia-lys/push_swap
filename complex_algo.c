/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:38:56 by zetan             #+#    #+#             */
/*   Updated: 2026/09/05 20:01:48 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_largest_bit(t_stack **stack_a);

void	radix_sort(t_stack **stack_a, t_operation *moves)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_stack	*stack_b;

	size = ps_lstsize(*stack_a);
	max_bits = get_largest_bit(stack_a);
	i = 0;
	stack_b = NULL;
	while (i < max_bits)
	{
		j = 0;
		if (is_sorted(*stack_a) == TRUE)
			break ;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a, moves);
			else
				push_b(stack_a, &stack_b, moves);
			j++;
		}
		while (stack_b != NULL)
			push_a(stack_a, &stack_b, moves);
		i++;
	}
}

static int	get_largest_bit(t_stack **stack_a)
{
	t_stack	*current;
	int		largest_index;
	int		max_bits;

	current = *stack_a;
	largest_index = current->index;
	max_bits = 0;
	while (current != NULL)
	{
		if (current->index > largest_index)
			largest_index = current->index;
		current = current->next;
	}
	while ((largest_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
