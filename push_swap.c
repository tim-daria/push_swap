/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:01:46 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/24 15:38:53 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_doubles(t_list *temp, void *num)
{
	while (temp)
	{
		if (*(int *)num == *(int *)temp->content)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

static int	free_list_array(t_list *lst, char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
		free (str_array[i++]);
	free (str_array);
	if (lst)
		ft_lstclear(&lst, del);
	return (1);
}
static int	convert_input(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**str_array;
	t_list	*temp;
	int		*num;

	str_array = NULL;
	if (argc == 2)
		str_array = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		str_array = malloc(argc * sizeof(char *));
		if (str_array == NULL)
			return (free_list_array(stack_a->first, str_array));
		while (argc-- > 1)
		{
			str_array[i] = argv[i + 1];
			i++;
		}
		str_array[i] = NULL;
	}
	i = 0;
	//num = malloc(sizeof(int));
	if (str_array == NULL)
		return (free_list_array(stack_a->first, str_array));
	// *num = ft_atoi(str_array[i++]);
	// stack_a->first = ft_lstnew(num);
	// if (stack_a->first == NULL)
	// 	return (1); // and free all allocated memory
	temp = stack_a->first;
	//stack_a->len = 1;
	while (str_array[i] != NULL)
	{
		num = malloc(sizeof(int));
		if (num == NULL || safe_atoi(str_array[i], num) == -1
			|| check_doubles(temp, num) == -1)
			return (free_list_array(stack_a->first, str_array));
			//safe_atoi(str_array[i++], &num); //here safe atoi
		//if num == NULL (check failed)
		if (stack_a->len == 0)
		{
			stack_a->first = ft_lstnew(num);
			temp = stack_a->first;
		}
		else
			ft_lstadd_back(&temp, ft_lstnew(num));
		if (stack_a->first == NULL)
			return (free_list_array(stack_a->first, str_array));
		//temp = stack_a->first;
		stack_a->len++;
		i++;
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

static int	already_sorted(t_list *lst)
{
	while (lst)
	{
		if (lst->content < lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_best	best_node;

	if (argc > 1)
	{
		stack_a.first = NULL;
		stack_b.first = NULL;
		stack_b.len = 0;
		if (convert_input(argc, argv, &stack_a) == 1)
			ft_putendl_fd("Error", 2);
		if (already_sorted(stack_a.first))
			return (0);
		while (stack_a.len > 3)
		{
			init_tbest(&best_node);
			find_bestnode(stack_a, stack_b, &best_node);
			move(&stack_a, &stack_b, &best_node);
		}
		sort3(&stack_a);
		ft_push_toa(&stack_a, &stack_b);
		ft_lstclear(&stack_a.first, del);
	}
}
