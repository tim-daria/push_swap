/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 16:28:25 by dtimofee          #+#    #+#             */
/*   Updated: 2025-02-27 16:28:25 by dtimofee         ###   ########.fr       */
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

int	check_doubles(t_list *temp, int *num)
{
	while (temp)
	{
		if (*num == *(int *)temp->content)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	already_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	if (temp->next == NULL)
		return (1);
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
