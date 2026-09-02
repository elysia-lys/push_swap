/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:46:38 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 17:46:30 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_best_rotation(t_stack *stack_a, int target_index);
void	sort_three(t_stack **stack_a, t_operation *moves);
void	sort_numbers(t_stack **stack_a, t_operation *moves);

void	selection_sort(t_stack	**stack_a, t_operation *moves)
{
	if (ps_lstsize(*stack_a) == 2 && is_sorted(*stack_a) == FALSE)
		swap_a(stack_a, moves);
	if (ps_lstsize(*stack_a) == 3)
		sort_three(stack_a, moves);
	if (ps_lstsize(*stack_a) >= 4)
		sort_numbers(stack_a, moves);
}

void	sort_numbers(t_stack **stack_a, t_operation *moves)
{
	t_stack	*stack_b;
	int		target_index;

	stack_b = NULL;
	target_index = 0;
	while (ps_lstsize(*stack_a) > 3)
	{
		while ((*stack_a)->index != target_index)
		{
			if (count_best_rotation(*stack_a, target_index) == 1)
				reverse_rotate_a(stack_a, moves);
			else
				rotate_a(stack_a, moves);
		}
		push_b(stack_a, &stack_b, moves);
		target_index++;
	}
	sort_three(stack_a, moves);
	while (stack_b)
		push_a(stack_a, &stack_b, moves);
}

void	sort_three(t_stack **stack_a, t_operation *moves)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;

	if (first > second && second < third && first < third)
		swap_a(stack_a, moves);
	if (first > second && second > third)
	{
		swap_a(stack_a, moves);
		reverse_rotate_a(stack_a, moves);
	}
	if (first > second && second < third && first > third)
		rotate_a(stack_a, moves);
	if (first < second && second > third && first < third)
	{
		swap_a(stack_a, moves);
		rotate_a(stack_a, moves);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack_a, moves);
}

int	count_best_rotation(t_stack *stack_a, int target_index)
{
	int	size;
	int	position;

	size = ps_lstsize(stack_a) - 1;
	position = 0;
	while (stack_a != NULL)
	{
		if (stack_a->index == target_index)
			break ;
		position++;
		stack_a = stack_a->next;
	}
	if (position >= size / 2)
		return (1);
	else
		return (0);
}
