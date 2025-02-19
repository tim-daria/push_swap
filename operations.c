/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:00:58 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/17 16:08:07 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void swap(t_stack *stack)
{
	void *temp;

	if (stack->len < 2)
		return;
	temp = stack->first->content;
	stack->first->content = stack->first->next->content;
	stack->first->next->content = temp;
	ft_putendl_fd("sa", 1);
}

static void ft_push_tob(t_stack *stack_b, void *num)
{
	if (stack_b->first == NULL)
	{
		stack_b->first = ft_lstnew(num);
		stack_b->last = stack_b->first;
	}
	else
	{
		ft_lstadd_front(&stack_b->first, ft_lstnew(num));
		stack_b->last->next = stack_b->first;
	}
	ft_putendl_fd("pb", 1);
}
static void *ft_pop(t_list **src)
{
	t_list *temp;
	void *num;

	temp = *src;
	num = temp->content;
	*src = temp->next;
	free(temp);
	return (num);
}

void	ft_push_toa(t_stack *stack_a, t_stack *stack_b)
{
	void	*num;

	while (stack_b->len > 0)
	{
		num = ft_pop(stack_b->first);

		ft_lstadd_front(dst, ft_lstnew(num));
		ft_putendl_fd("pa", 1);
	}
}

void move(t_stack *stack_a, t_stack *stack_b, t_best *to_move)
{
	void *num;

	if (stack_b->len == 0 && stack_a->first)
	{
		stack_b->max = *(int *)stack_a->first->content; // мне надо установить это только для первого прохода через цикл, дальше надо сравнивать
		stack_b->min = *(int *)stack_a->first->content;
		// printf("stack_b max - %d, stack_b min - %d ", stack_b->max, stack_b->min);
		// fflush(0);
	}
	do_rotations(stack_a, stack_b, to_move);
	num = ft_pop(&stack_a->first);
	stack_a->last->next = stack_a->first;
	// printf("current value - %d ", *(int *)num);
	// fflush(0);
	stack_a->len--;
	ft_push_tob(stack_b, num);
	if (*(int *)num > stack_b->max)
		stack_b->max = *(int *)num;
	if (*(int *)num < stack_b->min)
		stack_b->min = *(int *)num;
	stack_b->len++;
}
