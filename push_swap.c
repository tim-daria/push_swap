/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:01:46 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/26 18:16:25 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_stack(char	**str_array, t_stack *stack_a, int should_free)
{
	int		i;
	int		*num;

	i = 0;
	while (str_array[i] != NULL)
	{
		num = malloc(sizeof(int));
		if (num == NULL)
			return (free_list_array(stack_a->first, str_array, should_free));
		if (is_int(str_array[i], num) == -1
			|| check_doubles(stack_a->first, num) == -1)
		{
			free(num);
			return (free_list_array(stack_a->first, str_array, should_free));
		}
		if (stack_a->len == 0)
			stack_a->first = ft_lstnew(num);
		else
			ft_lstadd_back(&stack_a->first, ft_lstnew(num));
		if (stack_a->first == NULL)
			return (free_list_array(stack_a->first, str_array, should_free));
		stack_a->len++;
		i++;
	}
	return (1);
}

static char	**multiple_arg(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**str_array;

	i = 0;
	str_array = malloc(argc * sizeof(char *));
	if (str_array == NULL)
		return ((char **)free_list_array(stack_a->first, str_array, argc == 2));
	while (argc-- > 1)
	{
		str_array[i] = argv[i + 1];
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}

static int	convert_input(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**str_array;

	str_array = NULL;
	if (argc == 2)
		str_array = ft_split(argv[1], ' ');
	else
		str_array = multiple_arg(argc, argv, stack_a);
	if (str_array == NULL)
		return (free_list_array(stack_a->first, str_array, argc == 2));
	if (!fill_stack(str_array, stack_a, argc == 2))
		return (0);
	if (argc == 2)
	{
		i = 0;
		while (str_array[i] != NULL)
			free (str_array[i++]);
	}
	free (str_array);
	return (1);
}

static void	sort_largestack(t_stack *stack_a, t_stack *stack_b)
{
	t_best	best_node;

	stack_a->last = ft_lstlast(stack_a->first);
	stack_a->last->next = stack_a->first;
	while (stack_a->len > 3)
	{
		init_tbest(&best_node);
		find_bestnode(*stack_a, *stack_b, &best_node);
		move(stack_a, stack_b, &best_node);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		init_tstack(&stack_a);
		init_tstack(&stack_b);
		if (!convert_input(argc, argv, &stack_a))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if (already_sorted(stack_a.first) == 1)
		{
			ft_lstclear(&stack_a.first, del);
			return (0);
		}
		sort_largestack(&stack_a, &stack_b);
		sort3(&stack_a);
		if (stack_b.len > 0)
			ft_push_toa(&stack_a, &stack_b);
		stack_a.last->next = NULL;
		ft_lstclear(&stack_a.first, del);
	}
}
