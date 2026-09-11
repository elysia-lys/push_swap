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

void	swap_a(t_stack **a, t_operation *moves)
{
	swap_a_np(a);
	moves->sa += 1;
	ft_printf("sa\n");
}

void	swap_b(t_stack **b, t_operation *moves)
{
	swap_b_np(b);
	moves->sb += 1;
	ft_printf("sb\n");
}

void	swap_s(t_stack **a, t_stack **b, t_operation *moves)
{
	swap_s_np(a, b);
	moves->ss += 1;
	ft_printf("ss\n");
}
