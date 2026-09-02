/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:31:12 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 17:58:46 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_moves(t_operation *moves)
{
	ft_printf("sa: %d\n", moves->sa);
	ft_printf("sb: %d\n", moves->sb);
	ft_printf("ss: %d\n", moves->ss);
	ft_printf("pa: %d\n", moves->pa);
	ft_printf("pb: %d\n", moves->pb);
	ft_printf("ra: %d\n", moves->ra);
	ft_printf("rb: %d\n", moves->rb);
	ft_printf("rr: %d\n", moves->rr);
	ft_printf("rra: %d\n", moves->rra);
	ft_printf("rrb: %d\n", moves->rrb);
	ft_printf("rrr: %d\n", moves->rrr);
}

void	show_stack(t_stack *stack_a)
{
	ft_printf("Stack => [%d", stack_a->num);
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		ft_printf(", %d", stack_a->num);
	}
	ft_printf("]\n");
}

void	show_index(t_stack *stack_a)
{
	ft_printf("Index => [%d", stack_a->index);
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		ft_printf(", %d", stack_a->index);
	}
	ft_printf("]\n");
}
