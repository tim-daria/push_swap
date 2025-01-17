/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 15:01:46 by dtimofee          #+#    #+#             */
/*   Updated: 2025-01-16 15:01:46 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_print(t_list *first)
{
	t_list	*p = first->next;
	while (p != first)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void	ft_print_back(t_list *first)
{
	t_list	*p = first->prev;
	while (p != first)
	{
		printf("%d ", p->data);
		p = p->prev;
	}
}
int	main(void)
{
	t_list	z, a = {3}, b = {21}, c = {14};
	t_list	*first = &z;

	z.next = &a;
	z.prev = &c;
	a.next = &b;
	a.prev = &z;
	b.next = &c;
	b.prev = &a;
	c.next = &z;
	c.prev = &b;
	ft_print(first);
	ft_print_back(first);
	// while (p != first)
	// {
	// 	printf("%d ", p->data);
	// 	p = p->next;
	// }

}
