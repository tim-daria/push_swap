/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:00:47 by dtimofee          #+#    #+#             */
/*   Updated: 2025/01/17 15:32:47 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"
#include <stdlib.h>

void	rotate_clockwise(t_list **stack_b, t_list **last);
void	ft_push_tob(t_list **dst, t_list **last, void *num);
void	*ft_pop(t_list **src);
void	transfer(t_list **stack_a, t_list **stack_b);
void	ft_push_toa(t_list **dst, t_list **src);
#endif
