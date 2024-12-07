/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:16:52 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/07 16:56:01 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_int_list **stack, char c, int verbose)
{
	if (*stack)
		*stack = (*stack)->previous;
	if (verbose)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rrotate(t_int_list **stack, char c, int verbose)
{
	if (*stack)
		*stack = (*stack)->next;
	if (verbose)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rr(t_int_list **stacka, t_int_list **stackb, int verbose)
{
	if (*stacka)
		*stacka = (*stacka)->previous;
	if (*stackb)
		*stackb = (*stackb)->previous;
	if (verbose)
		ft_putendl_fd("rr", 1);
}

void	rrr(t_int_list **stacka, t_int_list **stackb, int verbose)
{
	if (*stacka)
		*stacka = (*stacka)->next;
	if (*stackb)
		*stackb = (*stackb)->next;
	if (verbose)
		ft_putendl_fd("rrr", 1);
}

void	push(t_int_list **pushed, t_int_list **poped, char c, int verbose)
{
	t_int_list	*node_poped;

	node_poped = pop(poped);
	if (node_poped)
	{
		native_push(pushed, &node_poped);
		if (verbose)
		{
			ft_putchar_fd('p', 1);
			ft_putchar_fd(c, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}
