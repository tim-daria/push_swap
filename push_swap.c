/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:01:46 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/17 16:33:59 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static int	ft_arraylen(char **str_array)
// {
// 	int	len;

// 	len = 0;
// 	while (str_array[len] != NULL)
// 		len++;
// 	return (len);
// }
static int	convert_input(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**str_array;
	t_list	*temp;
	int		*num;
	// int		len_array;

	str_array = NULL;
	if (argc == 2)
		str_array = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		str_array = malloc(argc * sizeof (char*));
		if (str_array == NULL)
			return (1);
		while (argc-- > 1)
		{
			// str_array[i] = malloc(sizeof(int));
			// if (str_array[i] == NULL)
			// 	return (1);
			str_array[i] = argv[i + 1];
			i++;
		}
		str_array[i] = NULL;
	}
	if (str_array == NULL) //|| len_array == 0 //safe_atoi for input_check
		return (1);
	//len_array = ft_arraylen(str_array);
	i = 0;
	num = malloc(sizeof(int));
	if (num == NULL)
		return (1); // delete all allocated memory (str_array)
	*num = ft_atoi(str_array[i++]);
	stack_a->first = ft_lstnew(num);
	if (stack_a->first == NULL)
		return (1); // and free all allocated memory
	temp = stack_a->first;
	stack_a->len = 1;
	while (str_array[i] != NULL)
	{
		num = malloc(sizeof(int));
		if (num == NULL) // delete all allocated memory
			return (1);
		*num = ft_atoi(str_array[i++]);
		ft_lstadd_back(&temp, ft_lstnew(num));
		stack_a->len++;
	}
	stack_a->last = ft_lstlast(temp);
	stack_a->last->next = stack_a->first;
	free (str_array);
	return (0);
}

void	sort3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack->first->content;
	b = *(int *)stack->first->next->content;
	c = *(int *)stack->last->content;
	if (a > b && a > c)
	{
		stack->max = a;
		if (c < b)
		{
			stack->min = c;
			swap(stack);
			rev_rotate_ab(stack);
			ft_putendl_fd("rra", 1);
		}
		else
		{
			stack->min = b;
			rotate_ab(stack);
			ft_putendl_fd("ra", 1);
		}
	}
	else if (c > b && c > a)
	{
		stack->max = c;
		if (a < b)
			stack->min = a;
		else
		{
			stack->min = b;
			swap(stack);
		}
	}
	else
	{
		stack->max = b;
		if (a < b)
		{
			stack->min = a;
			swap(stack);
			rotate_ab(stack);
			ft_putendl_fd("ra", 1);
		}
		else
		{
			stack->min = b;
			rev_rotate_ab(stack);
			ft_putendl_fd("rra", 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_stack	stack_a;
		t_stack	stack_b;
		t_best	best_node;
		// t_list	*temp; // todo remove

		stack_a.first = NULL;
		stack_b.first = NULL;
		stack_b.len = 0;
		// if (argc != 2 || convert_input(argv[1], &stack_a) == 1)
		// 	ft_putendl_fd("Error", 2);
		if (convert_input(argc, argv, &stack_a) == 1)
			ft_putendl_fd("Error", 2);
		// while (stack_a.first != NULL)
		// {
		// 	printf("%d ", *(int *)stack_a.first->content);
		// 	stack_a.first = stack_a.first->next;
		// }
		// printf("\n");
		// fflush(0);
		while (stack_a.len > 3)
		{
			find_bestnode(stack_a, stack_b, &best_node);
			// printf("best node sum = %d\n", best_node.sum);
			// fflush(0);
			move(&stack_a, &stack_b, &best_node);
		}
		//printf("%d - stack_a_len\n", stack_a.len);
		//transfer(&stack_a, &stack_b);
		// while (stack_a != NULL)
		// {
		// 	printf("%d ", *(int *)stack_a->content);
		// 	stack_a = stack_a->next;
		// }
		// printf("\n");
		// // while (stack_b->next != stack_b)
		// while (stack_b != NULL)
		// {
		// 	printf("%d ", *(int *)stack_b->content);
		// 	fflush(0);
		// 	// temp = stack_b->next;
		// 	// ft_lstdelone(stack_b, free);
		// 	// stack_b = temp;
		// 	stack_b = stack_b->next;
		// }
		// printf("\n");


		// stack_b.last->next = NULL;


		// while (stack_b.first != NULL)
		// {
		// 	printf("%d ", *(int *)stack_b.first->content);
		// 	stack_b.first = stack_b.first->next;
		// }
		// printf("%d - stack_a_len\n", stack_a.len);
		// fflush(0);
		// printf("%d - stack_a_first value\n", *(int *)stack_a.first->content);
		// fflush(0);
		// printf("%p - stack_a_first \n", stack_a.first);
		// printf("%d - stack_a_first next value\n", *(int *)stack_a.first->next->content);
		// printf("%p - stack_a_first next \n", stack_a.first->next);
		// fflush(0);
		// printf("%d - stack_a_first next next value\n", *(int *)stack_a.first->next->next->content);
		// printf("%p - stack_a_first next next\n", stack_a.first->next->next);
		// printf("%d - stack_a_last value\n", *(int *)stack_a.last->content);
		// printf("%p - stack_a_last \n", stack_a.last);
		// printf("%p - stack_a_last next\n", stack_a.last->next);
		sort3(&stack_a);
		ft_push_toa(&stack_a, &stack_b);
		// printf("%d - stack_a_first value\n", *(int *)stack_a.first->content);
		// fflush(0);
		// printf("%p - stack_a_first \n", stack_a.first);
		// fflush(0);
		// printf("%d - stack_a_first next value\n", *(int *)stack_a.first->next->content);
		// fflush(0);
		// printf("%p - stack_a_first next \n", stack_a.first->next);
		// fflush(0);
		// printf("%d - stack_a_first next next value\n", *(int *)stack_a.first->next->next->content);
		// printf("%p - stack_a_first next next\n", stack_a.first->next->next);
		// printf("%d - stack_a_last value\n", *(int *)stack_a.last->content);
		// printf("%p - stack_a_last \n", stack_a.last);
		// printf("%p - stack_a_last next\n", stack_a.last->next);
		// fflush(0);
		//printf("%d - stack_a_len\n", stack_a.len);
		// stack_a.last->next = NULL;
		// while (stack_a.first != NULL)
		// {
		// 	printf("%d ", *(int *)stack_a.first->content);
		// 	stack_a.first = stack_a.first->next;
		// }
		// printf("\n");
		// // while (stack_b->next != stack_b)
		// while (stack_b != NULL)
		// {
		// 	printf("%d ", *(int *)stack_b->content);
		// 	fflush(0);
		// 	// temp = stack_b->next;
		// 	// ft_lstdelone(stack_b, free);
		// 	// stack_b = temp;
		// 	stack_b = stack_b->next;
		// }
		// printf("\n");
	}
	return (0);
}
