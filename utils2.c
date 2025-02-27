/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:16:14 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/25 17:14:01 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_tstack(t_stack *src)
{
	src->first = NULL;
	src->last = NULL;
	src->len = 0;
	src->min = INT_MAX;
	src->max = INT_MIN;
}

int	greater_than(int a, int b)
{
	return (a > b);
}

int	less_than(int a, int b)
{
	return (a < b);
}

long	free_list_array(t_list *lst, char **str_array)
{
	if (str_array)
		free (str_array);
	if (lst)
		ft_lstclear(&lst, del);
	return (0);
}
