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

void	rotate_clockwise(t_list **stack_b, t_list **last)
{
	*stack_b = (*stack_b)->next;
	*last = (*last)->next;
	// ft_putendl_fd("rb", 1);
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

void	transfer(t_list **stack_a, t_list **stack_b)
{
	void	*num;
	int		count;
	void	*max;
	void	*min;
	t_list	*last;
	int		i;

	max = (*stack_a)->content;
	min = (*stack_a)->content;
	last = NULL;
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
					rotate_clockwise(stack_b, &last);
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
					rotate_clockwise(stack_b, &last);
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
		rotate_clockwise(stack_b, &last);
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
