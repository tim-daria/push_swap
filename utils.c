/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:27:38 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/17 17:25:28 by dtimofee         ###   ########.fr       */
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

int	ft_abs(int i)
{
	if (i < 0)
		return (i * (-1));
	return (i);
}
t_list *ft_before_last(t_list *lst, t_list *last)
{
	t_list * current;

	current = lst;
	while (current->next != last)
	{
		current = current->next;
	}
	return (current);
}

void	init_tbest(t_best *src)
{
	src->rs = 0;
	src->rrs = 0;
	src->ra = 0;
	src->rra = 0;
	src->rb = 0;
	src->rrb = 0;
	src->sum = 0;
}
