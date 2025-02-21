/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:38:55 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/17 15:49:02 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	find_pos_inb(t_stack b, void *num)
{
	int	i;
	t_stack	temp;

	i = 0;
	temp = b;

	if (*(int*)num > temp.max || *(int*)num < temp.min)
	{
		while (*(int*)temp.first->content != temp.max)
		{
			i++;
			temp.first = temp.first->next;
		}
	}
	else if (*(int*)num > *(int*)temp.first->content && *(int*)num < *(int*)temp.last->content)
		return (i);
	else
	{
		if (*(int*)num > *(int*)temp.first->content)
		{
			while (*(int*)num > *(int*)temp.first->content)
			{
				i++;
				temp.first = temp.first->next;
			}
		}
		while (*(int*)num < *(int*)temp.first->content)
		{
			i++;
			temp.first = temp.first->next;
		}
	}
	return (i);
}

void	find_bestnode(t_stack a, t_stack b, t_best *best_node)
{
	t_best	current;
	int		index_a;
	int		index_b;

	index_a = 0;
	init_tbest(&current);
	if (b.len < 2)
	{
		//best_node->sum = 0;
		*best_node = current;
		// printf("best_node movements - %d ", best_node->rs);
		a.first = a.first->next;
		index_a++;
		return;
	}
	// a.last->next = NULL;
	// printf("len(A) = %d, len(B) = %d\n", a.len, b.len);
	index_a = 0;
	while (index_a < a.len)
	{
		index_b = find_pos_inb(b, a.first->content);
		get_direction(index_a, index_b, a.len, b.len, &current);
		if (current.sum < best_node->sum)
		{
			// printf("Found best: %d, %d; sum = %d\n", index_a, index_b, current.sum);
			*best_node = current;
			best_node->pos = a.first;
		}
		index_a++;
	}
}
