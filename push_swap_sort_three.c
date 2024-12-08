/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:07:16 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 19:58:04 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	identify_nums_three(t_int_list **stacks, int num1, int num2, int num3)
{
	if (num1 > num2 && num1 < num3 && num2 < num3)
		swap(stacks, 'a', 1);
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		rotate(stacks, 'a', 1);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		rrotate(stacks, 'a', 1);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		swap(stacks, 'a', 1);
		rrotate(stacks, 'a', 1);
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		swap(stacks, 'a', 1);
		rotate(stacks, 'a', 1);
	}
}

void	sort_three(t_int_list **stacks)
{
	int			num1;
	int			num2;
	int			num3;

	num1 = (*stacks)->previous->c;
	num2 = (*stacks)->previous->previous->c;
	num3 = (*stacks)->c;
	identify_nums_three(stacks, num1, num2, num3);
}
