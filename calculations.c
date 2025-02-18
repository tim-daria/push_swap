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

	i = 0;
	if (*(int*)num > b.max || *(int*)num < b.min)
	{
		while (*(int*)b.first->content != b.max)
		{
			i++;
			b.first = b.first->next;
		}
	}
	else
	{
		while (*(int*)num < *(int*)b.first->content && *(int*)num > *(int*)b.first->next->content)
		{
			i++;
			b.first = b.first->next;
		}
	}
	return (i);
}

void	find_bestnode(t_stack a, t_stack b, t_best *best_node)
{
	t_best	current;
	//int		sum;
	int		index_a;
	int		index_b;
	// int		i;
	// int		k;

	//sum = 0;
	// i = 0;
	index_a = 0;
	init_tbest(&current);
	if (b.len < 2)
	{
		//best_node->sum = 0;
		*best_node = current;
		printf("best_node movements - %d ", best_node->rs);
		a.first = a.first->next;
		index_a++;
		return;
	}
	best_node->sum = INT_MAX;
	// a.last->next = NULL;
	printf("best_node movements - %d ", best_node->sum);
	fflush(0);
	while (index_a < a.len)
	{
		printf("abc");
		fflush(0);
		//cost_a = ft_min(i, a.len - i);
		index_b = find_pos_inb(b, a.first->content);
		printf("pos_b - %d\n", index_b);
		fflush(0);
		//cost_b = ft_min(k, b.len - k);
		get_direction(index_a, index_b, a.len, b.len, &current);
		//printf("current_sum = %d, best_node.sum = %d, pos = %d\n", current.sum, best_node->sum, *(int*) best_node->pos->content);
		if (current.sum < best_node->sum)
		{
			*best_node = current;
			best_node->pos = a.first;
		}
		//sum = cost_a + cost_b;
		// if (sum < min.sum)
		// {
		// 	min.sum = sum;
		// 	min.pos = a.first;
		// 	if (i < (a.len / 2 + 1))
		// 		min.ra = cost_a;
		// 	else
		// 		min.rra = cost_a;
		// 	if (k < (b.len / 2 + 1))
		// 		min.rb = cost_b;
		// 	else
		// 		min.rrb = cost_b;
		// }
		// a.first = a.first->next;
		index_a++;
	}
}
