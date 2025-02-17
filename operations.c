/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:00:58 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/07 17:34:33 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list *ft_before_last(t_list *lst, t_list *last)
{
	while (lst->next != last)
	{
		lst = lst->next;
	}
	return (lst);
}

void	rb(t_stack *stack_b)
{
	stack_b->first = stack_b->first->next;
	stack_b->last = stack_b->last->next;
	ft_putendl_fd("rb", 1);
}

void	ra(t_stack *stack_a)
{
	stack_a->first = stack_a->first->next;
	stack_a->last = stack_a->last->next;
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack *stack_a)
{
	t_list	*pre_last;

	pre_last = ft_before_last(stack_a->first, stack_a->last);
	stack_a->first = stack_a->last;
	stack_a->last = pre_last;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b)
{
	t_list	*pre_last;

	pre_last = ft_before_last(stack_b->first, stack_b->last);
	stack_b->first = stack_b->last;
	stack_b->last = pre_last;
	ft_putendl_fd("rrb", 1);
}
void	swap(t_list *first)
{
	void	*temp;

	temp = first->content;
	first->content = first->next->content;
	first->next->content = temp;
}

void	ft_push_tob(t_list **dst, t_list **last, void *num)
{
	if (*dst == NULL)
	{
		*dst = ft_lstnew(num);
		*last = *dst;
	}
	else
	{
		ft_lstadd_front(dst, ft_lstnew(num));
		(*last)->next = *dst;
	}
	ft_putendl_fd("pb", 1);
}
void	*ft_pop(t_list **src)
{
	t_list	*temp;
	void	*num;

	temp = *src;
	num = temp->content;
	*src = temp->next;
	free(temp);
	return (num);
}

void	ft_push_toa(t_list **dst, t_list **src)
{
	void	*num;

	while (*src != NULL)
	{
		num = ft_pop(src);
		ft_lstadd_front(dst, ft_lstnew(num));
		ft_putendl_fd("pa", 1);
	}
}
void	move(t_stack *stack_a, t_stack *stack_b, t_best *to_move)
{
	if (stack_b->len == 0)
	{
		stack_b->max = stack_a->first->content; // мне надо установить это только для первого прохода через цикл, дальше надо сравнивать
		stack_b->min = stack_a->first->content;
	}
	if (to_move->ra != 0)
	{
		while (to_move->ra > 0)
		{
			ra(stack_a);
			to_move->ra--;
		}
	}
}
void	transfer(t_stack *stack_a, t_stack *stack_b)
{
	void	*num;
	int		count;
	void	*max;
	void	*min;
	//t_list	*last;
	int		i;

	stack_b->max = stack_a->first->content;
	stack_b->min = stack_a->first->content;
	//last = NULL;
	count = 0;
	i = 0;
	while (*stack_a != NULL)
	{
		num = ft_pop(stack_a);
		//count++;
		if (count < 2)
			ft_push_tob(stack_b, &last, num);
		else
		 {
			if ((*(int*)num > *(int*)max || *(int*)num < *(int*)min) && (*stack_b)->content == max)
				ft_push_tob(stack_b, &last, num);
			else if ((*(int*)num > *(int*)max || *(int*)num < *(int*)min) && (*stack_b)->content != max)
			{
				while ((*stack_b)->content != max)
				{
					rb(&stack_b->first, &stack_b->last);
					i++;
				}
				// printf("%d - count\n", count);
				// printf("%d - i\n", i);
				if (count - i < i)
				{
					while (count - i > 0)
					{
						ft_putendl_fd("rrb", 1);
						i++;
					}
				}
				else
				{
					while (i > 0)
					{
						ft_putendl_fd("rb", 1);
						i--;
					}
				}
				i = 0;
				ft_push_tob(stack_b, &last, num);
			}
			else
			{
				while (*(int*)num < *(int*)(*stack_b)->content || *(int*)num > *(int*) last->content)
				{
					rb(&stack_b->first, &stack_b->last);
					i++;
				}
				// printf("%d - count\n", count);
				// printf("%d - i\n", i);
				if (count - i < i)
				{
					while (count - i > 0)
					{
						ft_putendl_fd("rrb", 1);
						i++;
					}
				}
				else
				{
					while (i > 0)
					{
						ft_putendl_fd("rb", 1);
						i--;
					}
				}
				i = 0;
				ft_push_tob(stack_b, &last, num);
			}
		}
		if (*(int*)num > *(int*)max)
			max = num;
		if (*(int*)num < *(int*)min)
			min = num;
		count++;
	}
	while ((*stack_b)->content != max)
	{
		rb(&stack_b->first, &stack_b->last);
		i++;
	}
	// printf("%d - count\n", count);
	// printf("%d - i\n", i);
	if (count - i < i)
	{
		while (count - i > 0)
		{
			ft_putendl_fd("rrb", 1);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_putendl_fd("rb", 1);
			i--;
		}
	}
	i = 0;
	last->next = NULL;
}
