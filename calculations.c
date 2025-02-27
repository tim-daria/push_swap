/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:38:55 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:10 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_inside(t_stack temp, int num_value, int is_stackb)
{
	int	i;
	int	(*comparison_func)(int, int);

	i = 0;
	if (is_stackb)
		comparison_func = &greater_than;
	else
		comparison_func = &less_than;
	if (comparison_func(num_value, *(int *)temp.first->content))
	{
		while (comparison_func(num_value, *(int *)temp.first->content))
		{
			i++;
			temp.first = temp.first->next;
		}
	}
	while ((is_stackb && num_value < *(int *)temp.first->content)
		|| (!is_stackb && num_value > *(int *)temp.first->content))
	{
		i++;
		temp.first = temp.first->next;
	}
	return (i);
}

static int	correct_place(t_stack temp, int num_value, int is_stackb)
{
	if ((is_stackb && num_value > *(int *)temp.first->content
			&& num_value < *(int *)temp.last->content)
		|| (!is_stackb && num_value < *(int *)temp.first->content
			&& num_value > *(int *)temp.last->content))
		return (1);
	else
		return (0);
}

int	find_pos_instack(t_stack *stack, void *num, int is_stackb)
{
	int		i;
	t_stack	temp;
	int		limit_value;

	i = 0;
	temp = *stack;
	if (is_stackb)
		limit_value = temp.max;
	else
		limit_value = temp.min;
	if (*(int *)num > temp.max || *(int *)num < temp.min)
	{
		while (*(int *)temp.first->content != limit_value)
		{
			i++;
			temp.first = temp.first->next;
		}
	}
	else if (correct_place(temp, *(int *)num, is_stackb))
		return (i);
	else
		i = search_inside(temp, *(int *)num, is_stackb);
	return (i);
}

static t_stack_sizes	stack_sizes(int lena, int lenb)
{
	t_stack_sizes	sizes;

	sizes.size_a = lena;
	sizes.size_b = lenb;
	return (sizes);
}

void	find_bestnode(t_stack a, t_stack b, t_best *best_node)
{
	t_best	current;
	int		index_a;
	int		index_b;
	t_list	*current_node;

	index_a = 0;
	init_tbest(&current);
	if (b.len < 2)
	{
		*best_node = current;
		a.first = a.first->next;
		index_a++;
		return ;
	}
	index_a = -1;
	current_node = a.first;
	while (++index_a < a.len)
	{
		index_b = find_pos_instack(&b, current_node->content, 1);
		get_direction(index_a, index_b, stack_sizes(a.len, b.len), &current);
		if (current.sum < best_node->sum)
			*best_node = current;
		current_node = current_node->next;
	}
}
