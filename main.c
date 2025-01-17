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
int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc != 2 || check_input(argv[1]) == 1)
			ft_putendl_fd("ERROR", 1);
	}
	return (0);
}
