/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 22:02:29 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 18:41:19 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> /* this is for compute disorder printf (%f) */

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_operation *moves;

	moves = ft_calloc(1, sizeof(t_operation));
	stack_a = build_stack(ac, av);
	if (!stack_a || check_duplicate(stack_a))
	{
		ft_printf("Error.\n");
		free(stack_a);
		exit (0);
	}
	apply_index(stack_a);
	selection_sort(&stack_a, moves);
	ft_printf("Sorted ");
	show_stack(stack_a);
	show_moves(moves);
	// disorder = compute_disorder(stack_a);
	// printf("%f\n", compute_disorder(stack_a));
	free(moves);
}

t_stack	*build_stack(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*temp;
	int	num;

	stack_a = NULL;
	if (ac < 2)
		return (NULL);
	while (ac > 1)
	{
		if (check_integer(av[ac - 1]) == TRUE)
		{
			num = (int)ps_atoi(av[ac - 1]);
			if (!stack_a)
				stack_a = ps_lstnew(num);
			else
			{
				temp = ps_lstnew(num);
				ps_lstadd_front(&stack_a, temp);
			}
		}
		else /* Integer Error */
			return (NULL);
		ac--;
	}
	return (stack_a);
}
