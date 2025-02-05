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
static void	rotate_clockwise(t_list **stack_b, t_list **last)
{
	*stack_b = (*stack_b)->next;
	*last = (*last)->next;
}
static void	ft_push_tob(t_list **dst, t_list **last, void *num)
{
	//t_list	*last = NULL;

	if (*dst == NULL)
	{
		*dst = ft_lstnew(num);
		//(*dst)->next = *dst;
		*last = *dst;
	}
	else
	{
		ft_lstadd_front(dst, ft_lstnew(num));
		printf("no");
		fflush(0);
		(*last)->next = *dst;
		printf("yes");
		fflush(0);
	}
}
static void	*ft_pop(t_list **src)
{
	t_list	*temp;
	void	*num;

	temp = *src;
	num = temp->content;
	*src = temp->next;
	free(temp);
	return (num);
}
static void	transfer(t_list **stack_a, t_list **stack_b)
{
	void	*num;
	int		count;
	void	*max;
	void	*min;
	t_list	*last;

	max = (*stack_a)->content;
	min = (*stack_a)->content;
	last = NULL;
	count = 0;
	printf("b");
	while (*stack_a != NULL)
	{
		num = ft_pop(stack_a);
		printf("%d ", *(int*)num);
		fflush(0);
		count++;
		//size = ft_lstsize(*stack_b);
		printf("%d", count);
		// if (*(int*)num > *(int*)max)
		// 	max = num;
		if (count <= 2)
		{
			printf("a");
			fflush(0);
			ft_push_tob(stack_b, &last, num);
		}
		else
		 {
			printf("c");
			fflush(0);
			if ((*(int*)num > *(int*)max && (*stack_b)->content == max) ||
				(*(int*)num < *(int*)min && (*stack_b)->content == min))
			{
				ft_push_tob(stack_b, &last, num);
				printf("where");
				fflush(0);
			}
			else if (*(int*)num > *(int*)max && (*stack_b)->content != max)
			{
				printf("I");
				fflush(0);
				while ((*stack_b)->content != max)
					rotate_clockwise(stack_b, &last);
				ft_push_tob(stack_b, &last, num);
			}
			else if (*(int*)num < *(int*)min && (*stack_b)->content != min)
			{
				while ((*stack_b)->content != min)
					rotate_clockwise(stack_b, &last);
				ft_push_tob(stack_b, &last, num);
			}
			else
			//if (*(int*)num < *(int*)max)
			{
				printf("am");
				fflush(0);
				while (*(int*)num > *(int*)(*stack_b)->content)
					rotate_clockwise(stack_b, &last);
				ft_push_tob(stack_b, &last, num);
			}
		}
		if (*(int*)num > *(int*)max)
			max = num;
		printf("%d - max\n", *(int*)max);
		fflush(0);
		if (*(int*)num < *(int*)min)
			min = num;
		printf("%d - min\n ", *(int*)min);
		fflush(0);
	}
	last->next = NULL;
}
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
