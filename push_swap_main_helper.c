/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:06:20 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/06 15:07:28 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	populate_a(t_int_list **a, char **argv, int argc)
{
	int			i;
	int			number;
	t_int_list	*node;

	i = 0;
	while (i < argc)
	{
		number = atoi(argv[i]);
		node = create_node(number);
		if (!node)
			return (0);
		insert(a, &node);
		i++;
	}
	return (1);
}

void	close_project(t_int_list *a)
{
	while (a)
	{
		free(pop(&a));
	}
}
