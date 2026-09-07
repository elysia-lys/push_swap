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
#include <stdio.h>

int	main(int ac, char *av[])
{
	//test your atoi something is wrong
	printf("1: %ld\n", ps_atoi("1"));
	printf("8: %ld\n", ps_atoi("8"));
	printf("7: %ld\n", ps_atoi("7"));
	printf("4: %ld\n", ps_atoi("4"));
	printf("9: %ld\n", ps_atoi("9"));

	printf("check 1: %d\n", check_integer("1"));
	printf("check 8: %d\n", check_integer("8"));
	printf("check 7: %d\n", check_integer("7"));
	printf("check 4: %d\n", check_integer("4"));
	printf("check 9: %d\n", check_integer("9"));

	t_stack	*stack_a;
	t_operation *moves;

	moves = ft_calloc(1, sizeof(t_operation));
	stack_a = build_stack(ac, av);
	/*if (!stack_a || check_duplicate(stack_a))
	{
		ft_printf("Error.\n");
		free(stack_a);
		exit (0);
	}*/
	if (!stack_a)
	{
		ft_printf("build_stack failed\n");
		exit(0);
	}
	if (check_duplicate(stack_a))
	{
		ft_printf("duplicate detected\n");
		exit(0);
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
}
