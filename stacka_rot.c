/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimofee <dtimofee@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 16:24:49 by dtimofee          #+#    #+#             */
/*   Updated: 2025-02-27 16:24:49 by dtimofee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacka_rot_direction(t_best *dir, int index_a, int len_a)
{
	t_best	ra;
	t_best	rra;

	init_tbest(&ra);
	init_tbest(&rra);
	ra.ra = index_a;
	rra.rra = len_a - index_a;
	if (ra.ra < rra.rra)
		*dir = ra;
	else
		*dir = rra;
}
