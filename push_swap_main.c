/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 15:32:22 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_int_list		*a;
	t_int_list		*b;

	if (argc < 2)
		return (1);
	if (!is_verified_input(argv + 1, argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	a = 0;
	b = 0;
	if (!populate_a(&a, &argv[1], argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	if (!normalize(&a, &argv[1], argc - 1))
		return (ft_putendl_fd("Error", 2), 1);
	set_lis(a);
	sort_brute_force(&b, &a, argc - 2);
	close_project(a);
	return (0);
}
