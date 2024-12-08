/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:55 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/08 20:10:17 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./42libft/ft_base/libft.h"
# include "./42libft/ft_math/ft_math.h"
# include "./42libft/ft_gnl/ft_get_next_line.h"

typedef struct s_int_list
{
	int					c;
	struct s_int_list	*next;
	struct s_int_list	*previous;
	int					lis;
	struct s_int_list	*lis_previous;
}	t_int_list;

typedef struct s_way
{
	int	branch;
	int	way;
}	t_way;

// main helper
int			populate_a(t_int_list **a, char **argv, int argc);
void		close_project(t_int_list *a);
//verify input
int			is_verified_input(char **s, int size);
//lis
void		set_lis(t_int_list *start);
// linked list
t_int_list	*create_node(int c);
t_int_list	*pop(t_int_list **stack);
void		insert(t_int_list **stack, t_int_list **node);
void		native_push(t_int_list **stack, t_int_list **node);
// brute force
void		sort_brute_force(t_int_list **b, t_int_list **a, int max);
// calculate rotation
t_way		get_best_branch(t_int_list **b, t_int_list **a);
// manage rotation
void		manage_rotate(t_int_list **a, t_int_list **b, t_way best_way);
// helper
t_int_list	*get_maximum(t_int_list *a);
int			list_len(t_int_list **start, t_int_list **end);
int			is_min(t_int_list *a, int x);
int			is_max(t_int_list *a, int x);
int			is_sorted(t_int_list *a);
// normalize
int			normalize(t_int_list **a, char **tab, int size);
// action
void		push(t_int_list **pushed, t_int_list **poped, char c, int verbose);
void		rotate(t_int_list **stack, char c, int verbose);
void		rrotate(t_int_list **stack, char c, int verbose);
void		rr(t_int_list **stacka, t_int_list **stackb, int verbose);
void		rrr(t_int_list **stacka, t_int_list **stackb, int verbose);
void		swap(t_int_list **stack, char c, int verbose);
// sort three
void		sort_three(t_int_list **a);

#endif