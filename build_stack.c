/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:07:14 by zetan             #+#    #+#             */
/*   Updated: 2026/09/05 18:59:43 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void free_split(char **split);
t_stack	*add_to_stack(char **ptr, t_stack *stack_a);

t_stack	*build_stack(int ac, char *av[], int start)
{
	t_stack	*stack_a;
	char	**split_args;

	stack_a = NULL;
	if (ac <= start)
		return (NULL);
	while (ac > start)
	{
		split_args = ft_split(av[ac - 1], ' ');
		stack_a = add_to_stack(split_args, stack_a);
		free_split(split_args);
		if (stack_a == NULL)
			return (NULL);
		ac--;
	}
	return (stack_a);
}

t_stack	*add_to_stack(char **ptr, t_stack *stack_a)
{
	t_stack	*temp;
	int		num;
	int		i;

	i = 0;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		i--;
		if (check_integer(ptr[i]) == TRUE)
		{
			num = (int)ps_atoi(ptr[i]);
			temp = ps_lstnew(num);
			ps_lstadd_front(&stack_a, temp);
		}
		else
		{
			free_stack(&stack_a);
			return (NULL);
		}
	}
	return (stack_a);
}

void	free_stack(t_stack **stack)
{
    t_stack	*tmp;

    if (!stack || !*stack)
	return ;
    while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

static void	free_split(char **split)
{
    int	i;

    i = 0;
    if (!split)
	    return ;
    while (split[i])
    {
	    free(split[i]);
	    i++;
    }
    free(split);
}
