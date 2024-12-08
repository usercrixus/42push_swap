/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 20:14:53 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_int_list	*a;
	t_int_list	*b;
	int			is_alloc;

	if (argc < 2)
		return (1);
	is_alloc = set_args(&argc, &argv);
	if (!is_verified_input(argv, argc))
		return (ft_putendl_fd("Error", 2), 1);
	a = 0;
	b = 0;
	if (!populate_a(&a, argv, argc))
		return (ft_putendl_fd("Error", 2), 1);
	if (is_sorted(a))
		return (close_project(a), 0);
	if (list_len(&a, &a->previous) == 3)
		return (sort_three(&a), close_project(a), 0);
	if (!normalize(&a, argv, argc))
		return (ft_putendl_fd("Error", 2), 1);
	set_lis(a);
	sort_brute_force(&b, &a, argc - 1);
	if (is_alloc)
		free_split(argv);
	close_project(a);
	return (0);
}
