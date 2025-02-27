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

static long	ft_atol(const char *nptr)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	while (ft_isdigit(nptr[i]))
		result = result * 10 + nptr[i++] - '0';
	return (result * sign);
}

int	is_int(const char *nptr, int *num)
{
	int		i;
	long	result;

	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] == '\0')
		return (-1);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (-1);
		i++;
	}
	result = ft_atol(nptr);
	if (result > INT_MAX || result < INT_MIN)
		return (-1);
	*num = (int)result;
	return (0);
}

void	init_tstack(t_stack *src)
{
	src->first = NULL;
	src->last = NULL;
	src->len = 0;
	src->min = INT_MAX;
	src->max = INT_MIN;
}
