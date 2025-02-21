/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:42:13 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/17 15:09:48 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_best	ra_rb(int i, int j)
{
	t_best	dir;

	init_tbest(&dir);
	dir.rr = ft_min(i, j);
	if (i - j < 0)
		dir.rb = ft_abs(i - j);
	else
		dir.ra = ft_abs(i - j);
	dir.sum = dir.rr + dir.ra + dir.rb;
	return (dir);
}

static t_best	rra_rrb(int i, int j, int size_a, int size_b)
{
	t_best	dir;

	init_tbest(&dir);
	dir.rrr = ft_min(size_a - i, size_b - j);
	if ((size_a - i) < (size_b - j))
		dir.rrb = ft_abs((size_a - i) - (size_b - j));
	else
		dir.rra = ft_abs((size_a - i) - (size_b - j));
	dir.sum = dir.rrr + dir.rra + dir.rrb;
	return (dir);
}

static t_best	ra_rrb(int i, int j, int size_b)
{
	t_best	dir;

	init_tbest(&dir);
	dir.ra = i;
	dir.rrb = size_b - j;
	dir.sum = dir.ra + dir.rrb;
	return (dir);
}

static t_best	rra_rb(int i, int j, int size_a)
{
	t_best	dir;

	init_tbest(&dir);
	dir.rra = size_a - i;
	dir.rb = j;
	dir.sum = dir.rra + dir.rb;
	return (dir);
}

void	get_direction(int i, int j, int size_a, int size_b, t_best *current)
{
	t_best	ra_rb_value;
	t_best	ra_rrb_value;
	t_best	rra_rb_value;
	t_best	rra_rrb_value;

	ra_rb_value = ra_rb(i, j);
	ra_rrb_value = ra_rrb(i, j, size_b);
	rra_rb_value = rra_rb(i, j, size_a);
	rra_rrb_value = rra_rrb(i, j, size_a, size_b);
	if (ra_rb_value.sum < current->sum)
		*current = ra_rb_value;
	if (ra_rrb_value.sum < current->sum)
		*current = ra_rrb_value;
	if (rra_rb_value.sum < current->sum)
		*current = rra_rb_value;
	if (rra_rrb_value.sum < current->sum)
		*current = rra_rrb_value;
}
