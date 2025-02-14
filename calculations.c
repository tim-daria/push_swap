/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 08:38:55 by dtimofee          #+#    #+#             */
/*   Updated: 2025-02-14 08:38:55 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (*(int*)num > *(int*)b.first->content || *(int*)num < *(int*)b.first->next->content)
		{
			i++;
			b.first = b.first->next;
		}
	}
	return (i);
}
static void	get_direction(int i, int j, int size_a, int size_b, t_best *min)
{
	int	ra_rb;
	int	ra_rrb;
	int	rra_rb;
	int	rra_rrb;
	int	min;

	ra_rb = ft_min(i, j) + ft_abs(i - j);
	//min = ra_rb;
	ra_rrb = i + size_b - j;
	// if (ra_rrb < min)
	// 	min = ra_rrb;
	rra_rb = size_a - i + j;
	rra_rrb = ft_min(size_a - i, size_b - j) + ft_abs((size_a - i) - (size_b - j));
}
t_best	calculate_cost(t_stack a, t_stack b)
{
	t_best	min;
	//int		sum;
	int		index_a;
	int		index_b;
	// int		i;
	// int		k;

	//sum = 0;
	// i = 0;
	index_a = 0;
	//min.sum = INT_MAX;
	a.last->next = NULL;
	if (b.len < 2)
	{
		min.pos = a.first;
		return (min);
	}
	while (a.first != NULL)
	{
		//cost_a = ft_min(i, a.len - i);
		index_b = find_pos_inb(b, a.first->content);
		//cost_b = ft_min(k, b.len - k);
		get_direction(index_a, index_b, a.len, b.len, &min);
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
		a.first = a.first->next;
		index_a++;
	}
	return (min);
}
