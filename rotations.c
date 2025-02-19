/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:32:51 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/17 14:35:17 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate_ab(t_stack *stack)
{
	stack->first = stack->first->next;
	stack->last = stack->last->next;
}

static void	rotate_rs(t_stack *stack_a, t_stack *stack_b)
{
	rotate_ab(stack_a);
	rotate_ab(stack_b);
	ft_putendl_fd("rs", 1);
}

static void	rev_rotate_rs(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate_ab(stack_a);
	rev_rotate_ab(stack_b);
	ft_putendl_fd("rrs", 1);
}

void	rev_rotate_ab(t_stack *stack)
{
	t_list	*pre_last;

	pre_last = ft_before_last(stack->first, stack->last);
	//stack->first->next = stack->first;
	stack->first = stack->last;
	stack->last = pre_last;
}
void	do_rotations(t_stack *stack_a, t_stack *stack_b, t_best *to_move)
{
	while (to_move->rs-- > 0)
		rotate_rs(stack_a, stack_b);
	while (to_move->rrs-- > 0)
		rev_rotate_rs(stack_a, stack_b);
	while (to_move->ra-- > 0)
	{
			rotate_ab(stack_a);
			ft_putendl_fd("ra", 1);
	}
	while (to_move->rra-- > 0)
	{
			rev_rotate_ab(stack_a);
			ft_putendl_fd("rra", 1);
	}
	while (to_move->rb-- > 0)
	{
			rotate_ab(stack_b);
			ft_putendl_fd("rb", 1);
	}
	while (to_move->rrb-- > 0)
	{
			rev_rotate_ab(stack_b);
			ft_putendl_fd("rrb", 1);
	}
}
