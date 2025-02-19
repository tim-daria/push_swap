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
	t_best dir;

	init_tbest(&dir);
	dir.sum = ft_min(i, j) + ft_abs(i - j);
	dir.rs = ft_min(i, j);
	if (i - j < 0)
		dir.rb = ft_abs(i - j);
	else
		dir.ra = ft_abs(i - j);
	return (dir);
}
static t_best	rra_rrb(int i, int j, int size_a, int size_b)
{
	t_best dir;

	init_tbest(&dir);
	dir.sum = ft_min(size_a - i, size_b - j) + ft_abs((size_a - i) - (size_b - j));
	dir.rrs = ft_min(size_a - i, size_b - j);
	if ((size_a - i) - (size_b - j) < 0)
		dir.rrb = ft_abs((size_a - i) - (size_b - j));
	else
		dir.rra = ft_abs((size_a - i) - (size_b - j));
	return (dir);
}

static t_best	ra_rrb(int i, int j, int size_b)
{
	t_best dir;

	init_tbest(&dir);
	dir.sum = i + size_b - j;
	dir.ra = i;
	dir.rrb = size_b - j;
	return (dir);
}

static t_best	rra_rb(int i, int j, int size_a)
{
	t_best dir;

	dir.sum = size_a - i + j;
	dir.rra = size_a - i;
	dir.rb = j;
	return (dir);
}
void	get_direction(int i, int j, int size_a, int size_b, t_best *current)
{
	t_best	ra_rb_value;
	t_best	ra_rrb_value;
	t_best	rra_rb_value;
	t_best	rra_rrb_value;

	ra_rb_value = ra_rb(i, j);
	*current = ra_rb_value;
	ra_rrb_value = ra_rrb(i, j, size_b);
	if (ra_rrb_value.sum < current->sum)
		*current = ra_rrb_value;
	rra_rb_value = rra_rb(i, j, size_a);
	if (rra_rb_value.sum < current->sum)
		*current = rra_rb_value;
	rra_rrb_value = rra_rrb(i, j, size_a, size_b);
	if (rra_rrb_value.sum < current->sum)
		*current = rra_rrb_value;
}
