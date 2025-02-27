/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:00:47 by dtimofee          #+#    #+#             */
/*   Updated: 2025/02/25 15:07:00 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	t_list	*first;
	t_list	*last;
	int		len;
	int		min;
	int		max;
}	t_stack;

typedef struct s_best
{
	int		sum;
	int		rr;
	int		rrr;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
}	t_best;

void	swap(t_stack *stack);
void	rotate_ab(t_stack *stack);
void	rev_rotate_ab(t_stack *stack);
void	do_rotations(t_stack *stack_a, t_stack *stack_b, t_best *to_move);
void	find_bestnode(t_stack a, t_stack b, t_best *best_node);
void	get_direction(int i, int j, int size_a, int size_b, t_best *current);
void	move(t_stack *stack_a, t_stack *stack_b, t_best *to_move);
void	sort3(t_stack *stack);
int		ft_min(int a, int b);
int		ft_abs(int i);
void	init_tbest(t_best *src);
void	init_tstack(t_stack *src);
void	del(void *b);
int		is_int(const char *nptr, int *num);
t_list	*ft_before_last(t_list *lst, t_list *last);
void	ft_push_toa(t_stack *stack_a, t_stack *stack_b);
void	stacka_rot_direction(t_best *dir, int index_a, int len_a);
int	find_pos_ina(t_stack *a, void *num);

#endif
