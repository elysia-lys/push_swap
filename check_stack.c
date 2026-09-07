/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:58:58 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 16:27:24 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (TRUE);
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}
