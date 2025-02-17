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
	return (i * (-1));
}
t_list *ft_before_last(t_list *lst, t_list *last)
{
	while (lst->next != last)
	{
		lst = lst->next;
	}
	return (lst);
}
