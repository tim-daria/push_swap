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
	fflush(0);
	// printf("%d - stack_a_first value\n", *(int *)stack->first->content);
	// fflush(0);
	// printf("%d - stack_a_first next value\n", *(int *)stack->first->next->content);
	// fflush(0);
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

// void	ft_push_toa(t_list **dst, t_list **src)
// {
// 	void	*num;

// 	while (*src != NULL)
// 	{
// 		num = ft_pop(src);
// 		ft_lstadd_front(dst, ft_lstnew(num));
// 		ft_putendl_fd("pa", 1);
// 	}
// }

void move(t_stack *stack_a, t_stack *stack_b, t_best *to_move)
{
	void *num;

	if (stack_b->len == 0 && stack_a->first)
	{
		stack_b->max = *(int *)stack_a->first->content; // мне надо установить это только для первого прохода через цикл, дальше надо сравнивать
		stack_b->min = *(int *)stack_a->first->content;
		printf("stack_b max - %d, stack_b min - %d ", stack_b->max, stack_b->min);
		fflush(0);
	}
	do_rotations(stack_a, stack_b, to_move);
	num = ft_pop(&stack_a->first);
	printf("current value - %d ", *(int *)num);
	fflush(0);
	stack_a->len--;
	ft_push_tob(stack_b, num);
	if (*(int *)num > stack_b->max)
		stack_b->max = *(int *)num;
	if (*(int *)num < stack_b->min)
		stack_b->min = *(int *)num;
	stack_b->len++;
}
// void	transfer(t_stack *stack_a, t_stack *stack_b)
// {
// 	void	*num;
// 	int		count;
// 	void	*max;
// 	void	*min;
// 	//t_list	*last;
// 	int		i;

// 	stack_b->max = stack_a->first->content;
// 	stack_b->min = stack_a->first->content;
// 	//last = NULL;
// 	count = 0;
// 	i = 0;
// 	while (*stack_a != NULL)
// 	{
// 		num = ft_pop(stack_a);
// 		//count++;
// 		if (count < 2)
// 			ft_push_tob(stack_b, &last, num);
// 		else
// 		 {
// 			if ((*(int*)num > *(int*)max || *(int*)num < *(int*)min) && (*stack_b)->content == max)
// 				ft_push_tob(stack_b, &last, num);
// 			else if ((*(int*)num > *(int*)max || *(int*)num < *(int*)min) && (*stack_b)->content != max)
// 			{
// 				while ((*stack_b)->content != max)
// 				{
// 					rb(&stack_b->first, &stack_b->last);
// 					i++;
// 				}
// 				// printf("%d - count\n", count);
// 				// printf("%d - i\n", i);
// 				if (count - i < i)
// 				{
// 					while (count - i > 0)
// 					{
// 						ft_putendl_fd("rrb", 1);
// 						i++;
// 					}
// 				}
// 				else
// 				{
// 					while (i > 0)
// 					{
// 						ft_putendl_fd("rb", 1);
// 						i--;
// 					}
// 				}
// 				i = 0;
// 				ft_push_tob(stack_b, &last, num);
// 			}
// 			else
// 			{
// 				while (*(int*)num < *(int*)(*stack_b)->content || *(int*)num > *(int*) last->content)
// 				{
// 					rb(&stack_b->first, &stack_b->last);
// 					i++;
// 				}
// 				// printf("%d - count\n", count);
// 				// printf("%d - i\n", i);
// 				if (count - i < i)
// 				{
// 					while (count - i > 0)
// 					{
// 						ft_putendl_fd("rrb", 1);
// 						i++;
// 					}
// 				}
// 				else
// 				{
// 					while (i > 0)
// 					{
// 						ft_putendl_fd("rb", 1);
// 						i--;
// 					}
// 				}
// 				i = 0;
// 				ft_push_tob(stack_b, &last, num);
// 			}
// 		}
// 		if (*(int*)num > *(int*)max)
// 			max = num;
// 		if (*(int*)num < *(int*)min)
// 			min = num;
// 		count++;
// 	}
// 	while ((*stack_b)->content != max)
// 	{
// 		rb(&stack_b->first, &stack_b->last);
// 		i++;
// 	}
// 	// printf("%d - count\n", count);
// 	// printf("%d - i\n", i);
// 	if (count - i < i)
// 	{
// 		while (count - i > 0)
// 		{
// 			ft_putendl_fd("rrb", 1);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (i > 0)
// 		{
// 			ft_putendl_fd("rb", 1);
// 			i--;
// 		}
// 	}
// 	i = 0;
// 	last->next = NULL;
// }
