/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 15:00:58 by dtimofee          #+#    #+#             */
/*   Updated: 2025-01-16 15:00:58 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_clockwise(t_list **stack_b, t_list **last)
{
	*stack_b = (*stack_b)->next;
	*last = (*last)->next;
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
void	transfer(t_list **stack_a, t_list **stack_b)
{
	void	*num;
	int		count;
	void	*max;
	void	*min;
	t_list	*last;

	max = (*stack_a)->content;
	min = (*stack_a)->content;
	last = NULL;
	count = 0;
	while (*stack_a != NULL)
	{
		num = ft_pop(stack_a);
		count++;
		if (count <= 2)
			ft_push_tob(stack_b, &last, num);
		else
		 {
			if ((*(int*)num > *(int*)max || *(int*)num < *(int*)min) && (*stack_b)->content == max)
				ft_push_tob(stack_b, &last, num);
			else if ((*(int*)num > *(int*)max || *(int*)num < *(int*)min) && (*stack_b)->content != max)
			{
				while ((*stack_b)->content != max)
					rotate_clockwise(stack_b, &last);
				ft_push_tob(stack_b, &last, num);
			}
			else
			{
				while (*(int*)num < *(int*)(*stack_b)->content || *(int*)num > *(int*) last->content)
					rotate_clockwise(stack_b, &last);
				ft_push_tob(stack_b, &last, num);
			}
		}
		if (*(int*)num > *(int*)max)
			max = num;
		if (*(int*)num < *(int*)min)
			min = num;
	}
	while ((*stack_b)->content != max)
		rotate_clockwise(stack_b, &last);
	last->next = NULL;
}
