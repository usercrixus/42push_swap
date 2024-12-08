/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:40:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 18:15:31 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rooting_next(t_int_list **a, t_int_list **b, char *line)
{
	if (ft_strncmp(line, "sb\n", 4) == 0)
		return (swap(b, 'b', 0), 1);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		return (swap(a, 'a', 0), 1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
	{
		swap(b, 'x', 0);
		swap(a, 'x', 0);
		return (1);
	}
	return (0);
}

int	rooting(t_int_list **a, t_int_list **b, char *line)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (rotate(a, 'a', 0), 1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rotate(b, 'b', 0), 1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rr(a, b, 0), 1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rrotate(a, 'a', 0), 1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rrotate(b, 'b', 0), 1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rrr(a, b, 0), 1);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (push(a, b, 'a', 0), 1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (push(b, a, 'b', 0), 1);
	else
		return (rooting_next(a, b, line));
	return (0);
}

int	manage_stdin(t_int_list **a, t_int_list **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!rooting(a, b, line))
			return (free(line), 0);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_int_list		*a;
	t_int_list		*b;

	if (argc < 1)
		return (1);
	if (!is_verified_input(argv + 1, argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	a = 0;
	b = 0;
	if (!populate_a(&a, &argv[1], argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	if (!manage_stdin(&a, &b))
	{
		close_project(a);
		close_project(b);
		return (ft_putendl_fd("Error", 2), 1);
	}
	if (is_sorted(a) && list_len(&b, &b->previous) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	close_project(a);
	close_project(b);
	return (0);
}
