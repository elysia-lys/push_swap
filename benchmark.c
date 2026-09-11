/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:32:07 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/11 15:19:16 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_complexity(double disorder, char *strategy)
{
	if (!strategy)
	{
		if (disorder < 0.2)
			ft_putstr_fd("O(n)", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
	else if (ft_strncmp(strategy, "--simple", 9) == 0)
		ft_putstr_fd("O(n)", 2);
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		ft_putstr_fd("O(n√n)", 2);
	else if (ft_strncmp(strategy, "--complex", 10) == 0)
		ft_putstr_fd("O(n log n)", 2);
	else if (ft_strncmp(strategy, "--adaptive", 11) == 0)
	{
		if (disorder < 0.2)
			ft_putstr_fd("O(n)", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
}

static void	print_operations(t_operation *moves)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(moves->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(moves->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(moves->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(moves->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(moves->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(moves->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(moves->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(moves->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(moves->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(moves->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(moves->rrr, 2);
	ft_putstr_fd("\n", 2);
}

static int	total_operations(t_operation *moves)
{
	return (moves->sa + moves->sb + moves->ss
		+ moves->pa + moves->pb
		+ moves->ra + moves->rb + moves->rr
		+ moves->rra + moves->rrb + moves->rrr);
}

void	benchmark(t_stack **a, t_operation *moves, char *strategy)
{
	double	disorder;

	disorder = calculate_disorder(*a);
	run_strategy(a, moves, strategy);
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putdouble(disorder);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] Strategy: ", 2);
	if (!strategy)
		ft_putstr_fd("adaptive", 2);
	else
		ft_putstr_fd(strategy + 2, 2);
	ft_putstr_fd(" / ", 2);
	print_complexity(disorder, strategy);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_operations(moves), 2);
	ft_putstr_fd("\n", 2);
	print_operations(moves);
}
