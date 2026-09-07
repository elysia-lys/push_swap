/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 22:02:29 by zetan             #+#    #+#             */
/*   Updated: 2026/09/05 20:22:01 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack		*stack_a;
	t_operation	*moves;

	moves = ft_calloc(1, sizeof(t_operation));
	stack_a = build_stack(ac, av);
	if (!stack_a || check_duplicate(stack_a) == TRUE)
	{
		ft_printf("Error.\n");
		exit(1);
	}
	apply_index(stack_a);
	radix_sort(&stack_a, moves);
	show_stack(stack_a);
	show_moves(moves);
	free_stack(&stack_a);
	free(moves);
}
