/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_np.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 01:13:15 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/12 01:15:46 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *stack;
	second_last->next = NULL;
	*stack = last;
}

void	reverse_rotate_a_np(t_stack **a)
{
	reverse_rotate(a);
}

void	reverse_rotate_b_np(t_stack **b)
{
	reverse_rotate(b);
}

void	reverse_rotate_r_np(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
