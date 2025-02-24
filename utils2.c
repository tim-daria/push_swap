/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:16:14 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/24 12:24:29 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	safe_atoi(const char *nptr, int *num)
{
	//int	result;
	int	i;
	int	sign;

	//result = 0;
	//num = NULL;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i++] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		//i++;
	}
	while (ft_isdigit(nptr[i++]))
	{
		*num = *num * 10 + nptr[i] - '0';
		//result = result * 10 + nptr[i] - '0';
		//i++;
	}
	*num = *num * sign;
	return (0);
}
