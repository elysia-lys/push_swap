/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:41:22 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 16:41:30 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_chunk(t_stack *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index < end)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}

static void	push_chunk(t_medium *m)
{
	while (has_chunk(*m->a, m->start, m->end))
	{
		if ((*m->a)->index >= m->start && (*m->a)->index < m->end)
			push_b(m->a, m->b, m->moves);
		else
			rotate_a(m->a, m->moves);
	}
}

static void	find_max(t_stack *b, int *max, int *pos)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index > *max)
		{
			*max = b->index;
			*pos = i;
		}
		i++;
		b = b->next;
	}
}

static void	push_max(t_medium *m)
{
	int	max;
	int	pos;
	int	size;

	max = (*m->b)->index;
	pos = 0;
	size = ps_lstsize(*m->b);
	find_max(*m->b, &max, &pos);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate_b(m->b, m->moves);
	else
		while (pos++ < size)
			reverse_rotate_b(m->b, m->moves);
	push_a(m->a, m->b, m->moves);
}

void	medium_sort(t_stack **a, t_operation *moves)
{
	t_medium	m;
	t_stack		*b;
	int			size;
	int			chunk_size;

	b = NULL;
	m.b = &b;
	size = ps_lstsize(*a);
	chunk_size = 1;
	while (chunk_size * chunk_size <= size)
		chunk_size++;
	chunk_size--;
	m.a = a;
	m.moves = moves;
	m.start = 0;
	m.end = chunk_size;
	while (m.start < size)
	{
		push_chunk(&m);
		m.start = m.end;
		m.end += chunk_size;
	}
	while (*m.b)
		push_max(&m);
}
