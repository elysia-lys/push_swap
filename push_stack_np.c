/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_np.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 00:50:37 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/12 00:51:21 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_np(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!a || !b || !*b)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
}

void	push_b_np(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!b || !a || !*a)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
}
