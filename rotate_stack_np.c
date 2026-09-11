/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_np.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 01:06:51 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/12 01:09:37 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*newlast_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	newlast_node = *stack;
	first_node = (*stack)->next;
	last_node = ps_lstlast(*stack);
	last_node->next = *stack;
	newlast_node->next = NULL;
	*stack = first_node;
}

void	rotate_a_np(t_stack **a)
{
	rotate(a);
}

void	rotate_b_np(t_stack **b)
{
	rotate(b);
}

void	rotate_r_np(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
