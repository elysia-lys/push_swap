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

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_operation	*moves;

	if (ac == 1)
		return (0);
	moves = ft_calloc(1, sizeof(t_operation));
	if (!call_flag(ac, av, &stack_a, moves))
	{
		free(moves);
		return (1);
	}
	free_stack(&stack_a);
	free(moves);
	return (0);
}
