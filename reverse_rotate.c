/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:51:46 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 17:33:07 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sub_reverse_rotate_a(t_stack **a);
static void	sub_reverse_rotate_b(t_stack **b);

void	reverse_rotate_a(t_stack **a, t_operation *moves)
{
	t_stack	*second_last;
	t_stack *last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *a;
	second_last->next = NULL;
	*a = last;
	moves->rra += 1;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b, t_operation *moves)
{
	t_stack	*second_last;
	t_stack *last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *b;
	second_last->next = NULL;
	*b = last;
	moves->rrb += 1;
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack **a, t_stack **b, t_operation *moves)
{
	sub_reverse_rotate_a(a);
	sub_reverse_rotate_b(b);
	moves->rrr += 1;
	ft_printf("rrr\n");
}

static void	sub_reverse_rotate_a(t_stack **a)
{
	t_stack	*second_last;
	t_stack *last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *a;
	second_last->next = NULL;
	*a = last;
}

static void	sub_reverse_rotate_b(t_stack **b)
{
	t_stack	*second_last;
	t_stack *last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *b;
	second_last->next = NULL;
	*b = last;
}
