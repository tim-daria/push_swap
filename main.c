/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:01:46 by dtimofee          #+#    #+#             */
/*   Updated: 2025/01/17 16:03:56 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	convert_input(char *str)
{
	int	i;
	char	**str_array;
	t_list	*start;
	t_list	*temp;

	str_array = ft_split(str, ' ');
	i = 0;
	//safe_atoi for input_check
	start = ft_lstnew((ft_atoi(str_array[i++])));
	temp = start;
	while (str_array[i] != NULL)
	{
		ft_lstadd_back(&temp, ft_lstnew(ft_atoi(str_array[i])));
		i++;
	}
	while (start->next != NULL)
	{
		printf("%d ", start->content);
		start = start->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc != 2 || convert_input(argv[1]) == 1)
			ft_putendl_fd("ERROR", 2);
	}
	return (0);
}
