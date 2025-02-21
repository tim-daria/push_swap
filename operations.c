/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:00:58 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/19 12:19:13 by dtimofee         ###   ########.fr       */
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
int	find_pos_ina(t_stack *a, void *num)
{
	int	i;
	t_stack	temp;

	i = 0;
	temp = *a;

	if (*(int*)num > temp.max || *(int*)num < temp.min)
	{
		while (*(int*)temp.first->content != temp.min)
		{
			i++;
			temp.first = temp.first->next;
		}
	}
	else if (*(int*)num < *(int*)temp.first->content && *(int*)num > *(int*)temp.last->content)
		return (i);
	else
	{
		if (*(int*)num < *(int*)temp.first->content)
		{
			while (*(int*)num < *(int*)temp.first->content)
			{
				i++;
				temp.first = temp.first->next;
			}
		}
		while (*(int*)num > *(int*)temp.first->content)
		{
			i++;
			temp.first = temp.first->next;
		}
	}
	return (i);
}

void	stacka_rot_direction(t_best *dir, int index_a, int len_a)
{
	t_best	ra;
	t_best	rra;

	init_tbest(&ra);
	init_tbest(&rra);


	ra.ra = index_a;
	rra.rra = len_a - index_a;
	if (ra.ra < rra.rra)
		*dir = ra;
	else
		*dir = rra;
	// printf("%d - dir.ra\n", dir->ra);
	// printf("%d - dir.rra\n", dir->rra);
}

void	ft_push_toa(t_stack *stack_a, t_stack *stack_b)
{
	void	*num;
	int		index_a;
	t_best	to_move;
	// void	*pos_min;

	init_tbest(&to_move);
	stack_b->last->next = NULL;
	while (stack_b->len > 0)
	{
		num = ft_pop(&stack_b->first);
		stack_b->len--;
		index_a = find_pos_ina(stack_a, num);
		// printf("%d - len_a\n", stack_a->len);
		// printf("%d - index_a\n", index_a);
		stacka_rot_direction(&to_move, index_a, stack_a->len);
		do_rotations(stack_a, stack_b, &to_move);
		ft_lstadd_front(&stack_a->first, ft_lstnew(num));
		// printf("aaa -> %p\n", stack_a->first);
		stack_a->last->next = stack_a->first;
		if (*(int *)num > stack_a->max)
			stack_a->max = *(int *)num;
		if (*(int *)num < stack_a->min)
		{
			stack_a->min = *(int *)num;
			//pos_min = num;
		}
		stack_a->len++;
		ft_putendl_fd("pa", 1);
	}
	index_a = find_pos_ina(stack_a, &stack_a->min);
	stacka_rot_direction(&to_move, index_a, stack_a->len);
	// printf("index_a = %d, to_move.ra = %d, to_move.rra = %d\n", index_a, to_move.ra, to_move.rra);
	do_rotations(stack_a, stack_b, &to_move);
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
