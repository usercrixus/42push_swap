/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:40:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 20:35:21 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (buffer < buffer->next)
			return (0);
		buffer = buffer->next;
	}
	return (1);
}

void	swap(t_int_list **stack, char c, int verbose)
{
	t_int_list	*poped;
	t_int_list	*insert;

	poped = pop(stack);
	insert = (*stack)->previous->previous;
	push(&insert, &poped, c, 0);
	if (verbose)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rooting_next(t_int_list *a, t_int_list *b, char *line)
{
	if (ft_strncmp(line, "sb", 3) == 0 && list_len(b, b->previous) > 1)
			swap(b, 'b', 1);
	else if (ft_strncmp(line, "sa", 3) == 0 && list_len(a, a->previous) > 1)
		swap(a, 'a', 1);
	else if (ft_strncmp(line, "ss", 3) == 0)
	{
		if (list_len(b, b->previous) > 1)
			swap(b, 'x', 0);
		if (list_len(a, a->previous) > 1)
			swap(a, 'x', 0);
		ft_putstr_fd('ss\n', 1);
	}
}

void	rooting(t_int_list *a, t_int_list *b, char *line)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		rotate(a, 'a');
	else if (ft_strncmp(line, "rb", 3) == 0)
		rotate(a, 'b');
	else if (ft_strncmp(line, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra", 4) == 0)
		rrotate(a, 'a');
	else if (ft_strncmp(line, "rrb", 4) == 0)
		rr(b, 'b');
	else if (ft_strncmp(line, "rrr", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(line, "pa", 3) == 0)
		push(a, b, 'a', 1);
	else if (ft_strncmp(line, "pb", 3) == 0)
		push(b, a, 'b', 1);
	else
		rooting_next(a, b, line);
}

int	main(int argc, int **argv)
{
	t_int_list		*a;
	t_int_list		*b;
	char			*line;
	int				fd;

	if (argc < 1)
		return (1);
	if (!is_verified_input(argv + 1, argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	a = 0;
	b = 0;
	if (!populate_a(&a, &argv[1], argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	fd = fopen(STDIN_FILENO, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		rooting(a, b, line);
		free(line);
		line = get_next_line(fd);
	}
	if (is_sorted(a))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	return (free(line), close(fd), 0);
}
