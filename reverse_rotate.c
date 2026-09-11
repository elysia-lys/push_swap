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

void	reverse_rotate_a(t_stack **a, t_operation *moves)
{
	reverse_rotate_a_np(a);
	moves->rra += 1;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b, t_operation *moves)
{
	reverse_rotate_b_np(b);
	moves->rrb += 1;
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack **a, t_stack **b, t_operation *moves)
{
	reverse_rotate_r_np(a, b);
	moves->rrr += 1;
	ft_printf("rrr\n");
}
