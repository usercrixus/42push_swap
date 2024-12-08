/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:07:16 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 20:10:19 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_sort_three(t_int_list **a, int num1, int num2, int num3)
{
	if (num1 > num2 && num1 < num3 && num2 < num3)
		swap(a, 'a', 1);
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		rotate(a, 'a', 1);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		rrotate(a, 'a', 1);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		swap(a, 'a', 1);
		rrotate(a, 'a', 1);
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		swap(a, 'a', 1);
		rotate(a, 'a', 1);
	}
}

void	sort_three(t_int_list **a)
{
	int			num1;
	int			num2;
	int			num3;

	num1 = (*a)->previous->c;
	num2 = (*a)->previous->previous->c;
	num3 = (*a)->c;
	manage_sort_three(a, num1, num2, num3);
}
