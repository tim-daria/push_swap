/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 16:30:36 by dtimofee          #+#    #+#             */
/*   Updated: 2025-02-27 16:30:36 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_a(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack->first->content;
	b = *(int *)stack->first->next->content;
	c = *(int *)stack->last->content;
	stack->max = a;
	if (c < b)
	{
		stack->min = c;
		swap(stack);
		rev_rotate_ab(stack);
		ft_putendl_fd("rra", 1);
	}
	else
	{
		stack->min = b;
		rotate_ab(stack);
		ft_putendl_fd("ra", 1);
	}
}

static void	max_b(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack->first->content;
	b = *(int *)stack->first->next->content;
	c = *(int *)stack->last->content;
	stack->max = b;
	if (a < c)
	{
		stack->min = a;
		swap(stack);
		rotate_ab(stack);
		ft_putendl_fd("ra", 1);
	}
	else
	{
		stack->min = c;
		rev_rotate_ab(stack);
		ft_putendl_fd("rra", 1);
	}
}

static void	max_c(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack->first->content;
	b = *(int *)stack->first->next->content;
	c = *(int *)stack->last->content;
	stack->max = c;
	if (a < b)
		stack->min = a;
	else
	{
		stack->min = b;
		swap(stack);
	}
}

void	sort3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->len == 2)
	{
		if (*(int *)stack->first->content > *(int *)stack->first->next->content)
			swap(stack);
		return ;
	}
	else
	{
		a = *(int *)stack->first->content;
		b = *(int *)stack->first->next->content;
		c = *(int *)stack->last->content;
		if (a > b && a > c)
			max_a(stack);
		else if (c > b && c > a)
			max_c(stack);
		else
			max_b(stack);
	}
}
