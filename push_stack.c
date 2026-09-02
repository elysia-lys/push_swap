/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:55:04 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 17:38:27 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* flags needed for ALL OPERATIONS benchmark
basically sometimes no need to print out the operations */

void	push_a(t_stack **a, t_stack **b, t_operation *moves)
{
	t_stack	*node;

	if (!a || !b || !*b)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	moves->pa += 1;
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b, t_operation *moves)
{
	t_stack	*node;

	if (!b || !a || !*a)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	moves->pb += 1;
	ft_printf("pb\n");
}
