/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeliew <yeliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 23:10:15 by yeliew            #+#    #+#             */
/*   Updated: 2026/09/12 00:56:45 by yeliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_stack(int ac, char **av, t_stack **a)
{
	*a = build_stack(ac, av, 1);
	if (!*a || check_duplicate(*a) == TRUE)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	apply_index(*a);
	return (1);
}

static char	*read_line(int fd)
{
	ssize_t	bytes_read;	
	char	buffer[2];
	char	*dest;
	char	*temp;

	dest = ft_strdup("");
	buffer[1] = 0;
	bytes_read = read(fd, buffer, 1);
	while (bytes_read > 0)
	{
		if (*buffer == '\0')
			break ;
		temp = dest;
		dest = ft_strjoin(temp, buffer);
		free(temp);
		if (*buffer == '\n')
			break ;
		bytes_read = read(fd, buffer, 1);
	}
	if (bytes_read == -1 && dest != 0)
		return (free(dest), NULL);
	else if (bytes_read == -1)
		return (0);
	return (dest);
}

static char	execute_operation(t_stack **a, t_stack **b, char *operation)
{
	if (ft_strncmp("sa\n", operation, 3) == 0)
		return (swap_a_np(a), 1);
	if (ft_strncmp("sb\n", operation, 3) == 0)
		return (swap_b_np(b), 1);
	if (ft_strncmp("ss\n", operation, 3) == 0)
		return (swap_s_np(a, b), 1);
	if (ft_strncmp("pa\n", operation, 3) == 0)
		return (push_a_np(a, b), 1);
	if (ft_strncmp("pb\n", operation, 3) == 0)
		return (push_b_np(a, b), 1);
	if (ft_strncmp("ra\n", operation, 3) == 0)
		return (rotate_a_np(a), 1);
	if (ft_strncmp("rb\n", operation, 3) == 0)
		return (rotate_b_np(b), 1);
	if (ft_strncmp("rr\n", operation, 3) == 0)
		return (rotate_r_np(a, b), 1);
	if (ft_strncmp("rra\n", operation, 3) == 0)
		return (reverse_rotate_a_np(a), 1);
	if (ft_strncmp("rrb\n", operation, 3) == 0)
		return (reverse_rotate_b_np(b), 1);
	if (ft_strncmp("rrr\n", operation, 3) == 0)
		return (reverse_rotate_r_np(a, b), 1);
	return (0);
}

static void	cleanup(t_stack **a, t_stack **b, char *line)
{
	free(line);
	free_stack(a);
	free_stack(b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (!fill_stack(ac, av, &stack_a))
		return (1);
	line = read_line(0);
	while (line && *line)
	{
		if (!execute_operation(&stack_a, &stack_b, line))
		{
			ft_putstr_fd("Error\n", 2);
			cleanup(&stack_a, &stack_b, line);
			return (1);
		}
		free(line);
		line = read_line(0);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	cleanup(&stack_a, &stack_b, line);
	return (0);
}
