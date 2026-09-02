/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:03:00 by zetan             #+#    #+#             */
/*   Updated: 2026/08/29 16:57:45 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;
	int	size;

	size = ps_lstsize(a);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (j < size)
		{
			total_pairs += 1;
			if (ps_lstpoint(a, i)->num > ps_lstpoint(a, j)->num)
				mistakes += 1;
		}
		i++;
	}
	return ((float)(mistakes) / (float)(total_pairs));
}

void	apply_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		rank;

	current = stack;
	while (current)
	{
		rank = 0;
		temp = stack;
		while (temp)
		{
			if (current->num > temp->num)
				rank++;
			temp = temp->next;
		}
		current->index = rank;
		current = current->next;
	}
}
