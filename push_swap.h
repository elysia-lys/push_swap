/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:36:47 by zetan             #+#    #+#             */
/*   Updated: 2026/09/01 18:41:08 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_utils/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define NOT_INT 6767676767
// # define TRUE 1
// # define FALSE 0

typedef enum s_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_operation
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operation;

typedef struct s_stack
{
	int				num;
	int				index;
	t_operation		moves;
	struct s_stack	*next;
}					t_stack;

/* Stack operations */
void	swap_a(t_stack **a, t_operation *moves);
void	swap_b(t_stack **b, t_operation *moves);
void	swap_s(t_stack **a, t_stack **b, t_operation *moves);
void	push_a(t_stack **a, t_stack **b, t_operation *moves);
void	push_b(t_stack **a, t_stack **b, t_operation *moves);
void	rotate_a(t_stack **a, t_operation *moves);
void	rotate_b(t_stack **b, t_operation *moves);
void	rotate_r(t_stack **a, t_stack **b, t_operation *moves);
void	reverse_rotate_a(t_stack **a, t_operation *moves);
void	reverse_rotate_b(t_stack **b, t_operation *moves);
void	reverse_rotate_r(t_stack **a, t_stack **b, t_operation *moves);

/* error stuff & checking */
long	ps_atoi(const char *nptr);
t_bool	check_integer(char *ptr);
float	compute_disorder(t_stack *a);
t_bool	check_duplicate(t_stack *stack);

/* stack utils */
t_stack	*ps_lstnew(int num);
int		ps_lstsize(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ps_lstpoint(t_stack *list, unsigned int i);

/* show stack & moves */
void	show_stack(t_stack *stack_a);
void	show_index(t_stack *stack_a);
void	show_moves(t_operation *moves);

t_stack	*build_stack(int ac, char *av[]);
void	apply_index(t_stack *stack);
t_bool	is_sorted(t_stack *stack);
void	selection_sort(t_stack **stack_a, t_operation *moves);

#endif
