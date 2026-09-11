/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:58:36 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/10 21:30:18 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (1);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (1);
	return (0);
}

static int	parse_flags(int ac, char **av, char **strategy, int *bench)
{
	int	i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!is_flag(av[i]))
			return (-1);
		if (ft_strncmp(av[i], "--bench", 8) == 0)
		{
			if (*bench)
				return (-1);
			*bench = 1;
		}
		else
		{
			if (*strategy)
				return (-1);
			*strategy = av[i];
		}
		i++;
	}
	return (i);
}

void	run_strategy(t_stack **a, t_operation *moves, char *strategy)
{
	if (!strategy)
		custom_algo(a, moves);
	else if (ft_strncmp(strategy, "--simple", 9) == 0)
		selection_sort(a, moves);
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		medium_sort(a, moves);
	else if (ft_strncmp(strategy, "--complex", 10) == 0)
		radix_sort(a, moves);
	else if (ft_strncmp(strategy, "--adaptive", 11) == 0)
		custom_algo(a, moves);
}

int	call_flag(int ac, char **av, t_stack **a, t_operation *moves)
{
	char	*strategy;
	int		start;
	int		bench;

	strategy = NULL;
	bench = 0;
	start = parse_flags(ac, av, &strategy, &bench);
	if (start < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	*a = build_stack(ac, av, start);
	if (!*a || check_duplicate(*a) == TRUE)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	apply_index(*a);
	if (bench)
		benchmark(a, moves, strategy);
	else
		run_strategy(a, moves, strategy);
	return (1);
}
