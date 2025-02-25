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
#include <stdio.h>

int	safe_atoi(const char *nptr, int *num)
{
	//int	result;
	int	i;
	int	sign;

	//result = 0;
	//num = NULL;
	if (nptr == NULL || num == NULL)
		return (-1);
	*num = 0;
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
	{
		if (*num > INT_MAX / 10 || (*num == INT_MAX / 10
				&& ((nptr[i] - '0') > INT_MAX % 10)))
			return (-1);
		*num = *num * 10 + nptr[i] - '0';
		//result = result * 10 + nptr[i] - '0';
		i++;
	}
	*num = *num * sign;
	//printf("%d\n - num", *num);
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
