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

static int	ft_arraylen(char **str_array)
{
	int	len;

	len = 0;
	while (str_array[len] != NULL)
		len++;
	return (len);
}
static int	convert_input(char *str, t_list	**start)
{
	int		i;
	char	**str_array;
	t_list	*temp;
	int		*num;
	int		len_array;

	str_array = ft_split(str, ' ');
	len_array = ft_arraylen(str_array);
	if (str_array == NULL || len_array == 0) //safe_atoi for input_check
		return (1);
	i = 0;
	num = malloc(sizeof(int));
	if (num == NULL)
		return (1);
	*num = ft_atoi(str_array[i++]);
	*start = ft_lstnew(num);
	temp = *start;
	while (str_array[i] != NULL)
	{
		num = malloc(sizeof(int));
		if (num == NULL) // delete all allocated memory
			return (1);
		*num = ft_atoi(str_array[i++]);
		ft_lstadd_back(&temp, ft_lstnew(num));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_list	*stack_a;
		t_list	*stack_b;
		// t_list	*temp; // todo remove

		stack_a = NULL;
		stack_b = NULL;
		if (argc != 2 || convert_input(argv[1], &stack_a) == 1)
			ft_putendl_fd("ERROR", 2);

		// while (stack_a != NULL)
		// {
		// 	printf("%d ", *(int *)stack_a->content);
		// 	stack_a = stack_a->next;
		// }
		// printf("\n");
		transfer(&stack_a, &stack_b);
		while (stack_a != NULL)
		{
			printf("%d ", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		printf("\n");
		// while (stack_b->next != stack_b)
		while (stack_b != NULL)
		{
			printf("%d ", *(int *)stack_b->content);
			fflush(0);
			// temp = stack_b->next;
			// ft_lstdelone(stack_b, free);
			// stack_b = temp;
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	return (0);
}
