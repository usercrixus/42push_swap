/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:04:33 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/07 03:49:33 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*populate_tab(char **tab, int size)
{
	int	*list;
	int	i;

	list = (int *)malloc(sizeof(int) * size);
	if (!list)
		return (0);
	i = 0;
	while (i < size)
	{
		list[i] = atoi(tab[i]);
		i++;
	}
	return (list);
}

void	sort_int(int *tab, int size)
{
	int		buffer;
	int		trigger;
	int		i;

	trigger = 1;
	while (trigger)
	{
		trigger = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				buffer = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = buffer;
				trigger = 1;
			}
			i++;
		}
	}
}

void	set_buffer_value(t_int_list *buffer, int *list, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		if (buffer->c == list[i])
			break ;
		i++;
	}
	if (buffer->c == list[i])
		buffer->c = i;
}

int	normalize(t_int_list **a, char **tab, int size)
{
	int			i;
	int			*list;
	t_int_list	*buffer;

	list = populate_tab(tab, size);
	if (!list)
		return (0);
	sort_int(list, size);
	buffer = *a;
	while (buffer != (*a)->previous)
	{
		set_buffer_value(buffer, list, size);
		buffer = buffer->next;
	}
	set_buffer_value(buffer, list, size);
	return (free(list), 1);
}
