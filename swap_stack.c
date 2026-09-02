/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:35:03 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 17:37:39 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sub_swap_a(t_stack **a);
static void	sub_swap_b(t_stack **b);

void	swap_a(t_stack **a, t_operation *moves)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	moves->sa += 1;
	ft_printf("sa\n");
}

void	swap_b(t_stack **b, t_operation *moves)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	moves->sb += 1;
	ft_printf("sb\n");
}

void	swap_s(t_stack **a, t_stack **b, t_operation *moves)
{
	sub_swap_a(a);
	sub_swap_b(b);
	moves->ss += 1;
	ft_printf("ss\n");
}

static void	sub_swap_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

static void	sub_swap_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}
