/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:30:52 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 20:34:04 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_duplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->num == checker->num)
				return (TRUE);
			checker = checker->next;
		}
		current = current->next;
	}
	return (FALSE);
}

t_bool	check_integer(char *ptr)
{
	int		i;
	long	num;

	i = 0;
	num = ps_atoi(ptr);
	if (num == NOT_INT)
		return (FALSE);
	return (TRUE);
}

long	ps_atoi(const char *nptr)
{
	int		n;
	long	result;
	int		sum;

	n = 0;
	result = 0;
	sum = 1;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			sum *= -1;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		result = result * 10 + (nptr[n] - '0');
		if ((sum == 1 && result > INT_MAX)
			|| (sum == -1 && (-result) < INT_MIN))
			return (NOT_INT);
		n++;
	}
	if (nptr[n] < '0' || nptr[n] > '9' || nptr[n] != ' ')
		return (NOT_INT);
	return ((int)(sum * result));
}
