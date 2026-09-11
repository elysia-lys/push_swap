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
	push_a_np(a, b);
	moves->pa += 1;
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b, t_operation *moves)
{
	push_b_np(a, b);
	moves->pb += 1;
	ft_printf("pb\n");
}
