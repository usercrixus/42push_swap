/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:23:46 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/07 17:03:08 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_int_list **start, t_int_list **end)
{
	t_int_list	*buffer;
	int			i;

	if (!*start || !*end)
		return (0);
	i = 1;
	buffer = *start;
	while (buffer != *end)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

int	is_min(t_int_list *a, int x)
{
	t_int_list	*end;
	t_int_list	*buffer;

	if (!a)
		return (1);
	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c < x)
			return (0);
		buffer = buffer->next;
	}
	if (buffer->c < x)
		return (0);
	return (1);
}

int	is_max(t_int_list *a, int x)
{
	t_int_list	*end;
	t_int_list	*buffer;

	if (!a)
		return (1);
	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c > x)
			return (0);
		buffer = buffer->next;
	}
	if (buffer->c > x)
		return (0);
	return (1);
}

t_int_list	*get_maximum(t_int_list *a)
{
	t_int_list	*buffer;

	if (!a)
		return (0);
	buffer = a;
	while (!is_max(a, buffer->c))
	{
		buffer = buffer->next;
	}
	return (buffer);
}

int	is_sorted(t_int_list *a)
{
	t_int_list	*buffer;
	t_int_list	*end;
	int			i;

	if (!a)
		return (0);
	buffer = a;
	end = a->previous;
	while (buffer != end)
	{
		if (buffer->c < buffer->next->c)
			return (0);
		buffer = buffer->next;
	}
	return (1);
}
