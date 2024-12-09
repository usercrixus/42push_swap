/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:06:20 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/09 13:18:16 by achaisne         ###   ########.fr       */
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

int	split_len(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	free_split(char **argv, int is_alloc)
{
	int	i;

	if (is_alloc)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

int	set_args(int *argc, char ***argv)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		(*argc) = split_len(*argv);
		return (1);
	}
	else
	{
		*argv = &(*argv)[1];
		(*argc)--;
		return (0);
	}
}
