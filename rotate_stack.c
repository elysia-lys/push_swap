/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:19:27 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 17:28:51 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, t_operation *moves)
{
	rotate_a_np(a);
	moves->ra += 1;
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b, t_operation *moves)
{
	rotate_b_np(b);
	moves->rb += 1;
	ft_printf("rb\n");
}

void	rotate_r(t_stack **a, t_stack **b, t_operation *moves)
{
	rotate_r_np(a, b);
	moves->rr += 1;
	ft_printf("rr\n");
}
