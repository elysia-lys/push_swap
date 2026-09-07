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

static void	sub_rotate_a(t_stack **a);
static void	sub_rotate_b(t_stack **b);

void	rotate_a(t_stack **a, t_operation *moves)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*newlast_node;

	if (!a || !*a || !(*a)->next)
		return ;
	newlast_node = *a;
	first_node = (*a)->next;
	last_node = ps_lstlast(*a);
	last_node->next = *a;
	newlast_node->next = NULL;
	*a = first_node;
	moves->ra += 1;
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b, t_operation *moves)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*newlast_node;

	if (!b || !*b || !(*b)->next)
		return ;
	newlast_node = *b;
	first_node = (*b)->next;
	last_node = ps_lstlast(*b);
	last_node->next = *b;
	newlast_node->next = NULL;
	*b = first_node;
	moves->rb += 1;
	ft_printf("rb\n");
}

void	rotate_r(t_stack **a, t_stack **b, t_operation *moves)
{
	sub_rotate_a(a);
	sub_rotate_b(b);
	moves->rr += 1;
	ft_printf("rr\n");
}

static void	sub_rotate_a(t_stack **a)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*newlast_node;

	if (!a || !*a || !(*a)->next)
		return ;
	newlast_node = *a;
	first_node = (*a)->next;
	last_node = ps_lstlast(*a);
	last_node->next = *a;
	newlast_node->next = NULL;
	*a = first_node;
}

static void	sub_rotate_b(t_stack **b)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*newlast_node;

	if (!b || !*b || !(*b)->next)
		return ;
	newlast_node = *b;
	first_node = (*b)->next;
	last_node = ps_lstlast(*b);
	last_node->next = *b;
	newlast_node->next = NULL;
	*b = first_node;
}
