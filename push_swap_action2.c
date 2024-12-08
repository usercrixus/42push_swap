/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:15:04 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 19:56:55 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_int_list **stack, char c, int verbose)
{
	t_int_list	*poped;
	t_int_list	*ins;

	if (list_len(stack, &(*stack)->previous) > 1)
	{
		poped = pop(stack);
		if (poped)
		{
			ins = (*stack)->previous;
			insert(&ins, &poped);
			if (verbose)
			{
				ft_putchar_fd('s', 1);
				ft_putchar_fd(c, 1);
				ft_putchar_fd('\n', 1);
			}
		}
	}
}
