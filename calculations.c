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

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
	return (b);
}

int	find_pos(t_stack b, void *num)
{
	int	count;

	if (*(int*)num > b.max || *(int*)num < b.min)
	{
		while (*(int*)b.first->content != b.max)
		{
			rb(b);
			count++;
		}
	}
}
t_best	calculate_cost(t_stack a, t_stack b)
{
	t_best	min;
	int		sum;
	int		cost_a;
	int		cost_b;
	int		i;

	sum = 0;
	i = 0;
	min.sum = INT_MAX;
	if (b.len < 2)
	{
		min.pos = a.first;
		return (min);
	}
	while (a.first != a.last)
	{
		cost_a = ft_min (i, a.len - i);
		cost_b = find_pos(b, a.first->content);
		sum = cost_a + cost_b;
		if (sum < min.sum)
		{
			min.sum = sum;
			min.pos = a.first;
			if (i < (a.len / 2 + 1))
				min.ra = cost_a;
			else
				min.rra = cost_a;
		}
		a.first = a.first->next;
	}
	return (min);
}
