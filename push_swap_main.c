/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/09 13:29:09 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_int_list	*a;
	t_int_list	*b;
	int			alloc;

	if (argc < 2)
		return (1);
	alloc = set_args(&argc, &argv);
	if (argc < 1)
		return (free_split(argv, alloc), 1);
	if (!is_verified_input(argv, argc))
		return (free_split(argv, alloc), ft_putendl_fd("Error", 2), 1);
	a = 0;
	b = 0;
	if (!populate_a(&a, argv, argc))
		return (free_split(argv, alloc), ft_putendl_fd("Error", 2), 1);
	if (is_sorted(a))
		return (free_split(argv, alloc), close_project(a), 0);
	if (list_len(&a, &a->previous) == 3)
		return (free_split(argv, alloc), sort_three(&a), close_project(a), 0);
	if (!normalize(&a, argv, argc))
		return (free_split(argv, alloc), ft_putendl_fd("Error", 2), 1);
	set_lis(a);
	sort_brute_force(&b, &a, argc - 1);
	free_split(argv, alloc);
	close_project(a);
	return (0);
}
